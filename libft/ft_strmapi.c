/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 15:03:36 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 15:03:38 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	new_s = (char *)malloc (sizeof(char) * ft_strlen(s) + 1);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, ((char *)s)[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
