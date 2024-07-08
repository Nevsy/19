float compute_p1(float x, float result, float interval)
{
	float	diff;
	float	absDiff;

	diff = result * result - x;
	if (diff >= 0)
		absDiff = diff;
	else
		absDiff = -diff;
	while (absDiff > 1e-6)
	{
		interval = interval / 2;
		if (diff > 0)
			result -= interval;
		else
			result += interval;
		diff = result * result - x;
		if (diff >= 0)
			absDiff = diff;
		else
			absDiff = -diff;
	}
	return (result);	
}

int	ft_sqrt(int nb)
{
	float result;
	float interval;
	float x;

	x = nb;
	if (nb <= 0)
		result = 0;
	else if (nb == 1)
		result = 1;
	else if (nb > 1)
	{
		result = (x - 1) / 2 + 1;
		interval = (x - 1) / 2;
		result = compute_p1(x, result, interval);
	}
	return (result);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

#include <stdio.h>
int	main(void)
{
	printf("is %d a prime? %d\n", 10, ft_is_prime(10));
	printf("is %d a prime? %d\n", 31, ft_is_prime(31));
	printf("is %d  a prime? %d", 1, ft_is_prime(1));
	return (0);
}