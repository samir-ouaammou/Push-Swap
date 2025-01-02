#include "push_swap.h"

void	ft_swap_a(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_a);
	if (nbrs->size < 2)
		return ;
	nbrs->temp = nbrs->stack_a->value;
	nbrs->stack_a->value = nbrs->stack_a->next->value;
	nbrs->stack_a->next->value = nbrs->temp;
}

void	ft_swap_b(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_b);
	if (nbrs->size < 2)
		return ;
	nbrs->temp = nbrs->stack_b->value;
	nbrs->stack_b->value = nbrs->stack_b->next->value;
	nbrs->stack_b->next->value = nbrs->temp;
}

void	ft_s_swap(t_push_swap *nbrs)
{
	ft_swap_a(nbrs);
	ft_swap_b(nbrs);
}

void	ft_push_a(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_b);
	if (nbrs->size < 1)
		return ;
	nbrs->help1 = nbrs->stack_b;
	nbrs->stack_b = nbrs->stack_b->next;
	nbrs->help1->next = NULL;
	ft_lstadd_front(&nbrs->stack_a, nbrs->help1);
}

void	ft_push_b(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_a);
	if (nbrs->size < 1)
		return ;
	nbrs->help1 = nbrs->stack_a;
	nbrs->stack_a = nbrs->stack_a->next;
	nbrs->help1->next = NULL;
	ft_lstadd_front(&nbrs->stack_b, nbrs->help1);
}
