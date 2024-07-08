int ft_fiboNext(int prev1, int prev2, int depth, int index)
{
	if (depth == index)
		return (prev1 + prev2);
	return ft_fiboNext(prev2, prev1 + prev2, depth + 1, index);
}

int	ft_fibonacci(int index)
{
	int	result;
	
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	result = ft_fiboNext(0, 1, 2, index);
	return (result);
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_fibonacci(11));
	return (0);
}

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
// 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11,  12