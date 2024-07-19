#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*next_to_do;

	if (begin_list == 0)
		return ;
	next_to_do = begin_list;
	while (next_to_do != 0)
	{
		(*f)(next_to_do->data);
		next_to_do = next_to_do->next;
	}
}