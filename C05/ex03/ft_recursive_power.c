int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (nb < 0 || power < 0)
		return (0);
	if (power != 0)
		result = nb * ft_recursive_power(nb, power - 1);
	else
		return (result);
	return (result);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_power(2, 10));
	return 0;
}