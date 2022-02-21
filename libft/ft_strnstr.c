/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 15:04:26 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 15:04:28 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle || !haystack || !needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && i + j < len && haystack[i + j] == needle[j])
		{
			if (!needle[j])
				return (&((char *)haystack)[i]);
			j++;
		}
		if (!needle[j])
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
