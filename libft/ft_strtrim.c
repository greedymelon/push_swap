/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 15:05:12 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 15:05:14 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && is_in(s1[start], set))
		start++;
	end = start;
	while (s1[end] != '\0')
		end++;
	while (end > start && is_in(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
