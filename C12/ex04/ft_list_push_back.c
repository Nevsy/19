#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_el;
	t_list	*current;

	new_el = ft_create_elem(data);
	if (*begin_list == ((void *)0))
	{
		*begin_list = new_el;
		return ;
	}
	current =  *begin_list;
	while (current->next != ((void *)0))
		current = current->next;
	current->next = new_el;
}