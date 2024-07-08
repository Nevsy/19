#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	indexPotentialFind;
	
	i = 0;
	j = 0;
	indexPotentialFind = -1;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			indexPotentialFind = i;
			while (str[i] && to_find[j] && str[i++] == to_find[j++])
			if (to_find[j] == '\0')
				return (str + indexPotentialFind);
		}
		i++;
	}
	return (NULL);
}

int	checkValidity(char *base)
{
	int baseLen;

	baseLen = 0;
	while (base[baseLen] != '\0'){
		if (base[baseLen] == '+' || base[baseLen] == '-' || ft_strstr(base, &base[baseLen]) == NULL)
			return -1;
		baseLen++;
	}
	if (baseLen <= 1)
		return -1;
	return baseLen;
}

void	ft_putnbr(int nb, char *base)
{
	long nb2;
	int baseLen;

	baseLen = checkValidity(base);
	if (baseLen == -1)
		return ;
	nb2 = nb;
	if (nb2 < 0)
	{
		nb2 *= -1;
		ft_putchar('-');
	}
	if (nb2 < baseLen)
	{
		ft_putchar(base[nb2]);
	}
	else {
		ft_putnbr(nb2 / baseLen, base);
		ft_putnbr(nb2 % baseLen, base);
	}
}

int main(void)
{
	ft_putnbr(1023, "01");
	return (0);
}