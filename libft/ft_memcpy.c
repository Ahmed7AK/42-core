
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char 	*dst_ptr;
	unsigned char	*src_ptr;
	size_t		i;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	dst_ptr[i] = '\0';
	return (dst);
}
