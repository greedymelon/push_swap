/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_long.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:51:44 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/21 19:17:48 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	putnum(const char *str, int neg_pos)
{
	long int	num;

	num = *str - '0';
	str++;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * neg_pos);
}

long int	ft_atoi_long(const char *str)
{
	long int	neg_pos;

	neg_pos = 1;
	while (*str != '\0' && ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg_pos = -1;
		str++;
	}
	if (*str >= '0' && *str <= '9')
		return (putnum(str, neg_pos));
	return (0);
}
