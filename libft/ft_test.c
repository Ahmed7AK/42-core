#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

int tests_run = 0;
int tests_passed = 0;

void print_result(int pass, const char *test_name)
{
    tests_run++;
    if (pass) tests_passed++;
    printf("  %s%s%s: %s\n", pass ? GREEN : RED, pass ? "✓" : "✗", RESET, test_name);
}

void test_ft_strlen(void)
{
    printf("\n%s=== Testing ft_strlen ===%s\n", BLUE, RESET);
    print_result(ft_strlen("Hello") == strlen("Hello"), "Normal string");
    print_result(ft_strlen("") == strlen(""), "Empty string");
    print_result(ft_strlen("A") == strlen("A"), "Single character");
    print_result(ft_strlen("This is a longer test string") == strlen("This is a longer test string"), "Long string");
}

void test_ft_isalpha(void)
{
    printf("\n%s=== Testing ft_isalpha ===%s\n", BLUE, RESET);
    print_result(!!ft_isalpha('a') == !!isalpha('a'), "Lowercase letter");
    print_result(!!ft_isalpha('Z') == !!isalpha('Z'), "Uppercase letter");
    print_result(!!ft_isalpha('5') == !!isalpha('5'), "Digit");
    print_result(!!ft_isalpha(' ') == !!isalpha(' '), "Space");
    print_result(!!ft_isalpha('\n') == !!isalpha('\n'), "Newline");
}

void test_ft_isdigit(void)
{
    printf("\n%s=== Testing ft_isdigit ===%s\n", BLUE, RESET);
    print_result(!!ft_isdigit('0') == !!isdigit('0'), "Zero");
    print_result(!!ft_isdigit('9') == !!isdigit('9'), "Nine");
    print_result(!!ft_isdigit('5') == !!isdigit('5'), "Mid digit");
    print_result(!!ft_isdigit('a') == !!isdigit('a'), "Letter");
    print_result(!!ft_isdigit(' ') == !!isdigit(' '), "Space");
}

void test_ft_isalnum(void)
{
    printf("\n%s=== Testing ft_isalnum ===%s\n", BLUE, RESET);
    print_result(!!ft_isalnum('a') == !!isalnum('a'), "Lowercase letter");
    print_result(!!ft_isalnum('Z') == !!isalnum('Z'), "Uppercase letter");
    print_result(!!ft_isalnum('5') == !!isalnum('5'), "Digit");
    print_result(!!ft_isalnum('!') == !!isalnum('!'), "Special char");
    print_result(!!ft_isalnum(' ') == !!isalnum(' '), "Space");
}

void test_ft_isascii(void)
{
    printf("\n%s=== Testing ft_isascii ===%s\n", BLUE, RESET);
    print_result(!!ft_isascii(0) == !!isascii(0), "Zero");
    print_result(!!ft_isascii(127) == !!isascii(127), "Max ASCII");
    print_result(!!ft_isascii(128) == !!isascii(128), "Beyond ASCII");
    print_result(!!ft_isascii('A') == !!isascii('A'), "Normal char");
    print_result(!!ft_isascii(-1) == !!isascii(-1), "Negative");
}

void test_ft_isprint(void)
{
    printf("\n%s=== Testing ft_isprint ===%s\n", BLUE, RESET);
    print_result(!!ft_isprint('a') == !!isprint('a'), "Letter");
    print_result(!!ft_isprint(' ') == !!isprint(' '), "Space");
    print_result(!!ft_isprint('\n') == !!isprint('\n'), "Newline");
    print_result(!!ft_isprint(31) == !!isprint(31), "Control char");
    print_result(!!ft_isprint(127) == !!isprint(127), "DEL char");
}

void test_ft_toupper(void)
{
    printf("\n%s=== Testing ft_toupper ===%s\n", BLUE, RESET);
    print_result(ft_toupper('a') == toupper('a'), "Lowercase a");
    print_result(ft_toupper('z') == toupper('z'), "Lowercase z");
    print_result(ft_toupper('A') == toupper('A'), "Already uppercase");
    print_result(ft_toupper('5') == toupper('5'), "Digit");
    print_result(ft_toupper('!') == toupper('!'), "Special char");
}

void test_ft_tolower(void)
{
    printf("\n%s=== Testing ft_tolower ===%s\n", BLUE, RESET);
    print_result(ft_tolower('A') == tolower('A'), "Uppercase A");
    print_result(ft_tolower('Z') == tolower('Z'), "Uppercase Z");
    print_result(ft_tolower('a') == tolower('a'), "Already lowercase");
    print_result(ft_tolower('5') == tolower('5'), "Digit");
    print_result(ft_tolower('!') == tolower('!'), "Special char");
}

void test_ft_atoi(void)
{
    printf("\n%s=== Testing ft_atoi ===%s\n", BLUE, RESET);
    print_result(ft_atoi("123") == atoi("123"), "Positive number");
    print_result(ft_atoi("-456") == atoi("-456"), "Negative number");
    print_result(ft_atoi("0") == atoi("0"), "Zero");
    print_result(ft_atoi("   42") == atoi("   42"), "Leading spaces");
    print_result(ft_atoi("+789") == atoi("+789"), "Plus sign");
    print_result(ft_atoi("  -123abc") == atoi("  -123abc"), "Trailing chars");
}

void test_ft_strchr(void)
{
    printf("\n%s=== Testing ft_strchr ===%s\n", BLUE, RESET);
    char *test = "Hello World";
    print_result(ft_strchr(test, 'H') == strchr(test, 'H'), "First char");
    print_result(ft_strchr(test, 'o') == strchr(test, 'o'), "Middle char");
    print_result(ft_strchr(test, 'd') == strchr(test, 'd'), "Last char");
    print_result(ft_strchr(test, '\0') == strchr(test, '\0'), "Null terminator");
    print_result(ft_strchr(test, 'x') == strchr(test, 'x'), "Not found");
}

void test_ft_strrchr(void)
{
    printf("\n%s=== Testing ft_strrchr ===%s\n", BLUE, RESET);
    char *test = "Hello World";
    print_result(ft_strrchr(test, 'o') == strrchr(test, 'o'), "Duplicate char");
    print_result(ft_strrchr(test, 'H') == strrchr(test, 'H'), "First char");
    print_result(ft_strrchr(test, 'd') == strrchr(test, 'd'), "Last char");
    print_result(ft_strrchr(test, '\0') == strrchr(test, '\0'), "Null terminator");
    print_result(ft_strrchr(test, 'x') == strrchr(test, 'x'), "Not found");
}

void test_ft_strncmp(void)
{
    printf("\n%s=== Testing ft_strncmp ===%s\n", BLUE, RESET);
    int orig, yours;
    
    orig = strncmp("Hello", "Hello", 5);
    yours = ft_strncmp("Hello", "Hello", 5);
    print_result(orig == yours, "Equal strings");
    
    orig = strncmp("Hello", "World", 5);
    yours = ft_strncmp("Hello", "World", 5);
    print_result((orig < 0 && yours < 0) || (orig > 0 && yours > 0) || (orig == 0 && yours == 0), "Different strings");
    
    orig = strncmp("Hello", "Help", 3);
    yours = ft_strncmp("Hello", "Help", 3);
    print_result(orig == yours, "Partial match");
    
    orig = strncmp("Hello", "Hello", 10);
    yours = ft_strncmp("Hello", "Hello", 10);
    print_result(orig == yours, "n > length");
    
    orig = strncmp("", "", 1);
    yours = ft_strncmp("", "", 1);
    print_result(orig == yours, "Empty strings");
}

void test_ft_strnstr(void)
{
    printf("\n%s=== Testing ft_strnstr ===%s\n", BLUE, RESET);
    print_result(ft_strnstr("Hello World", "World", 11) == strnstr("Hello World", "World", 11), "Found");
    print_result(ft_strnstr("Hello World", "World", 8) == strnstr("Hello World", "World", 8), "Not in range");
    print_result(ft_strnstr("Hello World", "", 11) == strnstr("Hello World", "", 11), "Empty needle");
    print_result(ft_strnstr("Hello", "Hello", 5) == strnstr("Hello", "Hello", 5), "Exact match");
    print_result(ft_strnstr("Hello", "xyz", 5) == strnstr("Hello", "xyz", 5), "Not found");
}

void test_ft_memset(void)
{
    printf("\n%s=== Testing ft_memset ===%s\n", BLUE, RESET);
    char buf1[10] = {0};  // Initialize to zero
    char buf2[10] = {0};
    memset(buf1, 'A', 10);
    ft_memset(buf2, 'A', 10);
    print_result(memcmp(buf1, buf2, 10) == 0, "Set all bytes");
    
    memset(buf1, 0, 10);
    ft_memset(buf2, 0, 10);
    print_result(memcmp(buf1, buf2, 10) == 0, "Set to zero");
    

    memset(buf1, 255, 5);
    ft_memset(buf2, 255, 5);
    print_result(memcmp(buf1, buf2, 10) == 0, "Partial set");
}

void test_ft_bzero(void)
{
    printf("\n%s=== Testing ft_bzero ===%s\n", BLUE, RESET);
    char buf1[10] = "AAAAAAAAAA";
    char buf2[10] = "AAAAAAAAAA";
    bzero(buf1, 10);
    ft_bzero(buf2, 10);
    print_result(memcmp(buf1, buf2, 10) == 0, "Zero all bytes");
    
    strcpy(buf1, "Test");
    strcpy(buf2, "Test");
    bzero(buf1, 2);
    ft_bzero(buf2, 2);
    print_result(memcmp(buf1, buf2, 10) == 0, "Partial zero");
}

void test_ft_memcpy(void)
{
    printf("\n%s=== Testing ft_memcpy ===%s\n", BLUE, RESET);
    char src[] = "Hello World";
    char dst1[20], dst2[20];
    
    memcpy(dst1, src, 11);
    ft_memcpy(dst2, src, 11);
    print_result(memcmp(dst1, dst2, 11) == 0, "Copy string");
    
    int nums[] = {1, 2, 3, 4, 5};
    int dst3[5], dst4[5];
    memcpy(dst3, nums, sizeof(nums));
    ft_memcpy(dst4, nums, sizeof(nums));
    print_result(memcmp(dst3, dst4, sizeof(nums)) == 0, "Copy integers");
}

void test_ft_memmove(void)
{
    printf("\n%s=== Testing ft_memmove ===%s\n", BLUE, RESET);
    char buf1[20] = "Hello World";
    char buf2[20] = "Hello World";
    
    memmove(buf1 + 2, buf1, 5);
    ft_memmove(buf2 + 2, buf2, 5);
    print_result(strcmp(buf1, buf2) == 0, "Overlapping forward");
    
    strcpy(buf1, "Hello World");
    strcpy(buf2, "Hello World");
    memmove(buf1, buf1 + 2, 5);
    ft_memmove(buf2, buf2 + 2, 5);
    print_result(strcmp(buf1, buf2) == 0, "Overlapping backward");
}

void test_ft_memchr(void)
{
    printf("\n%s=== Testing ft_memchr ===%s\n", BLUE, RESET);
    char test[] = "Hello World";
    print_result(ft_memchr(test, 'W', 11) == memchr(test, 'W', 11), "Found");
    print_result(ft_memchr(test, 'W', 5) == memchr(test, 'W', 5), "Not in range");
    print_result(ft_memchr(test, '\0', 12) == memchr(test, '\0', 12), "Null char");
    print_result(ft_memchr(test, 'x', 11) == memchr(test, 'x', 11), "Not found");
}

void test_ft_memcmp(void)
{
    printf("\n%s=== Testing ft_memcmp ===%s\n", BLUE, RESET);
    int orig, yours;
    
    orig = memcmp("Hello", "Hello", 5);
    yours = ft_memcmp("Hello", "Hello", 5);
    print_result(orig == yours, "Equal");
    
    orig = memcmp("Hello", "World", 5);
    yours = ft_memcmp("Hello", "World", 5);
    print_result((orig < 0 && yours < 0) || (orig > 0 && yours > 0) || (orig == 0 && yours == 0), "Less than");
    
    orig = memcmp("World", "Hello", 5);
    yours = ft_memcmp("World", "Hello", 5);
    print_result((orig < 0 && yours < 0) || (orig > 0 && yours > 0) || (orig == 0 && yours == 0), "Greater than");
    
    orig = memcmp("Hello", "Help", 3);
    yours = ft_memcmp("Hello", "Help", 3);
    print_result(orig == yours, "Partial equal");
}

void test_ft_strlcpy(void)
{
    printf("\n%s=== Testing ft_strlcpy ===%s\n", BLUE, RESET);
    char dst1[10], dst2[10];
    size_t r1, r2;
    
    r1 = strlcpy(dst1, "Hello", 10);
    r2 = ft_strlcpy(dst2, "Hello", 10);
    print_result(r1 == r2 && strcmp(dst1, dst2) == 0, "Normal copy");
    
    r1 = strlcpy(dst1, "Hello World", 6);
    r2 = ft_strlcpy(dst2, "Hello World", 6);
    print_result(r1 == r2 && strcmp(dst1, dst2) == 0, "Truncated copy");
    
    r1 = strlcpy(dst1, "Test", 0);
    r2 = ft_strlcpy(dst2, "Test", 0);
    print_result(r1 == r2, "Size zero");
}

void test_ft_strlcat(void)
{
    printf("\n%s=== Testing ft_strlcat ===%s\n", BLUE, RESET);
    char dst1[20], dst2[20];
    size_t r1, r2;
    
    strcpy(dst1, "Hello ");
    strcpy(dst2, "Hello ");
    r1 = strlcat(dst1, "World", 20);
    r2 = ft_strlcat(dst2, "World", 20);
    print_result(r1 == r2 && strcmp(dst1, dst2) == 0, "Normal concat");
    
    strcpy(dst1, "Hello ");
    strcpy(dst2, "Hello ");
    r1 = strlcat(dst1, "World", 10);
    r2 = ft_strlcat(dst2, "World", 10);
    print_result(r1 == r2 && strcmp(dst1, dst2) == 0, "Limited space");
}

void test_ft_strdup(void)
{
    printf("\n%s=== Testing ft_strdup ===%s\n", BLUE, RESET);
    char *s1 = strdup("Hello");
    char *s2 = ft_strdup("Hello");
    print_result(strcmp(s1, s2) == 0, "Normal string");
    free(s1);
    free(s2);
    
    s1 = strdup("");
    s2 = ft_strdup("");
    print_result(strcmp(s1, s2) == 0, "Empty string");
    free(s1);
    free(s2);
}

void test_ft_calloc(void)
{
    printf("\n%s=== Testing ft_calloc ===%s\n", BLUE, RESET);
    int *arr1 = (int *)calloc(5, sizeof(int));
    int *arr2 = (int *)ft_calloc(5, sizeof(int));
    int all_zero = 1;
    for (int i = 0; i < 5; i++) {
        if (arr2[i] != 0) all_zero = 0;
    }
    print_result(all_zero, "Memory zeroed");
    free(arr1);
    free(arr2);
    
    char *str = (char *)ft_calloc(10, sizeof(char));
    all_zero = 1;
    for (int i = 0; i < 10; i++) {
        if (str[i] != 0) all_zero = 0;
    }
    print_result(all_zero, "Char array zeroed");
    free(str);
}

int main(void)
{
    printf("\n%s╔════════════════════════════════════╗%s\n", BLUE, RESET);
    printf("%s║   LIBFT COMPREHENSIVE TEST SUITE  ║%s\n", BLUE, RESET);
    printf("%s╚════════════════════════════════════╝%s\n", BLUE, RESET);
    
    test_ft_strlen();
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_atoi();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_strnstr();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_strdup();
    test_ft_calloc();
    
    printf("\n%s╔════════════════════════════════════╗%s\n", BLUE, RESET);
    printf("%s║           FINAL RESULTS            ║%s\n", BLUE, RESET);
    printf("%s╚════════════════════════════════════╝%s\n", BLUE, RESET);
    printf("\nTests passed: %s%d/%d%s\n", 
        tests_passed == tests_run ? GREEN : RED,
        tests_passed, tests_run, RESET);
    
    if (tests_passed == tests_run)
        printf("%s🎉 All tests passed! 🎉%s\n\n", GREEN, RESET);
    else
        printf("%s❌ Some tests failed%s\n\n", RED, RESET);
    
    return (tests_passed == tests_run) ? 0 : 1;
}