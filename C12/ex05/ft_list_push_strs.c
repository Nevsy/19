#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*new_el;
	t_list	*begin;
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	begin = 0;
	while (i < size)
	{
		new_el = ft_create_elem(strs[i]);
		if (begin != 0)
			new_el->next = begin;
		begin = new_el;
	}
	return (begin);
}