/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:56:15 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:56:19 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
		return (dst);
	}
	while (len)
	{
		((char *)dst)[len - 1] = ((char *)src)[len - 1];
		len--;
	}
	return (dst);
}
