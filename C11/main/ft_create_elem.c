#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*el;

	el = malloc(sizeof(t_list));
	el->data = data;
	el->next = NULL;
	return (el);
}