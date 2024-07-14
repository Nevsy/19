#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (!dup)
		return (0);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab;
	char				*str;

	i = 0;
	tab = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!tab)
		return (0);
	while (i < ac)
	{
		str = av[i];
		tab[i].size = ft_strlen(str);
		tab[i].str = str;
		tab[i].copy = ft_strdup(str);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}