#include "push_swap.h"

void	ft_sort_tab(t_push_swap *nbrs)
{
	nbrs->i = 0;
	while (nbrs->i < nbrs->size)
	{
		nbrs->j = nbrs->i + 1;
		while (nbrs->j < nbrs->size)
		{
			if (nbrs->save[nbrs->i] > nbrs->save[nbrs->j])
			{
				nbrs->temp = nbrs->save[nbrs->i];
				nbrs->save[nbrs->i] = nbrs->save[nbrs->j];
				nbrs->save[nbrs->j] = nbrs->temp;
			}
			nbrs->j++;
		}
		nbrs->i++;
	}
	nbrs->start = 0;
	if (ft_lstsize(nbrs->stack_a) <= 100)
		nbrs->end = nbrs->size / 6;
	else
		nbrs->end = nbrs->size / 14;
}

int	ft_is_sorted(t_push_swap *nbrs, t_list *lst)
{
	nbrs->help1 = lst;
	while (nbrs->help1)
	{
		nbrs->help2 = nbrs->help1->next;
		while (nbrs->help2)
		{
			if (nbrs->help1->value > nbrs->help2->value)
				return (0);
			nbrs->help2 = nbrs->help2->next;
		}
		nbrs->help1 = nbrs->help1->next;
	}
	return (1);
}

void	ft_sort_four_elements(t_push_swap *nbrs)
{
	if (ft_is_sorted(nbrs, nbrs->stack_a))
		return ;
	if ((nbrs->stack_a->value > nbrs->stack_a->next->next->value
			&& nbrs->stack_a->value < nbrs->stack_a->next->next->next->value)
		|| (nbrs->stack_a->value < nbrs->stack_a->next->value
			&& nbrs->stack_a->value > nbrs->stack_a->next->next->value
			&& nbrs->stack_a->value > nbrs->stack_a->next->next->next->value))
		ft_rotate_a(nbrs);
	if (nbrs->stack_a->value > nbrs->stack_a->next->value
		&& nbrs->stack_a->value < nbrs->stack_a->next->next->value
		&& nbrs->stack_a->value > nbrs->stack_a->next->next->next->value)
		ft_rotate_a(nbrs);
	ft_push_b(nbrs);
	ft_sort_three_elements(nbrs, nbrs->stack_a, 'a');
	ft_push_a(nbrs);
	if (ft_is_sorted(nbrs, nbrs->stack_a))
		return ;
	if (nbrs->stack_a->value > nbrs->stack_a->next->value
		&& nbrs->stack_a->value < nbrs->stack_a->next->next->value)
		ft_swap_a(nbrs);
	if (nbrs->stack_a->value > nbrs->stack_a->next->next->next->value)
		ft_rotate_a(nbrs);
}

int	ft_find_min_index(t_push_swap *nbrs)
{
	nbrs->i = 0;
	nbrs->j = 0;
	nbrs->nbr = nbrs->stack_a->value;
	nbrs->help1 = nbrs->stack_a;
	while (nbrs->help1)
	{
		if (nbrs->help1->value < nbrs->nbr)
		{
			nbrs->nbr = nbrs->help1->value;
			nbrs->j = nbrs->i;
		}
		nbrs->help1 = nbrs->help1->next;
		nbrs->i++;
	}
	return (nbrs->j);
}

void	ft_sort_five_elements(t_push_swap *nbrs)
{
	if (ft_is_sorted(nbrs, nbrs->stack_a))
		return ;
	while (ft_find_min_index(nbrs) != 0)
	{
		if (nbrs->j <= 2)
			ft_rotate_a(nbrs);
		else
			ft_reverse_rotate_a(nbrs);
	}
	ft_push_b(nbrs);
	ft_sort_four_elements(nbrs);
	ft_push_a(nbrs);
}
