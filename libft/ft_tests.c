#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// ft_atoi test
void	atoi_test()
{
	printf("<atoi test start>\n");
	char *test_cases[] = {"h1234", "-1234", "+1234", "--1234", "++1234", "adsf12354dfsf", "123dsfsdf"};	
	for (int i = 0; i < 7; i++) 
	{
		int atoi1 = atoi(test_cases[i]);
		int atoi2 = ft_atoi(test_cases[i]);
		printf("Expected: %i\n", atoi1);
		printf("Result: %i\n", atoi2);
		if (atoi1 == atoi2)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	printf("<atoi test end/>\n\n");
}


// ft_bzero test
void	bzero_test()
{
	printf("<bzero test start>\n");

	char buffer1[10] = "abcdefghij";
	char buffer2[10] = "abcdefghij";
	bzero(buffer1, 10);
	ft_bzero(buffer2, 10);
	printf("Fully Zeroed:\n");

	if (memcmp(buffer1, buffer2, 10) == 0)
		printf("PASS\n");
	else
		printf("FAIL\n");

	char buffer3[10] = "abcdefghij";
	char buffer4[10] = "abcdefghij";
	bzero(buffer3, 5);
	ft_bzero(buffer4, 5);
	printf("Partial Zero:\n");

	if (memcmp(buffer3, buffer4, 10) == 0)
		printf("PASS\n");
	else
		printf("FAIL\n");

	printf("<bzero test end>\n\n");
}

// ft_calloc test
void	calloc_test()
{
	printf("<calloc test start>\n");

	int *arr1 = (int *)calloc(5, sizeof(int));
	int *arr2 = (int *)ft_calloc(5, sizeof(int));
	printf("int array calloc\n");
	for (int i = 0; i < 5; i++)
	{
		if (arr1[i] != arr2[i])
			printf("FAIL\n");
	}
	free(arr1);
	free(arr2);
	printf("PASS\n");

	
	char *str = ft_calloc(5, sizeof(char));
	printf("string calloc\n");
	for (int i = 0; i < 5; i++)
	{
		if (str[i] != 0)
			printf("FAIL\n");
	}
	printf("PASS\n");
	free(str);

	printf("<calloc test end/>\n\n");
}

// isalnum test
void	isalnum_test()
{
	printf("<isalnum test start>\n");
	char test_cases[] = {'A', 'z', 'g', '1', '5', ']', '/'};
	for (int i = 0; i < 7; i++)
	{
		printf("Expected: %i\n", isalnum(test_cases[i]));
		printf("Result: %i\n", ft_isalnum(test_cases[i]));
		if (isalnum(test_cases[i]) == ft_isalnum(test_cases[i]))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	printf("<isalnum test end/>\n\n");
}

// isalpha test
void	isalpha_test()
{
	printf("<isalpha test start>\n");
	char test_cases[] = {'A', 'z', 'g', '1', '5', ']', '/'};
	for (int i = 0; i < 7; i++)
	{
		printf("Expected: %i\n", isalpha(test_cases[i]));
		printf("Result: %i\n", ft_isalpha(test_cases[i]));
		if (isalpha(test_cases[i]) == ft_isalpha(test_cases[i]))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	printf("<isalpha test end/>\n\n");
}

// isascii test
void	isascii_test()
{
	printf("<isascii test start>\n");
	char test_cases[] = {'A', 'z', 'g', '1', '5', ']', '/'};
	for (int i = 0; i < 7; i++)
	{
		printf("Expected: %i\n", isascii(test_cases[i]));
		printf("Result: %i\n", ft_isascii(test_cases[i]));
		if (isascii(test_cases[i]) == ft_isascii(test_cases[i]))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	printf("<isascii test end/>\n\n");
}

// isdigit test
void	isdigit_test()
{
	printf("<isdigit test start>\n");
	char test_cases[] = {'A', 'z', 'g', '1', '5', ']', '/'};
	for (int i = 0; i < 7; i++)
	{
		printf("Expected: %i\n", isdigit(test_cases[i]));
		printf("Result: %i\n", ft_isdigit(test_cases[i]));
		if (isdigit(test_cases[i]) == ft_isdigit(test_cases[i]))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	printf("<isdigit test end/>\n\n");
}

// isprintf test
void	isprint_test()
{
	printf("<isprint test start>\n");
	char test_cases[] = {'A', 'z', 'g', '1', '5', ']', '/'};
	for (int i = 0; i < 7; i++)
	{
		printf("Expected: %i\n", isprint(test_cases[i]));
		printf("Result: %i\n", ft_isprint(test_cases[i]));
		if (isprint(test_cases[i]) == ft_isprint(test_cases[i]))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	printf("<isprint test end/>\n\n");
}

// memchr test
void	memchr_test()
{
	printf("<memchr test start>\n");

	char *str = "hello";
	char *ptr1 = memchr(str, 'l', 5);
	char *ptr2 = ft_memchr(str, 'l', 5);
	printf("Expected: %s\n", ptr1);
	printf("Result: %s\n", ptr2);
	if (*ptr1 == *ptr2)
		printf("PASS\n");
	else
		printf("FAIL\n");

	ptr1 = memchr(str, 'a', 5);
	ptr2 = ft_memchr(str, 'a', 5);
	printf("Expected: %s\n", ptr1);
	printf("Result: %s\n", ptr2);

	ptr1 = memchr(str, 'l', 0);
	ptr2 = ft_memchr(str, 'l', 0);
	printf("Expected: %s\n", ptr1);
	printf("Result: %s\n", ptr2);
	
	printf("<memchr test end/>\n");
}



int	main(void)
{
	printf("=== Test starting... ===\n\n");

	atoi_test();
	bzero_test();
	calloc_test();
	isalnum_test();
	isalpha_test();
	isascii_test();
	isdigit_test();
	isprint_test();
	memchr_test();
}
