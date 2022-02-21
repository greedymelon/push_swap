/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 15:01:49 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 15:01:52 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nws;
	size_t	nwssize;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nwssize = ft_strlen(s1) + ft_strlen(s2) + 1;
	nws = (char *)malloc(nwssize * sizeof(char));
	if (nws == NULL)
		return (NULL);
	ft_strlcpy(nws, s1, nwssize);
	ft_strlcat(nws, s2, nwssize);
	return (nws);
}
