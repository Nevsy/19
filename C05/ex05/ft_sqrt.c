float	ft_abs(float x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

float compute_p1(float x, float result, float interval)
{
	float	diff;
	int		c;

	c = -1;
	diff = result * result - x;
	while (ft_abs(diff) > 0.000001)
	{
		c++;
		interval = interval / 2;
		if (diff > 0)
			result -= interval;
		else
			result += interval;
		diff = result * result - x;
	}
	return (result);	
}

/*
* CONVERT OUT TO INT
*/
float	ft_sqrt(int nb)
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

#include <stdio.h>
int main (void)
{
	printf("%f", ft_sqrt(2));
	return 0;
}

// 0 1 -> 
// 1 2 -> 
// 2 + -> 