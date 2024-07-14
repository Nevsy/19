#include "ft_strs_to_tab.c"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

// No negative!
void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

#include <stdio.h>
void	show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	//while (i < 5)
	while (par[i].str != 0)
	{
		printf("index: %d\n", i);
		fflush(stdout);
		printf("str: %s\n", par[i].str);
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	char *strs[] = {"hello", "world", "this", "is"};
	struct s_stock_str *temp = ft_strs_to_tab(4, strs);
	printf("show_tab\n");
	show_tab(temp);
	free(temp);
	return (0);
}