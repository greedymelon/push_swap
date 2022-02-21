/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:53:29 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:53:31 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	new_list = ft_lstnew(f(lst->content));
	if (new_list == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new_element = ft_lstnew(f(lst->content));
		if (new_element == NULL)
			break ;
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	if (lst == NULL)
		return (new_list);
	ft_lstclear(&new_list, del);
	return (NULL);
}
