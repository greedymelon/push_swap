/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:50:22 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:50:26 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*copy(char *num, int n, int i)
{
	if (n < 0)
	{
		num[i + 1] = '\0';
		num[0] = '-';
		while (i > 0)
		{
			num[i] = '0' - n % 10;
			n /= 10;
			i--;
		}
	}
	else
	{
		num[i] = '\0';
		while (i > 0)
		{
			num[i - 1] = '0' + n % 10;
			n /= 10;
			i--;
		}
	}
	return (num);
}

int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		intlen;

	intlen = ft_intlen(n);
	if (n < 0)
		num = malloc((intlen + 2) * sizeof(char));
	else if (n > 0)
		num = malloc((intlen + 1) * sizeof(char));
	else
		num = malloc(2 * sizeof(char));
	if (num == NULL)
		return (NULL);
	if (n != 0)
		return (copy(num, n, intlen));
	num[0] = '0';
	num[1] = '\0';
	return (num);
}
