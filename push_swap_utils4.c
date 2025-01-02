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