int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (nb < 0 || power < 0)
		return (0);
	while (power != 0)
	{
		result *= nb;
		power--;
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_power(2, 10));
	return 0;
}