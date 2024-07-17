#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next_to_free;

	if (begin_list == 0)
		return ;
	next_to_free = begin_list;
	while (next_to_free->next != 0)
	{
		next_to_free = next_to_free->next;
		free_fct(next_to_free->data);
		free(next_to_free);
	}
	free_fct(next_to_free->data);
	free(next_to_free);
}