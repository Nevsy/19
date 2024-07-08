#include <string.h>
#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
	char s1[12] = "hello ";
	char s2[5] = "world";
	
	printf("cat: %d\n", strncat(s1, s2, 5));
	fflush(stdout);
	printf("ft: %d\n", ft_strncat2(s1, s2, 5));
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	lenDest;

	i = 0;
	lenDest = 0;
	while (dest[lenDest] != '\0')
		lenDest++;
	while(src[i] != '\0' && i < nb)
	{
		dest[lenDest + i] = src[i];
		i++;
	}
	dest[lenDest + i] = '\0';
	return (dest);
}

