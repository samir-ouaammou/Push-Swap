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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
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
