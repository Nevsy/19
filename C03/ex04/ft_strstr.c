#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	//char haystack[] = "0123456789";
	char haystack[] = "hello world";
	//char needle[] = "1";
	char needle[] = "wo";
	
	printf("ft: %s\n", ft_strstr(haystack, needle));
	printf("strstr: %s", strstr(haystack, needle));
	return 0;
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	indexPotentialFind;
	
	i = 0;
	j = 0;
	indexPotentialFind = -1;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			indexPotentialFind = i;
			while (str[i] && to_find[j] && str[i++] == to_find[j++])
			if (to_find[j] == '\0')
				return (str + indexPotentialFind);
		}
		i++;
	}
	return (NULL);
}
