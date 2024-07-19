#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;
	t_list *current;

	if (begin_list == ((void *)0))
		return (0);
	count = 1;
	current = begin_list;
	while (current->next != ((void *)0))
	{
		count++;
		current = current->next;
	}
	return (count);
}