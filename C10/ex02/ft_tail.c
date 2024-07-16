#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.", 1);
		return (1);
	}
	return (fd);
}

void	read_shit(char *filename, int file_desc, int c_flag)
{
	char	c;
	int		i;
	int		n_s;

	(void)c_flag;
	i = 0;
	n_s = 0;
	while (read(file_desc, &c, 1))
		if (c == '\n')
			n_s++;
	close(file_desc);
	file_desc = open(filename, O_RDONLY);
	if (n_s - 11 < 0)
		while (read(file_desc, &c, 1))
			write(1, &c, 1);
	else
	{
		while (read(file_desc, &c, 1) && i < n_s - 9)
			if (c == '\n')
				i++;
		while (read(file_desc, &c, 1))
			write(1, &c, 1);
	}
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	file_desc;

	if (argc < 2)
	{
		write(2, "File name is missing.", 21);
		return (1);
	}
	else if (argc == 3)
	{
		if (!(argv[2][0] == '-' && argv[2][1] == 'c'))
			return (1);
		file_desc = get_file(argv[1]);
		read_shit(argv[1], file_desc, 1);
	}
	else if (argc > 3)
	{
		write(2, "Too many arguments.", 19);
		return (1);
	}
	else
	{
		file_desc = get_file(argv[1]);
		read_shit(argv[1], file_desc, 0);
	}
	return (0);
}