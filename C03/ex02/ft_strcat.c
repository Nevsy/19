#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char s1[12] = "hello ";
	char s2[5] = "world";
	
	printf("cat: %s\n", strcat(s1, s2));
	fflush(stdout);
	printf("ft: %s\n", ft_strcat2(s1, s2));
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	lenFirst;

	i = 0;
	lenFirst = 0;
	while (dest[lenFirst] != '\0')
		lenFirst++;
	while(src[i] != '\0')
	{
		dest[lenFirst + i] = src[i];
		i++;
	}
	dest[lenFirst + i] = '\0';
	return (dest);
}

