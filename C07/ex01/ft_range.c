#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
		return (NULL);
	ptr = malloc(sizeof(int) * (max - min));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}

#include <stdio.h>
int main(void)
{
	int *range = ft_range(-5, 10);
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", range[i]);
	}
	free(range);
	return (0);
}