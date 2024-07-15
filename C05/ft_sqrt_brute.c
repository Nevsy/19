int	ft_sqrt(int nb)
{
	int	i;
	int	cap;

	i = 0;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	cap = (nb - 1) / 2 + 1;
	while (nb > i * i && i < cap)
		i++;
	if (nb == i * i)
		return (i);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(4330 * 4330));
	printf("%d\n", ft_sqrt(4330 * 4330 + 1));
	return (0);
}