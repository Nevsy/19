#include <stdlib.h>

int	ft_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (!(ptr = malloc(sizeof(int) * (max - min))))
		return (0);
	*range = ptr;
	if (!ptr)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < max - min)
	{
		ptr[i] = min + i;
		i++;
	}
	return (max - min);
}

#include <stdio.h>
int main(void)
{
	int *range;
	int size = ft_range(&range, -5, 10);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", range[i]);
	}
	printf("\n");
	printf("size: %d", size);
	free(range);
	return (0);
}