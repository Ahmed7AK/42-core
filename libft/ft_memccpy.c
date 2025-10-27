#include <string.h>
#include <stdio.h>

void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	unsigned char	*dstp;
	unsigned char	*srcp;
	unsigned char	ch;
	size_t	i;
	
	dstp = (unsigned char *)dst;
	srcp = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ch != srcp[i])
		{
			dstp[i] = srcp[i];
		}
		else
		{
			dstp[i] = srcp[i];
			return (dst);
		}
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *src = "hello";
	char dst[5];
	int c = '0';
	char *result = memccpy(dst, src, c, 4);
	printf("dst: %s\n", dst);
	printf("result: %s\n", result);
}
