#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

#include <stdio.h>
char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**deconstructed;

	if (!(deconstructed = malloc(sizeof(char) * ft_strlen(str) + 100))) // il faudra moins que le strlen mais vsy flemme
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (find_char(str[i], charset))
			continue;
		else
		{
			while (str[i] && !find_char(str[i], charset))
			{
				printf("test\n");
				fflush(stdout);
				deconstructed[j][k++] = str[i++];
			}
			deconstructed[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	return (deconstructed);
}

int	main(int argc, char *argv[])
{
	char **deconstructed;

	if (argc != 3)
		return (1);
	deconstructed = ft_split(argv[1], argv[2]);
	if (deconstructed == NULL)
		return (1);
	for (int i = 0; i < 2; i++)
	{
		printf("split %d, %s\n", i, deconstructed[i]);
		fflush(stdout);
	}
	return (0);
}