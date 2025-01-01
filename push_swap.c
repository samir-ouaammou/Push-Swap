#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	nbrs;

	if (ac < 2)
		exit(0);
	ft_check_args(ac, av, &nbrs);
	return (0);
}
