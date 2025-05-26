/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:10:07 by souaammo          #+#    #+#             */
/*   Updated: 2025/01/07 10:10:09 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two_elements(t_push_swap *nbrs, t_list *lst, char c)
{
	if (ft_is_sorted(nbrs, lst))
		return ;
	if (c == 'a')
		ft_swap_a(nbrs);
	if (c == 'b')
		ft_swap_b(nbrs);
}

void	ft_s_stack(t_push_swap *nbrs, char c)
{
	if (c == 'a')
	{
		if (nbrs->stack_a->value > nbrs->stack_a->next->value
			&& nbrs->stack_a->value > nbrs->stack_a->next->next->value
			&& nbrs->stack_a->next->value > nbrs->stack_a->next->next->value)
		{
			ft_swap_a(nbrs);
			ft_reverse_rotate_a(nbrs);
		}
	}
	if (c == 'b')
	{
		if (nbrs->stack_b->value > nbrs->stack_b->next->value
			&& nbrs->stack_b->value > nbrs->stack_b->next->next->value
			&& nbrs->stack_b->next->value > nbrs->stack_b->next->next->value)
		{
			ft_swap_b(nbrs);
			ft_reverse_rotate_b(nbrs);
		}
	}
}

void	ft_stack_a(t_push_swap *nbrs)
{
	if (nbrs->stack_a->value > nbrs->stack_a->next->value
		&& nbrs->stack_a->value < nbrs->stack_a->next->next->value
		&& nbrs->stack_a->next->value < nbrs->stack_a->next->next->value)
		ft_swap_a(nbrs);
	if (nbrs->stack_a->value < nbrs->stack_a->next->value
		&& nbrs->stack_a->next->value > nbrs->stack_a->next->next->value
		&& nbrs->stack_a->value > nbrs->stack_a->next->next->value)
		ft_reverse_rotate_a(nbrs);
	if (nbrs->stack_a->value < nbrs->stack_a->next->value
		&& nbrs->stack_a->next->value > nbrs->stack_a->next->next->value
		&& nbrs->stack_a->value < nbrs->stack_a->next->next->value)
	{
		ft_reverse_rotate_a(nbrs);
		ft_swap_a(nbrs);
	}
	if (nbrs->stack_a->value > nbrs->stack_a->next->value
		&& nbrs->stack_a->value > nbrs->stack_a->next->next->value
		&& nbrs->stack_a->next->value < nbrs->stack_a->next->next->value)
		ft_rotate_a(nbrs);
	ft_s_stack(nbrs, 'a');
}

void	ft_stack_b(t_push_swap *nbrs)
{
	if (nbrs->stack_b->value > nbrs->stack_b->next->value
		&& nbrs->stack_b->value < nbrs->stack_b->next->next->value
		&& nbrs->stack_b->next->value < nbrs->stack_b->next->next->value)
		ft_swap_b(nbrs);
	if (nbrs->stack_b->value < nbrs->stack_b->next->value
		&& nbrs->stack_b->next->value > nbrs->stack_b->next->next->value
		&& nbrs->stack_b->value > nbrs->stack_b->next->next->value)
		ft_reverse_rotate_b(nbrs);
	if (nbrs->stack_b->value < nbrs->stack_b->next->value
		&& nbrs->stack_b->next->value > nbrs->stack_b->next->next->value
		&& nbrs->stack_b->value < nbrs->stack_b->next->next->value)
	{
		ft_reverse_rotate_b(nbrs);
		ft_swap_b(nbrs);
	}
	if (nbrs->stack_b->value > nbrs->stack_b->next->value
		&& nbrs->stack_b->value > nbrs->stack_b->next->next->value
		&& nbrs->stack_b->next->value < nbrs->stack_b->next->next->value)
		ft_rotate_b(nbrs);
	ft_s_stack(nbrs, 'b');
}

void	ft_sort_three_elements(t_push_swap *nbrs, t_list *lst, char c)
{
	if (ft_is_sorted(nbrs, lst))
		return ;
	if (c == 'a')
		ft_stack_a(nbrs);
	if (c == 'b')
		ft_stack_b(nbrs);
}
