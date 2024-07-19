#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*prev;

	current = *begin_list;
	prev = 0;
	while (current != 0)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			prev->next = current->next;
			current = prev->next;
			(*free_fct)(current->data);
			free(current);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}