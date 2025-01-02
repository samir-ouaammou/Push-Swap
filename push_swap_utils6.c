#include "push_swap.h"

void	ft_rotate_a(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_a);
	if (nbrs->size < 2)
		return ;
	nbrs->help1 = nbrs->stack_a;
	nbrs->stack_a = nbrs->stack_a->next;
	nbrs->help1->next = NULL;
	ft_lstadd_back(&nbrs->stack_a, nbrs->help1);
}

void	ft_rotate_b(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_b);
	if (nbrs->size < 2)
		return ;
	nbrs->help1 = nbrs->stack_b;
	nbrs->stack_b = nbrs->stack_b->next;
	nbrs->help1->next = NULL;
	ft_lstadd_back(&nbrs->stack_b, nbrs->help1);
}

void	ft_rotate_rr(t_push_swap *nbrs)
{
	ft_rotate_a(nbrs);
	ft_rotate_b(nbrs);
}

void	ft_reverse_rotate_a(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_a);
	if (nbrs->size < 2)
		return ;
	nbrs->help1 = nbrs->stack_a;
	while (nbrs->help1->next)
		nbrs->help1 = nbrs->help1->next;
	nbrs->help2 = nbrs->stack_a;
	while (nbrs->help2->next != nbrs->help1)
		nbrs->help2 = nbrs->help2->next;
	nbrs->help2->next = NULL;
	nbrs->help1->next = nbrs->stack_a;
	nbrs->stack_a = nbrs->help1;
}

void	ft_reverse_rotate_b(t_push_swap *nbrs)
{
	nbrs->size = ft_lstsize(nbrs->stack_b);
	if (nbrs->size < 2)
		return ;
	nbrs->help1 = nbrs->stack_b;
	while (nbrs->help1->next)
		nbrs->help1 = nbrs->help1->next;
	nbrs->help2 = nbrs->stack_b;
	while (nbrs->help2->next != nbrs->help1)
		nbrs->help2 = nbrs->help2->next;
	nbrs->help2->next = NULL;
	nbrs->help1->next = nbrs->stack_b;
	nbrs->stack_b = nbrs->help1;
}
