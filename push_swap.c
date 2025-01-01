#include "push_swap.h"

void	ft_push_swap_init(t_push_swap *nbrs)
{
	nbrs->i = 0;
	nbrs->j = 0;
	nbrs->size = 0;
	nbrs->temp = 0;
	nbrs->save = 0;
	nbrs->stack_a = NULL;
	nbrs->stack_b = NULL;
	nbrs->help1 = NULL;
	nbrs->help2 = NULL;
	nbrs->split = NULL;
}

int	main(int ac, char **av)
{
	t_push_swap	nbrs;

	if (ac < 2)
		exit(0);
	ft_push_swap_init(&nbrs);
	ft_check_args(ac, av, &nbrs);
	// ft_swap_a(&nbrs);
	// ft_push_a(&nbrs);
	while (nbrs.stack_a)
	{
		printf("%d\n", nbrs.stack_a->value);
		nbrs.stack_a = nbrs.stack_a->next;
	}
	return (0);
}
