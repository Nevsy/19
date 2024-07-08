#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char str[] = "  ---++----||||1b1212";
	printf("%d", ft_atoi_base(str, "0|"));
	return (0);
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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		result;
	int		baseLen;
	char	*charPtr;
	int		diffBaseStr;

	baseLen = checkValidity(base);
	if (baseLen == -1)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		charPtr = ft_strstr(base, (char[]){str[i], '\0'});
		if (charPtr == NULL)
			break;
		diffBaseStr = charPtr - base;
		result = result * baseLen + diffBaseStr;
		i++;
	}
	return (result * sign);
}