/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:59:01 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:59:04 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	**ft_free_mem(char **str_of_str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str_of_str[i]);
		i++;
	}	
	free(str_of_str);
	return (NULL);
}

static char	**copystr(char *s, char **str_of_str, int count, char c)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < count)
	{
		while (s[start] == c && s[start])
			start++;
		while (s[start + end] != c && s[start + end])
			end++;
		str_of_str[i] = ft_substr(s, start, end);
		if (str_of_str[i] == NULL)
		{	
			ft_free_mem(str_of_str, i);
			return (NULL);
		}
		i++;
		start += end;
		end = 0;
	}
	return (str_of_str);
}

char	**ft_split(char const *s, char c)
{
	char	**str_of_str;
	int		count;
	int		i;

	if (s == NULL)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (((char *)s)[i] != c)
		{	
			count++;
			while (((char *)s)[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	str_of_str = malloc((count + 1) * sizeof (char *));
	if (str_of_str == NULL)
		return (NULL);
	str_of_str[count] = NULL;
	return (copystr((char *)s, str_of_str, count, c));
}
