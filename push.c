
#include "push_swap.h"

void	push(t_list **lst_a, t_list **lst_b, char *str)
{
	t_list	*sentinel_a;
	t_list	*sentinel_b;
	t_list	*head_a;
	t_list	*head_b;
	t_list	*next_a;

	sentinel_a = *lst_a;
	sentinel_b = *lst_b;
	head_a = sentinel_a->next;
	head_b = sentinel_b->next;
	next_a = head_a->next;

	sentinel_a->next = next_a;
	next_a->prev = sentinel_a;

	sentinel_b->next = head_a;
	head_a->prev = sentinel_b;
	head_a->next = head_b;
	head_b->prev = head_a;

	if (str)
		ft_printf("%s\n", str);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b, "pa");
}

void	push_b(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a, "pb");
}
