#include <unistd.h>

void	print_solution(int solutions[10][3])
{
	int	i;
	char c;

	while (i < 10)
	{
		c = solutions[i][0] + '0';
		write(1, &c, 1);
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}

int solution_is_valid(int solutions[10][3], int row, int column, int posDiagIndex, int negDiagIndex)
{
	int	j;

	j = 0;
	while (j < column)
	{
		if (solutions[j][0] == row || solutions[j][1] == posDiagIndex || solutions[j][2] == negDiagIndex)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

int	backtrack(int solutions[10][3], int currentColIndex)
{
	int	i;
	int	counter;

	i = 0;
	if (currentColIndex == 9)
	{
		print_solution(solutions);
		return (1);
	}
	while (i + currentColIndex < 10)
	{
		if (solution_is_valid(solutions, i, currentColIndex, currentColIndex + i, currentColIndex - i) == 1)
			continue;
		solutions[currentColIndex + i][0] = i;
		solutions[currentColIndex + i][1] = currentColIndex + i;
		solutions[currentColIndex + i][2] = currentColIndex - i;
		counter += backtrack(solutions, currentColIndex + 1);
		i++;
	}
	return (counter);
}

int	ft_ten_queens_puzzle(void)
{
	int	solutions[10][3]; // [[chosen: row, +diag, -diag], [], ..., []]
	int	i;
	int	counter;

	i = 0;
	while (i < 10)
	{
		solutions[0][i, i, -i];
		counter += backtrack(solutions, 1);
		i++;
	}
	return (counter);
}

#include <stdio.h>
int	main(void)
{
	printf("\nresults: %d\n", ft_ten_queens_puzzle());
}