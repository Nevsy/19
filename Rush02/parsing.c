#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// MARK: BOOL, LINK
typedef	struct number_str_link
{
	long long		number;
	char	str[1024];
} number_str_link;

// typedef enum bool
// {
// 	False,
// 	True
// };

// MARK: PUTSTR, STRLEN
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// MARK: ATOI
int	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign == -1)
	{
		write (1, "Negative number found.", 22);
		return (0);
		// Retourner une liste de 2 chiffres?
		// 1: resultat
		// 2: resultat valide ?
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result);
}

// MARK: GET FILE
int	get_file(char *filepath)
{
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.");
		return (1);
	}
	return (fd);
}

// MARK: COUNT LINES
int	count_non_empty_lines(int file_desc)
{
	char	c;
	char	prev;
	int		count;

	prev = '\n';
	while (read(file_desc, &c, 1))
	{
		if (c == '\n' && prev != '\n')
			count++;
		prev = c;
	}
	return (count);
}

// MARK: INIT
void	init_arr(number_str_link **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i]->number = 0;
		arr[i]->str[0] = '\0';
	}
}

// MARK: PARSE
number_str_link	**parse_file(int file_desc, char *filepath)
{
	char			c;
	number_str_link	**numbers;
	int				non_empty_lines;
	int				current_line;
	int				current_col;

	non_empty_lines = count_non_empty_lines(file_desc);
	numbers = malloc(sizeof(number_str_link *) * non_empty_lines);
	init_arr(numbers, non_empty_lines);
	file_desc = get_file(filepath);
	current_line = 0;
	while (current_line < non_empty_lines)
	{
		while (read(file_desc, &c, 1) && (c >= '0' && c <= '9'))
			numbers[current_line]->number = numbers[current_line]->number * 10 + c - '0';
		while (read(file_desc, &c, 1) && ((c >= 11 && c <= 13) || c == 32 || c == 9)) // PAS DE \n !!
			continue;
		if (c != ':')
			break;
		while (read(file_desc, &c, 1) && ((c >= 11 && c <= 13) || c == 32 || c == 9)) // PAS DE \n !!
			continue;
		numbers[current_line]->str[0] = c;
		current_col = 1;
		while (read(file_desc, &c, 1) && (c != '\n')) // QUE DES PRINTABLES -> != ...
			numbers[current_line]->str[current_col++] = c;
		if (c != '\n')
			break;
		current_line++;
	}
	close(file_desc);
	return (numbers);
}

// MARK: MAIN
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	file_desc;

	if (argc < 2)
	{
		ft_putstr("File name is missing.");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.");
		return (1);
	}
	else
	{
		file_desc = get_file(argv[1]);
		number_str_link **numbers = parse_file(file_desc, argv[1]);
		printf("%s", numbers[22]->str);
	}
	return (0);
}