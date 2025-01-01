#include "push_swap.h"

int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || (c == 32) || (c == '-'));
}

void	ft_save_nbrs(t_push_swap *nbrs)
{
	nbrs->j = 0;
	while (nbrs->split[nbrs->j])
	{
		nbrs->save[nbrs->size] = ft_atoi(nbrs->split, nbrs->split[nbrs->j]);
		nbrs->size++;
		nbrs->j++;
	}
}

void	ft_check_duplicates(t_push_swap *nbrs)
{
	nbrs->i = 0;
	while (nbrs->i < nbrs->size)
	{
		nbrs->j = nbrs->i + 1;
		while (nbrs->j < nbrs->size)
		{
			if (nbrs->save[nbrs->i] == nbrs->save[nbrs->j])
			{
				free(nbrs->save);
				write(2, "Error\n", 6);
				exit(-1);
			}
			nbrs->j++;
		}
		nbrs->i++;
	}
}

void	ft_check_args(int ac, char **av, t_push_swap *nbrs)
{
	ft_check_strs(ac, av, nbrs);
	nbrs->i = 1;
	nbrs->size = 0;
	while (nbrs->i < ac)
	{
		nbrs->size += ft_word_count(av[nbrs->i], ' ');
		nbrs->i++;
	}
	nbrs->save = malloc((nbrs->size) * sizeof(int *));
	if (!nbrs->save)
		ft_errormsg("Error\n");
	nbrs->size = 0;
	nbrs->i = 1;
	while (nbrs->i < ac)
	{
		nbrs->split = ft_split(av[nbrs->i], ' ');
		ft_save_nbrs(nbrs);
		ft_free_args(nbrs->split);
		nbrs->i++;
	}
	ft_check_duplicates(nbrs);
	ft_creat_list(nbrs);
	free(nbrs->save);
	nbrs->save = NULL;
}
