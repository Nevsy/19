int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (nb < 0)
		return (0);
	while (nb != 0)
	{
		result *= nb;
		nb--;
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_factorial(9));
	return 0;
}