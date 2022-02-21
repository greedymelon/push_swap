/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:50:54 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:50:58 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*place_holder;

	if (*lst == NULL)
		*lst = new;
	else
	{
		place_holder = *lst;
		while (place_holder->next != NULL)
			place_holder = place_holder->next;
		place_holder->next = new;
	}
}
