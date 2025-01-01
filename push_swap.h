#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_push_swap
{
	int		i;
	int		j;
	int		count;
	int		*save;
	char	**split;

}			t_push_swap;

int			ft_isdigit(int c);
int			ft_isempty(char *str);
void		ft_errormsg(char *msg);
void		ft_free_args(char **temp);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
int			ft_atoi(char **temp, const char *str);
int			ft_word_count(const char *str, char c);
void		ft_check_strs(int ac, char **av, t_push_swap *nbrs);
void		ft_check_args(int ac, char **av, t_push_swap *nbrs);

#endif
