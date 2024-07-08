#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		nb2 *= -1;
		ft_putchar('-');
	}
	if (nb2 < 10)
	{
		ft_putchar(nb2 + '0');
	}
	else{
		ft_putnbr(nb2 / 10);
		ft_putnbr(nb2 % 10);
	}
}

int main(void)
{
	ft_putnbr(-212);
	return (0);
}