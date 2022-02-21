/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 15:04:50 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 15:04:52 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*f;

	if (s == NULL)
		return (NULL);
	f = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			f = s;
		s++;
	}
	if (*s == (char)c)
		f = s;
	return ((char *)f);
}
