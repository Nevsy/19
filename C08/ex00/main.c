#include "ft.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) >= 5)
		ft_putstr(argv[1]);
	else if (argc == 2)
		ft_putchar(ft_strcmp(argv[1], "42") + '0');
	ft_putchar('\n');
	return (0);
}