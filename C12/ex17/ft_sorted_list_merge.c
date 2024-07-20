#include "ft_list.h"

t_list	*ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list *result;
	t_list *begin_list1_cpy;

	result = 0;
	begin_list1_cpy = *begin_list1;
	if (begin_list1_cpy == 0)
		return (begin_list2);
	else if (begin_list2 == 0)
		return (begin_list1_cpy);
	if ((*cmp)(begin_list1_cpy->data, begin_list2->data) <= 0)
	{
		result = begin_list1_cpy;
		result->next = sorted_merge(&begin_list1_cpy->next, begin_list2, cmp);
	}
	else
	{
		result = begin_list2;
		result->next = sorted_merge(begin_list1, begin_list2->next, cmp);
	}
	return (result);
}