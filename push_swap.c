#include "push_swap.h"

void	ft_push_swap_init(t_push_swap *nbrs)
{
	nbrs->i = 0;
	nbrs->j = 0;
	nbrs->nbr = 0;
	nbrs->size = 0;
	nbrs->temp = 0;
	nbrs->save = 0;
	nbrs->stack_a = NULL;
	nbrs->stack_b = NULL;
	nbrs->help1 = NULL;
	nbrs->help2 = NULL;
	nbrs->split = NULL;
}

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
	// printf("\n");
	// // while (nbrs.stack_a)
	// // {
	// // 	printf("%d\n", nbrs.stack_a->value);
	// // 	nbrs.stack_a = nbrs.stack_a->next;
	// // }
	ft_free_all(&nbrs);
	return (0);
}
// ft_swap_a(&nbrs);
// ft_swap_b(&nbrs);
// ft_s_swap(&nbrs);
// ft_push_a(&nbrs);
// ft_push_b(&nbrs);
// ft_rotate_a(&nbrs);
// ft_rotate_b(&nbrs);
// ft_rotate_rr(&nbrs);
// ft_reverse_rotate_a(&nbrs);
// ft_reverse_rotate_b(&nbrs);
// ft_reverse_rotate_both(&nbrs);