/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:54:42 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:54:44 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (s == NULL || n == 0)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		i++;
		str++;
	}
	return (NULL);
}
