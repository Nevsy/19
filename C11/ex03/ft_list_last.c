#include "ft_list.h"

#include "ft_list.h"

t_list	*ft_list_size(t_list *begin_list)
{
	t_list *current;

	if (begin_list == ((void *)0))
		return (0);
	current = begin_list;
	while (current->next != ((void *)0))
		current = current->next;

	return (current);
}