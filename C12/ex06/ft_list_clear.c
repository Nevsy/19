#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next_to_free;

	next_to_free = begin_list;
	while (next_to_free != 0)
	{
		free_fct(next_to_free->data);
		free(next_to_free);
		next_to_free = next_to_free->next;
	}
}