#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*begin_list_cpy;
	t_list	*new_el;

	new_el = ft_create_elem(data);
	begin_list_cpy = *begin_list;
	if (!begin_list_cpy)
	{
		*begin_list = new_el; 
		return ;
	}
	new_el->next = begin_list_cpy;
	*begin_list = new_el;
}
