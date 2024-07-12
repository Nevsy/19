#include <stdlib.h>
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_first;

	i = 0;
	len_first = 0;
	while (dest[len_first])
		len_first++;
	while(src[i])
	{
		dest[len_first + i] = src[i];
		i++;
	}
	dest[len_first + i] = '\0';
	return (dest);
}

void	cat_this_shit(int size, char **strs, char *sep, char *string)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(string, strs[i]);
		if (++i != size - 1)
			ft_strcat(string, sep);
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		i;
	int		j;
	int		strs_size;

	strs_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			strs_size++;
		i++;
	}
	j = 0;
	while (sep[j] && size != 0)
		j++;
	if(!(string = malloc(sizeof(char) * (strs_size + (size - 1) * j + 1))))
		return (NULL);
	cat_this_shit(size, strs, sep, string);
	string[strs_size] = '\0';
	return (string);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);
	else
	{
		printf("%s", ft_strjoin(3, argv, argv[2]));
	}
	return (0);
}