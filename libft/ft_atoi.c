/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:46:24 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:46:31 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

static int	putnum(const char *str, int i)
{
	int	num;

	num = *str - '0';
	str++;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * i);
}

int	ft_atoi(const char *str)
{
	int	i;

	i = 1;
	while (*str != '\0' && ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		i = -1;
		str++;
	}
	if (*str >= '0' && *str <= '9')
		return (putnum(str, i));
	return (0);
}
