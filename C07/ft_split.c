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

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;

	while (str[i])
	{
		while (str[i] && find_char(str[i], charset))
			i++;
		while (str[i] && !find_char(str[i], charset))
			i++;
		j++;
	}
	return (j);
}

char	*take_word(char	*str, char *charset, int index)
{
	int		i;
	int		j;
	char	*word;

	i = index;
	while (str[i] && !find_char(str[i++], charset))
		j++;
	if(!(word = malloc(j * sizeof(char) + 1)))
		return (NULL);
	i = index;
	j = 0;
	while (str[i] && !find_char(str[i], charset))
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

#include <stdio.h>
char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**deconstructed;

	deconstructed = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!deconstructed) // il faudra moins que le strlen mais vsy flemme
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && find_char(str[i], charset))
			i++;
		k = 0;
		while (k <= ft_strlen(take_word(str, charset, i)))
		{
			deconstructed[j][k] = take_word(str, charset, i)[k];
			k++;
		}
		printf("%s", deconstructed[j]);
		fflush(stdout);
		j++;
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