#!/bin/bash

# Configuration
MAX_MOVES=5500      # Maximum allowed moves
CHECKER="./checker_mac" # Path to your checker binary

# Colors
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
CYAN="\033[36m"
MAGENTA="\033[35m"
RESET="\033[0m"

# Sizes to test — parallel arrays: size and how many random tests per size
SIZES=(5 10 15 20 25 30 35 40 45 50 75 100 150 200 250 300 350 400 450 500)
COUNTS=(5  5  5  5  5  5  5  5  5  5  5   5   5   5   5   5   5   5   5  500)

echo "========================================================"
echo "  PUSH_SWAP MULTI-SIZE TESTER                          "
echo "  Testing sizes: ${SIZES[*]}"
echo "  Tests per size: 5 (500 for final 500-number test)"
echo "  Max moves allowed: $MAX_MOVES"
echo "========================================================"

# Check if checker exists
if [ ! -f "$CHECKER" ]; then
    echo -e "${RED}Error: $CHECKER not found.${RESET}"
    exit 1
fi
chmod +x "$CHECKER"

# ---------------------------------------------------------------------------
# Helper: generate $1 unique random integers in range [$2, $3]
# ---------------------------------------------------------------------------
rand_unique() {
    local count=$1
    local lo=$2
    local hi=$3

    LC_ALL=C tr -dc '0-9\n' < /dev/urandom 2>/dev/null \
        | fold -w 8 \
        | awk -v lo="$lo" -v hi="$hi" -v n="$count" '
            BEGIN { srand() }
            {
                val = (($1 + 0) % (hi - lo + 1)) + lo
                if (!(val in seen)) {
                    seen[val] = 1
                    print val
                    if (++found == n) exit
                }
            }
        '
}

# ---------------------------------------------------------------------------
# Helper: run one test case and print result
# Usage: run_test "label" "args" [max_moves]
# Returns 0 on pass, 1 on fail
# ---------------------------------------------------------------------------
run_test() {
    local label="$1"
    local arg="$2"
    local max_moves="${3:-$MAX_MOVES}"

    valgrind --leak-check=full --errors-for-leak-kinds=all --error-exitcode=42 \
        ./push_swap $arg > /dev/null 2>&1
    if [ $? -eq 42 ]; then LEAK_FOUND=1; else LEAK_FOUND=0; fi

    CHECKER_OUT=$(./push_swap $arg | $CHECKER $arg 2>&1)
    MOVES=$(./push_swap $arg | wc -l | tr -d ' ')

    if [ "$MOVES" -gt "$max_moves" ]; then EXCEEDED_MOVES=1; else EXCEEDED_MOVES=0; fi

    [ $LEAK_FOUND -eq 0 ]      && VG="${GREEN}OK${RESET}" || VG="${RED}KO${RESET}"
    [ "$CHECKER_OUT" == "OK" ] && CH="${GREEN}OK${RESET}" || CH="${RED}KO${RESET}"
    [ $EXCEEDED_MOVES -eq 0 ]  && MV="${GREEN}$MOVES${RESET}" || MV="${RED}$MOVES (Too High!)${RESET}"

    echo -e "  $label: Valgrind=$VG checker=$CH | moves=$MV"

    if [ $LEAK_FOUND -eq 1 ] || [ "$CHECKER_OUT" != "OK" ] || [ $EXCEEDED_MOVES -eq 1 ]; then
        REASON=""
        [ $EXCEEDED_MOVES -eq 1 ]  && REASON+=" exceeded_moves($MOVES)"
        [ $LEAK_FOUND -eq 1 ]      && REASON+=" memory_leak"
        [ "$CHECKER_OUT" != "OK" ] && REASON+=" not_sorted"
        echo -e "    ${YELLOW}↳ Failed:$REASON${RESET}"
        return 1
    fi
    return 0
}

# ---------------------------------------------------------------------------
# Counters
# ---------------------------------------------------------------------------
TOTAL_PASS=0
TOTAL_FAIL=0

# ---------------------------------------------------------------------------
# WORST CASE SCENARIOS
# ---------------------------------------------------------------------------
echo ""
echo -e "${MAGENTA}========================================================"
echo -e "  WORST CASE SCENARIOS"
echo -e "========================================================${RESET}"

WC_PASS=0
WC_FAIL=0

# Reverse sorted — worst case for push phase sliding window
for SIZE in 10 50 100 500; do
    ARG=$(seq $SIZE -1 1 | tr '\n' ' ')
    run_test "Reverse sorted ($SIZE)" "$ARG"
    if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi
done

# Already sorted — must produce 0 moves
for SIZE in 10 50 100 500; do
    ARG=$(seq 1 $SIZE | tr '\n' ' ')
    run_test "Already sorted ($SIZE)" "$ARG" 0
    if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi
done

# Alternating high/low — maximizes rotation cost in pull phase
for SIZE in 10 50 100 500; do
    ARG=""
    lo=1
    hi=$SIZE
    while [ $lo -lt $hi ]; do
        ARG="$ARG $hi $lo"
        lo=$((lo+1))
        hi=$((hi-1))
    done
    [ $lo -eq $hi ] && ARG="$ARG $lo"
    run_test "Alternating high/low ($SIZE)" "$ARG"
    if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi
done

# All negative numbers
for SIZE in 10 50 100 500; do
    ARG=$(rand_unique $SIZE -10000 -1 | tr '\n' ' ')
    run_test "All negative ($SIZE)" "$ARG"
    if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi
done

# Interleaved sorted halves — hard for chunk detection
for SIZE in 50 500; do
    HALF=$((SIZE/2))
    ARG=""
    for ((i=1; i<=HALF; i++)); do
        ARG="$ARG $i $((i+HALF))"
    done
    run_test "Interleaved sorted halves ($SIZE)" "$ARG"
    if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi
done

# INT boundary stress
run_test "INT boundaries" "2147483647 -2147483648 0 1 -1"
if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi

# Single element — must produce 0 moves
run_test "Single element" "42" 0
if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi

# Two elements
run_test "Two elements unsorted" "2 1" 1
if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi

run_test "Two elements sorted" "1 2" 0
if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi

# All three-element permutations — must sort in at most 3 moves each
for PERM in "3 2 1" "3 1 2" "2 3 1" "2 1 3" "1 3 2"; do
    run_test "Three elements ($PERM)" "$PERM" 3
    if [ $? -eq 0 ]; then WC_PASS=$((WC_PASS+1)); else WC_FAIL=$((WC_FAIL+1)); fi
done

TOTAL_PASS=$((TOTAL_PASS + WC_PASS))
TOTAL_FAIL=$((TOTAL_FAIL + WC_FAIL))
echo -e "  ${MAGENTA}Worst cases: ${GREEN}$WC_PASS passed${RESET} / ${RED}$WC_FAIL failed${RESET}"

# ---------------------------------------------------------------------------
# RANDOM TESTS BY SIZE
# ---------------------------------------------------------------------------
for idx in "${!SIZES[@]}"; do
    STACK_SIZE="${SIZES[$idx]}"
    TEST_COUNT="${COUNTS[$idx]}"

    echo ""
    echo -e "${CYAN}========================================================"
    echo -e "  SIZE: $STACK_SIZE numbers ($TEST_COUNT tests)"
    echo -e "========================================================${RESET}"

    SIZE_PASS=0
    SIZE_FAIL=0
    SIZE_TOTAL_MOVES=0

    for ((i=1; i<=TEST_COUNT; i++)); do
        ARG=$(rand_unique $STACK_SIZE -10000 10000 | tr '\n' ' ')

        valgrind --leak-check=full --errors-for-leak-kinds=all --error-exitcode=42 \
            ./push_swap $ARG > /dev/null 2>&1
        if [ $? -eq 42 ]; then LEAK_FOUND=1; else LEAK_FOUND=0; fi

        CHECKER_OUT=$(./push_swap $ARG | $CHECKER $ARG 2>&1)
        MOVES=$(./push_swap $ARG | wc -l | tr -d ' ')
        SIZE_TOTAL_MOVES=$((SIZE_TOTAL_MOVES + MOVES))

        if [ "$MOVES" -gt "$MAX_MOVES" ]; then EXCEEDED_MOVES=1; else EXCEEDED_MOVES=0; fi

        [ $LEAK_FOUND -eq 0 ]      && VG="${GREEN}OK${RESET}" || VG="${RED}KO${RESET}"
        [ "$CHECKER_OUT" == "OK" ] && CH="${GREEN}OK${RESET}" || CH="${RED}KO${RESET}"
        [ $EXCEEDED_MOVES -eq 0 ]  && MV="${GREEN}$MOVES${RESET}" || MV="${RED}$MOVES (Too High!)${RESET}"

        echo -e "  Test $i: Valgrind=$VG checker=$CH | moves=$MV"

        if [ $LEAK_FOUND -eq 1 ] || [ "$CHECKER_OUT" != "OK" ] || [ $EXCEEDED_MOVES -eq 1 ]; then
            SIZE_FAIL=$((SIZE_FAIL + 1))
            REASON=""
            [ $EXCEEDED_MOVES -eq 1 ]  && REASON+=" exceeded_moves($MOVES)"
            [ $LEAK_FOUND -eq 1 ]      && REASON+=" memory_leak"
            [ "$CHECKER_OUT" != "OK" ] && REASON+=" not_sorted"
            echo -e "    ${YELLOW}↳ Failed:$REASON${RESET}"
        else
            SIZE_PASS=$((SIZE_PASS + 1))
        fi
    done

    SIZE_AVG=$((SIZE_TOTAL_MOVES / TEST_COUNT))
    TOTAL_PASS=$((TOTAL_PASS + SIZE_PASS))
    TOTAL_FAIL=$((TOTAL_FAIL + SIZE_FAIL))

    echo -e "  ${CYAN}Result: ${GREEN}$SIZE_PASS passed${RESET} / ${RED}$SIZE_FAIL failed${RESET} | avg moves: $SIZE_AVG${RESET}"
done

# ---------------------------------------------------------------------------
# Final summary
# ---------------------------------------------------------------------------
TOTAL_TESTS=$((TOTAL_PASS + TOTAL_FAIL))
echo ""
echo "========================================================"
echo "  FINAL SUMMARY"
echo "========================================================"
echo -e "  Total: ${GREEN}$TOTAL_PASS passed${RESET} / ${RED}$TOTAL_FAIL failed${RESET} out of $TOTAL_TESTS"

if [ $TOTAL_FAIL -eq 0 ]; then
    echo -e "  ${GREEN}ALL TESTS PASSED!${RESET}"
    echo "========================================================"
    exit 0
else
    echo -e "  ${RED}$TOTAL_FAIL TEST(S) FAILED${RESET}"
    echo "========================================================"
    exit 1
fi