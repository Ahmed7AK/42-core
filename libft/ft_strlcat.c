#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0')
		i++;
	
	j = 0; 
	while (j < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i + 1);
}

int main(void)
{
	char *src = "ahmed";
	char dst[7];
	dst[0] = 'h';
	dst[1] = 'i';
	int result = (int)ft_strlcat(dst, src, 5);
	printf("%s\n%i\n", dst, result);
}
