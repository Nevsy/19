#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
	char s1[12] = "hello ";
	char s2[5] = "world";
	
	printf("cat: %d\n", strlcat(s1, s2, 12));
	fflush(stdout);
	printf("ft: %d\n", ft_strlcat2(s1, s2, 12));
	return (0);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	lenDest;
	int lenSrc;

	i = 0;
	lenDest = 0;
	while (dest[lenDest] != '\0')
		lenDest++;
	while (src[lenSrc] != '\0')
		lenSrc++;
	if (size == 0 || size <= lenDest)
		return (lenSrc + size);
	while(src[i] != '\0' && i < size - lenDest - 1)
	{
		dest[lenDest + i] = src[i];
		i++;
	}
	dest[lenDest + i] = '\0';

	return (lenDest + lenSrc);
}
