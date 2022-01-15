#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*front;

	front = *lst;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (front)
		front = front -> next;
	front -> next = new;
}
