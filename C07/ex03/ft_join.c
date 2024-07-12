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

#include <stdio.h>
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		i;
	int		j;
	int		strs_size;

	// Get size: go through all charac
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			strs_size++;
		i++;
	}
	printf("strs size: %d", strs_size);
	j = 0;
	while (sep[j])
		j++;
	string = malloc(sizeof(char) * strs_size + (size - 1) * j + 1);
	while (i < size)
	{
		ft_strcat(string, strs[i]);
		if (++i != size)
			ft_strcat(string, sep);
	}
	return (string);
}

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