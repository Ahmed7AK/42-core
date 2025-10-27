
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	unsigned char	ch;

	ch = c;
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
	{
		return (1);
	}
	return (0);
}
