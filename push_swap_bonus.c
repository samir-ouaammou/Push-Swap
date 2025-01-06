#include "push_swap.h"

void	ft_free_all(t_push_swap *nbrs)
{
	if (nbrs->line != NULL)
	{
		write (2, "Error\n", 6);
		free(nbrs->line);
	}
	free(nbrs->save);
	nbrs->save = NULL;
	ft_lstclear(nbrs, &nbrs->stack_a);
	ft_lstclear(nbrs, &nbrs->stack_b);
	exit(0);
}

int	ft_strcmp(t_push_swap *nbrs, const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	nbrs->nbr = ft_strlen(s2);
	if (s1[nbrs->nbr] != '\n' && s1[nbrs->nbr] != '\0')
		return (0);
	nbrs->i = 0;
	while ((s1[nbrs->i]) && (s1[nbrs->i] == s2[nbrs->i])
		&& (nbrs->i < nbrs->nbr))
		nbrs->i++;
	if (s1[nbrs->i] == s2[nbrs->i])
		return (1);
	if (s1[nbrs->i] == '\n' && s2[nbrs->i] == '\0')
		return (1);
	return (0);
}

void	ft_execute_instructions(t_push_swap *nbrs)
{
	if (ft_strcmp(nbrs, nbrs->line, "sa\n"))
		ft_swap_a(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "sb\n"))
		ft_swap_b(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "ss\n"))
		ft_s_swap(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "pa\n"))
		ft_push_a(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "pb\n"))
		ft_push_b(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "ra\n"))
		ft_rotate_a(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "rb\n"))
		ft_rotate_b(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "rr\n"))
		ft_rotate_rr(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "rra\n"))
		ft_reverse_rotate_a(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "rrb\n"))
		ft_reverse_rotate_b(nbrs);
	else if (ft_strcmp(nbrs, nbrs->line, "rrr\n"))
		ft_reverse_rotate_both(nbrs);
	else
		ft_free_all(nbrs);
}

void	ft_read_instructions(t_push_swap *nbrs)
{
	nbrs->instructions = 1337;
	nbrs->line = get_next_line(0);
	while (nbrs->line != NULL)
	{
		ft_execute_instructions(nbrs);
		free(nbrs->line);
		nbrs->line = NULL;
		nbrs->line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_push_swap	nbrs;

	if (ac < 2)
		exit(0);
	ft_push_swap_init(&nbrs);
	ft_check_args(ac, av, &nbrs);
	ft_read_instructions(&nbrs);
	if (ft_is_sorted(&nbrs, nbrs.stack_a) && !nbrs.stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_all(&nbrs);
	return (0);
}
