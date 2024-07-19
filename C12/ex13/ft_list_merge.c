#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*prev;
	t_list	*current1;
	t_list	*current2;

	prev = *begin_list1
	current1 = *begin_list1->next;
	while (current1 != 0)
	{
		prev = current1;
		current1 = current1->next;
	}
	current1 = prev;
	current2 = begin_list2;
	while (current2 != 0)
	{
		current1->next = current2;
		current1 = current1->next;
		current2 = current2->next;
	}
}