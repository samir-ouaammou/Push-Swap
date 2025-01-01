#include "push_swap.h"

void	ft_free_args(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(temp);
	temp = NULL;
}

void	ft_free_and_exit(char **str)
{
	ft_free_args(str);
	write(2, "Error\n", 6);
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

int	ft_atoi(char **temp, const char *str)
{
	long	res;
	size_t	i;
	int		sgn;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	sgn = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	res = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		if (((res * sgn) > 2147483647) || ((res * sgn) < -2147483648))
			ft_free_and_exit(temp);
		i++;
	}
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
