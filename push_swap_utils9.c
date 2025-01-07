/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils9.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:10:28 by souaammo          #+#    #+#             */
/*   Updated: 2025/01/07 10:10:30 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_init(t_push_swap *nbrs)
{
	nbrs->i = 0;
	nbrs->j = 0;
	nbrs->nbr = 0;
	nbrs->size = 0;
	nbrs->temp = 0;
	nbrs->start = 0;
	nbrs->end = 0;
	nbrs->save = 0;
	nbrs->instructions = 0;
	nbrs->stack_a = NULL;
	nbrs->stack_b = NULL;
	nbrs->help1 = NULL;
	nbrs->help2 = NULL;
	nbrs->split = NULL;
	nbrs->line = NULL;
}

int	ft_is_small_number(t_push_swap *nbrs, int size)
{
	nbrs->i = 0;
	while (nbrs->i <= size)
	{
		if (nbrs->stack_a->value <= nbrs->save[nbrs->i])
			return (1);
		nbrs->i++;
	}
	return (0);
}

int	ft_is_big_number(t_push_swap *nbrs)
{
	nbrs->i = 0;
	nbrs->j = 0;
	nbrs->nbr = nbrs->stack_b->value;
	nbrs->help1 = nbrs->stack_b;
	while (nbrs->help1)
	{
		if (nbrs->nbr < nbrs->help1->value)
		{
			nbrs->nbr = nbrs->help1->value;
			nbrs->j = nbrs->i;
		}
		nbrs->i++;
		nbrs->help1 = nbrs->help1->next;
	}
	return (nbrs->j);
}

void	ft_push_max_to_a(t_push_swap *nbrs)
{
	while (nbrs->stack_b)
	{
		nbrs->size = ft_lstsize(nbrs->stack_b);
		nbrs->temp = nbrs->size / 2;
		if (ft_is_big_number(nbrs) <= nbrs->temp)
		{
			while (nbrs->j > 0)
			{
				ft_rotate_b(nbrs);
				nbrs->j--;
			}
		}
		else
		{
			while (nbrs->j < nbrs->size)
			{
				ft_reverse_rotate_b(nbrs);
				nbrs->j++;
			}
		}
		ft_push_a(nbrs);
	}
}

void	ft_sort_large_stack(t_push_swap *nbrs)
{
	ft_sort_tab(nbrs);
	while (nbrs->stack_a)
	{
		if (ft_is_small_number(nbrs, nbrs->start))
		{
			ft_push_b(nbrs);
			ft_rotate_b(nbrs);
			nbrs->start++;
			nbrs->end++;
		}
		else if (ft_is_small_number(nbrs, nbrs->end))
		{
			ft_push_b(nbrs);
			if (nbrs->stack_b && nbrs->stack_b->next)
			{
				if (nbrs->stack_b->value < nbrs->stack_b->next->value)
					ft_swap_b(nbrs);
			}
			nbrs->end++;
			nbrs->start++;
		}
		else
			ft_rotate_a(nbrs);
	}
	ft_push_max_to_a(nbrs);
}
