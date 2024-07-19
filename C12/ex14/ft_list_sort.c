#include "ft_list.h"

t_list	*sorted_merge(t_list *a, t_list *b, int (*cmp)())
{
	t_list *result;

	result = 0;
	if (a == 0)
		return (b);
	else if (b == 0)
		return (a);
	if ((*cmp)(a->data, b->data) <= 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next, cmp);
	}
	return (result);
}

void	front_back_split(t_list *source, t_list **front_ref, t_list **back_ref)
{
	t_list *fast;
	t_list *slow;

	slow = source;
	fast = source->next;
	while (fast != 0)
	{
		fast = fast->next;
		if (fast->next != 0)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = 0;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *begin_list;
	if ((head == 0) || (head->next == 0))
		return ;
	front_back_split(head, &a, &b);
	ft_list_sort(&a, cmp);
	ft_list_sort(&b, cmp);
	*begin_list = sorted_merge(a, b, cmp);
}

int	main(void)
{
	t_list *res = 0;
	t_list *a = 0;

	
}