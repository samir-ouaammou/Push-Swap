#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_push_swap
{
	int				i;
	int				j;
	int				nbr;
	int				size;
	int				temp;
	int				start;
	int				end;
	int				*save;
	char			**split;
	t_list			*stack_a;
	t_list			*stack_b;
	t_list			*help1;
	t_list			*help2;
}					t_push_swap;

int					ft_isdigit(int c);
int					ft_isempty(char *str);
void				ft_errormsg(char *msg);
int					ft_lstsize(t_list *lst);
void				ft_free_args(char **temp);
size_t				ft_strlen(const char *str);
void				ft_swap_a(t_push_swap *nbrs);
void				ft_swap_b(t_push_swap *nbrs);
void				ft_s_swap(t_push_swap *nbrs);
void				ft_push_a(t_push_swap *nbrs);
void				ft_push_b(t_push_swap *nbrs);
void				ft_sort_tab(t_push_swap *nbrs);
void				ft_rotate_a(t_push_swap *nbrs);
void				ft_rotate_b(t_push_swap *nbrs);
void				ft_rotate_rr(t_push_swap *nbrs);
void				ft_creat_list(t_push_swap *nbrs);
char				**ft_split(char const *s, char c);
void				ft_sort_large_stack(t_push_swap *nbrs);
int					ft_word_count(const char *str, char c);
void				ft_reverse_rotate_a(t_push_swap *nbrs);
void				ft_reverse_rotate_b(t_push_swap *nbrs);
void				ft_sort_five_elements(t_push_swap *nbrs);
void				ft_sort_four_elements(t_push_swap *nbrs);
void				ft_reverse_rotate_both(t_push_swap *nbrs);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_is_sorted(t_push_swap *nbrs, t_list *lst);
void				ft_lstclear(t_push_swap *nbrs, t_list **list);
void				ft_free_and_exit(t_push_swap *nbrs, char **str);
void				ft_check_strs(int ac, char **av, t_push_swap *nbrs);
void				ft_check_args(int ac, char **av, t_push_swap *nbrs);
int					ft_atoi(t_push_swap *nbrs, char **temp, const char *str);
void				ft_sort_two_elements(t_push_swap *nbrs, t_list *lst,
						char c);
void				ft_sort_three_elements(t_push_swap *nbrs, t_list *lst,
						char c);

#endif
