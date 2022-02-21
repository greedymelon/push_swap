/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:58:18 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/15 14:58:21 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	copy(char *num, int n, int i)
{
	if (n < 0)
	{
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
		while (i > 0)
		{
			num[i - 1] = '0' + n % 10;
			n /= 10;
			i--;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	int		count;

	if (n == 0)
		write (fd, "0", 1);
	else
	{
		count = ft_intlen(n);
		copy(num, n, count);
		if (n < 0)
			write (fd, num, count + 1);
		else
			write (fd, num, count);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	num[10];
	int		count;
	int		i;

	if (n == 0)
		write (fd, "0", 1);
	else
	{
		i = 1;
		count = ft_uintlen(n);
		while (count - i >= 0)
		{
			num[count - i] = '0' + n % 10;
			n /= 10;
			i++;
		}
		write (fd, num, count);
	}
}
