#include <stdio.h>
#include <unistd.h>

int	is_solution_valid(int solution[10], int index_added)
{
	int	i;
	int	diag_pos_index;
	int	diag_neg_index;

	i = 0;
	diag_pos_index = index_added + solution[index_added];
	diag_neg_index = index_added - solution[index_added];
	while (i < index_added)
	{
		if (solution[i] == solution[index_added]
			|| i - solution[i] == diag_neg_index
			|| i + solution[i] == diag_pos_index)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_solution(int solution[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = solution[i] + '0';
		write(1, &c, 1);
		c = '\n';
		if (i == 9)
			write(1, &c, 1);
		i++;
	}
}

int	backtrack(int solution[10], int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (index == 10)
	{
		print_solution(solution);
		return (1);
	}
	while (i < 10)
	{
		solution[index] = i;
		if (is_solution_valid(solution, index))
			count += backtrack(solution, index + 1);
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	solution[10];
	int	count;

	count = backtrack(solution, 0);
	return (count);
}

int	main(void)
{
	printf("amount of sols: %d", ft_ten_queens_puzzle());
	return (0);
}