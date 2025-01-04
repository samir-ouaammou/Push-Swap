#include "push_swap.h"

void	ft_errormsg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	ft_check_strs(int ac, char **av, t_push_swap *nbrs)
{
	nbrs->i = 1;
	while (nbrs->i < ac)
	{
		nbrs->j = 0;
		while (av[nbrs->i][nbrs->j])
		{
			if (!ft_isdigit(av[nbrs->i][nbrs->j]))
				ft_errormsg("Error\n");
			nbrs->j++;
		}
		if (!ft_isempty(av[nbrs->i]))
			ft_errormsg("Error\n");
		nbrs->i++;
	}
}

int	ft_check_str(const char *str, int *sgn, size_t *i)
{
	*i = 0;
	*sgn = 1;
	if ((str[*i] == '-' || str[*i] == '+') && (str[*i + 1] < '0' || str[*i
			+ 1] > '9'))
		return (0);
	return (1);
}

int	ft_atoi(t_push_swap *nbrs, char **temp, const char *str)
{
	long	res;
	size_t	i;
	int		sgn;

	if (!ft_check_str(str, &sgn, &i))
		ft_free_and_exit(nbrs, temp);
	res = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sgn = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		if (((res * sgn) > 2147483647) || ((res * sgn) < -2147483648))
			ft_free_and_exit(nbrs, temp);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		ft_free_and_exit(nbrs, temp);
	return (res * sgn);
}

int	ft_word_count(const char *str, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}
