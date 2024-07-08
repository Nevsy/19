#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	c;
	int		i;

	while (argv[0][i] != '\0')
	{
		c = argv[0][i];
		write(1, &c, 1);
		i++;
	}
	return (0);
}