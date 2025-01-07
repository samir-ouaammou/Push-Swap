/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:08:18 by souaammo          #+#    #+#             */
/*   Updated: 2025/01/07 10:10:45 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_push_swap *nbrs)
{
	free(nbrs->save);
	nbrs->save = NULL;
	ft_lstclear(nbrs, &nbrs->stack_a);
	ft_lstclear(nbrs, &nbrs->stack_b);
	exit(0);
}

int	main(int ac, char **av)
{
	t_push_swap	nbrs;

	if (ac < 2)
		exit(0);
	ft_push_swap_init(&nbrs);
	ft_check_args(ac, av, &nbrs);
	if (ft_is_sorted(&nbrs, nbrs.stack_a))
	{
		ft_free_all(&nbrs);
		return (0);
	}
	if (nbrs.size <= 1)
		ft_free_all(&nbrs);
	if (nbrs.size == 2)
		ft_sort_two_elements(&nbrs, nbrs.stack_a, 'a');
	if (nbrs.size == 3)
		ft_sort_three_elements(&nbrs, nbrs.stack_a, 'a');
	if (nbrs.size == 4)
		ft_sort_four_elements(&nbrs);
	if (nbrs.size == 5)
		ft_sort_five_elements(&nbrs);
	if (nbrs.size >= 6)
		ft_sort_large_stack(&nbrs);
	ft_free_all(&nbrs);
	return (0);
}
