#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char s1[] = "hello world";
	char s2[] = "this is a longer string";

	printf("ft1: %d\n", ft_strlen(s1));
	printf("ft2: %d", ft_strlen(s2));
	//printf("len1: %d", strlen(s1));
	//printf("len1: %d", strlen(s2));
	return (0);
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}
