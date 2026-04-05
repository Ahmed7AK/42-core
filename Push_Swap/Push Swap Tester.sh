#!/bin/bash

# Configuration
MAX_MOVES=5500
PUSH_SWAP="./push_swap"

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
echo "  PUSH_SWAP TESTER (Ubuntu)"
echo "  Testing sizes: ${SIZES[*]}"
echo "  Tests per size: 5 (500 for final 500-number test)"
echo "  Max moves allowed: $MAX_MOVES"
echo "========================================================"

# ---------------------------------------------------------------------------
# Dependency checks
# ---------------------------------------------------------------------------
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: $PUSH_SWAP not found. Run 'make' first.${RESET}"
    exit 1
fi

if ! command -v valgrind &> /dev/null; then
    echo -e "${YELLOW}Warning: valgrind not found. Install with: sudo apt install valgrind${RESET}"
    echo -e "${YELLOW}Leak checking will be skipped.${RESET}"
    HAS_VALGRIND=0
else
    HAS_VALGRIND=1
fi

# ---------------------------------------------------------------------------
# Built-in checker — reads moves from stdin, applies them, checks if sorted
# No checker_mac needed
# ---------------------------------------------------------------------------
check_sorted() {
    local arg="$1"
    local moves
    moves=$(./push_swap $arg 2>/dev/null)

    # Feed moves into a pure bash stack simulator
    echo "$moves" | awk -v input="$arg" '
    BEGIN {
        n = split(input, arr, " ")
        for (i = 1; i <= n; i++) a[i] = arr[i]
        top_a = n
        top_b = 0
    }
    function sa() { if (top_a >= 2) { t=a[1]; a[1]=a[2]; a[2]=t } }
    function sb() { if (top_b >= 2) { t=b[1]; b[1]=b[2]; b[2]=t } }
    function ss() { sa(); sb() }
    function pa() {
        if (top_b < 1) return
        top_a++
        for (i=top_a; i>1; i--) a[i]=a[i-1]
        a[1]=b[1]
        for (i=1; i<top_b; i++) b[i]=b[i+1]
        top_b--
    }
    function pb() {
        if (top_a < 1) return
        top_b++
        for (i=top_b; i>1; i--) b[i]=b[i-1]
        b[1]=a[1]
        for (i=1; i<top_a; i++) a[i]=a[i+1]
        top_a--
    }
    function ra()  { if (top_a<1) return; t=a[1]; for(i=1;i<top_a;i++) a[i]=a[i+1]; a[top_a]=t }
    function rb()  { if (top_b<1) return; t=b[1]; for(i=1;i<top_b;i++) b[i]=b[i+1]; b[top_b]=t }
    function rr()  { ra(); rb() }
    function rra() { if (top_a<1) return; t=a[top_a]; for(i=top_a;i>1;i--) a[i]=a[i-1]; a[1]=t }
    function rrb() { if (top_b<1) return; t=b[top_b]; for(i=top_b;i>1;i--) b[i]=b[i-1]; b[1]=t }
    function rrr() { rra(); rrb() }
    {
        op = $1
        if (op == "sa")  sa()
        else if (op == "sb")  sb()
        else if (op == "ss")  ss()
        else if (op == "pa")  pa()
        else if (op == "pb")  pb()
        else if (op == "ra")  ra()
        else if (op == "rb")  rb()
        else if (op == "rr")  rr()
        else if (op == "rra") rra()
        else if (op == "rrb") rrb()
        else if (op == "rrr") rrr()
    }
    END {
        if (top_b != 0) { print "KO"; exit }
        for (i = 1; i < top_a; i++) {
            if (a[i]+0 > a[i+1]+0) { print "KO"; exit }
        }
        print "OK"
    }
    '
}

# ---------------------------------------------------------------------------
# Helper: generate $1 unique random integers in range [$2, $3]
# Handles negatives correctly by generating range then shifting
# ---------------------------------------------------------------------------
rand_unique() {
    local count=$1
    local lo=$2
    local hi=$3

    LC_ALL=C tr -dc '0-9\n' < /dev/urandom 2>/dev/null \
        | fold -w 9 \
        | awk -v lo="$lo" -v hi="$hi" -v n="$count" '
            {
                range = hi - lo + 1
                val = (($1 + 0) % range) + lo
                if (!(val in seen)) {
                    seen[val] = 1
                    print val
                    if (++found == n) exit
                }
            }
        '
}

# ---------------------------------------------------------------------------
# Helper: check for memory leaks using valgrind
# ---------------------------------------------------------------------------
check_leaks() {
    local arg="$1"
    if [ $HAS_VALGRIND -eq 0 ]; then
        return 0
    fi
    valgrind --leak-check=full --errors-for-leak-kinds=all \
        --error-exitcode=42 ./push_swap $arg > /dev/null 2>&1
    return $?
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

    check_leaks "$arg"
    if [ $? -eq 42 ]; then LEAK_FOUND=1; else LEAK_FOUND=0; fi

    CHECKER_OUT=$(check_sorted "$arg")
    MOVES=$(./push_swap $arg 2>/dev/null | wc -l | tr -d ' ')

    if [ "$MOVES" -gt "$max_moves" ]; then EXCEEDED_MOVES=1; else EXCEEDED_MOVES=0; fi

    if [ $HAS_VALGRIND -eq 1 ]; then
        [ $LEAK_FOUND -eq 0 ] && LK="${GREEN}OK${RESET}" || LK="${RED}KO${RESET}"
        LEAK_LABEL="leaks=$LK "
    else
        LEAK_LABEL=""
    fi
    [ "$CHECKER_OUT" == "OK" ] && CH="${GREEN}OK${RESET}" || CH="${RED}KO${RESET}"
    [ $EXCEEDED_MOVES -eq 0 ]  && MV="${GREEN}$MOVES${RESET}" || MV="${RED}$MOVES (Too High!)${RESET}"

    echo -e "  $label: ${LEAK_LABEL}checker=$CH | moves=$MV"

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

        check_leaks "$ARG"
        if [ $? -eq 42 ]; then LEAK_FOUND=1; else LEAK_FOUND=0; fi

        CHECKER_OUT=$(check_sorted "$ARG")
        MOVES=$(./push_swap $ARG 2>/dev/null | wc -l | tr -d ' ')
        SIZE_TOTAL_MOVES=$((SIZE_TOTAL_MOVES + MOVES))

        if [ "$MOVES" -gt "$MAX_MOVES" ]; then EXCEEDED_MOVES=1; else EXCEEDED_MOVES=0; fi

        if [ $HAS_VALGRIND -eq 1 ]; then
            [ $LEAK_FOUND -eq 0 ] && LK="${GREEN}OK${RESET}" || LK="${RED}KO${RESET}"
            LEAK_LABEL="leaks=$LK "
        else
            LEAK_LABEL=""
        fi
        [ "$CHECKER_OUT" == "OK" ] && CH="${GREEN}OK${RESET}" || CH="${RED}KO${RESET}"
        [ $EXCEEDED_MOVES -eq 0 ]  && MV="${GREEN}$MOVES${RESET}" || MV="${RED}$MOVES (Too High!)${RESET}"

        echo -e "  Test $i: ${LEAK_LABEL}checker=$CH | moves=$MV"

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
