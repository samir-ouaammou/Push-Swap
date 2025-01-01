#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_errormsg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(-1);
}
