#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	c;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		while (argv[i][j] != '\0')
		{
			c = argv[j][j];
			write(1, &c, 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}