#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_el;
	t_list	*current;
	t_list	*prev;

	new_el = ft_create_elem(data);
	current = *begin_list;
	prev = 0;
	while (current != 0 && (*cmp)(new_el->data, current->data) > 0)
	{
		prev = current;
		current = current->next;
	}
	if (current == 0)
	{
		prev->next = new_el;
	}
	else if ((*cmp)(new_el->data, current->data) <= 0)
	{
		if (prev == 0)
		{
			new_el->next = current;
			*begin_list = new_el;
			return ;
		}
		new_el->next = current;
		prev->next = new_el;
	}
}




















/*#include <stdlib.h>

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
		if (fast != 0)
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

t_list	*ft_create_elem(void *data)
{
	t_list	*el;

	el = malloc(sizeof(t_list));
	el->data = data;
	el->next = 0;
	return (el);
}

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

int	ft_strcmp(void *s1, void *s2)
{
	int		i;
	char	*s1_cpy;
	char	*s2_cpy;

	s1_cpy = (char *)s1;
	s2_cpy = (char *)s2;
	i = 0;
	while (s1_cpy[i] && s2_cpy[i] && s1_cpy[i] == s2_cpy[i])
		i++;
	return (s1_cpy[i] - s2_cpy[i]);
}

#include <unistd.h>
void	ft_putstr(void *str)
{
	char	*str_cpy;

	str_cpy = (char *)str;
	while (*str_cpy)
		write (1, str_cpy++, 1);
	write(1, " ", 1);
}

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

int	main(void)
{
	t_list *head = 0;

	ft_list_push_front(&head, "b");
	ft_list_push_front(&head, "r");
	ft_list_push_front(&head, "c");
	ft_list_push_front(&head, "t");
	ft_list_push_front(&head, "u");
	ft_list_push_front(&head, "d");
	ft_list_push_front(&head, "p");
	ft_list_push_front(&head, "i");
	ft_list_push_front(&head, "m");
	ft_list_push_front(&head, "l");
	ft_list_push_front(&head, "n");
	ft_list_push_front(&head, "q");
	ft_list_push_front(&head, "e");
	ft_list_push_front(&head, "y");
	ft_list_push_front(&head, "j");
	ft_list_push_front(&head, "xd");
	ft_list_push_front(&head, "w");
	ft_list_push_front(&head, "v");
	ft_list_push_front(&head, "k");
	ft_list_push_front(&head, "o");
	ft_list_push_front(&head, "h");
	ft_list_push_front(&head, "h");
	ft_list_push_front(&head, "g");
	ft_list_push_front(&head, "s");
	// no a, f or z

	ft_list_foreach(head, &ft_putstr);
	ft_list_sort(&head, &ft_strcmp);
	write(1, "\n", 1);
	ft_list_foreach(head, &ft_putstr);
	write(1, "\n", 1);
	ft_sorted_list_insert(&head, "a", &ft_strcmp);
	ft_sorted_list_insert(&head, "z", &ft_strcmp);
	ft_sorted_list_insert(&head, "f", &ft_strcmp);
	ft_list_foreach(head, &ft_putstr);
	return (0);
}*/