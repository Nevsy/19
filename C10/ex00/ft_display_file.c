#include <unistd.h>
#include <fcntl.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.");
		return (1);
	}
	return (fd);
}

void	read_shit(int file_desc)
{
	char	c;

	while (read(file_desc, &c, 1))
	{
		write(1, &c, 1);
	}
	close(file_desc);
}

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
		read_shit(file_desc);
	}
	return (0);
}