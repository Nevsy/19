int	ft_sqrt(int nb)
{
	int		i;
	int		cap;
	long	nb_cpy;

	nb_cpy = nb;
	i = 0;
	if (nb_cpy <= 0)
		return (0);
	else if (nb_cpy == 1)
		return (1);
	cap = (nb_cpy - 1) / 2 + 1;
	while (nb_cpy > i * i && i < cap)
		i++;
	if (nb_cpy == i * i)
		return (i);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_sqrt(43630 * 43630));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(4330 * 4330));
	printf("%d\n", ft_sqrt(4330 * 4330 + 1));
	return (0);
}