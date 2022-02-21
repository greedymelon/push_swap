/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:51:49 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:51:59 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*place_holder;
	t_list	*index;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			place_holder = *lst;
			index = *lst;
			while (index != NULL)
			{
				index = index->next;
				del(place_holder->content);
				free(place_holder);
				place_holder = index;
			}
		}
		*lst = NULL;
	}
}
