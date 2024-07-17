#include "ft_list.h"
#include <stdlib.h>

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*node;
	int		count;

	if (begin_list == 0)
		return ;
	count = 0;
	node = begin_list;
	while (node->next != 0 && count < nbr)
	{
		node = node->next;
		count++;
	}
	if (count == nbr)
		return (node);
	return (0);
}