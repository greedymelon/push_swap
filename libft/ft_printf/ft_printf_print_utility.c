/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utility.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 14:21:23 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/13 14:21:27 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_function.h"

void	print_padding(int width, const char c, int *printed)
{
	if (width < 0)
		width = 0;
	*printed += width;
	while (width > 0)
	{
		write (1, &c, 1);
		width--;
	}
}

void	ft_putjustnbr(int n, int fd, t_flag *bonus)
{
	char	num[11];
	int		count;
	int		i;

	if (n == 0)
	{
		count = 1;
		write (fd, "0", count);
	}
	else
	{
		count = ft_intlen(n);
		i = count - 1;
		if (n > 0)
			n *= -1;
		while (i >= 0)
		{
			num[i] = '0' - n % 10;
			n /= 10;
			i--;
		}
		write (fd, num, count);
	}
	bonus->printed_char += count;
}

void	print_plus_minus(int n, t_flag *bonus)
{
	if (bonus->plus_space || n < 0)
		bonus->printed_char++;
	if (bonus->plus_space == 1 && n >= 0)
		write (1, "+", 1);
	if (bonus->plus_space == 2 && n >= 0)
		write (1, " ", 1);
	if (n < 0)
		write (1, "-", 1);
}

void	print_prefix(char c, unsigned n, t_flag *bonus)
{
	if (n && bonus->prefix)
	{
		bonus->printed_char += bonus->prefix;
		if (c == 'x')
			write(1, "0x", 2);
		if (c == 'X')
			write(1, "0X", 2);
	}
}

void	print_null_ptr(t_flag *bonus)
{
	if (!bonus->dot && bonus->spc_zr == '0')
		print_prefix('x', 1, bonus);
	bonus->width -= 2 + bonus->precision;
	if (!bonus->dot)
		bonus->width -= 1;
	if (!bonus->padding_right && !bonus->dot)
		print_padding(bonus->width, bonus->spc_zr, &bonus->printed_char);
	if (!bonus->padding_right && bonus->dot)
		print_padding(bonus->width, ' ', &bonus->printed_char);
	if (bonus->spc_zr != '0' || bonus->dot)
		print_prefix('x', 1, bonus);
	print_padding(bonus->precision, '0', &bonus->printed_char);
	if (!bonus->dot)
	{	
		write(1, "0", 1);
		bonus->printed_char += 1;
	}
	if (bonus->padding_right)
		print_padding(bonus->width, ' ', &bonus->printed_char);
}
