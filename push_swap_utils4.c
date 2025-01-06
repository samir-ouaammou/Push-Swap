#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_list	*ft_lstnew(int nbr)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (!lst)
		return (NULL);
	lst->value = nbr;
	lst->next = NULL;
	return (lst);
}

void	ft_creat_list(t_push_swap *nbrs)
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	lst = NULL;
	nbrs->i = 0;
	while (nbrs->i < nbrs->size)
	{
		new = ft_lstnew(nbrs->save[nbrs->i]);
		ft_lstadd_back(&lst, new);
		nbrs->i++;
	}
	nbrs->stack_a = lst;
}

void	ft_reverse_rotate_both(t_push_swap *nbrs)
{
	if (ft_lstsize(nbrs->stack_a) > 1 && ft_lstsize(nbrs->stack_b) > 1)
	{
		nbrs->nbr = 1337;
		ft_reverse_rotate_a(nbrs);
		nbrs->nbr = 1337;
		ft_reverse_rotate_b(nbrs);
		if (nbrs->instructions == 0)
			write(1, "rrr\n", 4);
	}
	else
	{
		nbrs->nbr = 0;
		ft_reverse_rotate_a(nbrs);
		ft_reverse_rotate_b(nbrs);
	}
}

void	ft_lstclear(t_push_swap *nbrs, t_list **list)
{
	if (!list)
		return ;
	nbrs->help1 = *list;
	while (nbrs->help1)
	{
		nbrs->help2 = nbrs->help1;
		nbrs->help1 = nbrs->help1->next;
		free(nbrs->help2);
		nbrs->help2 = NULL;
	}
	*list = NULL;
}
