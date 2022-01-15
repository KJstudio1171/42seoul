#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*maplist;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	maplist = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&maplist, del);
			return (NULL);
		}
		ft_lstadd_back(&maplist, tmp);
		lst = lst -> next;
	}
	return (maplist);
}
