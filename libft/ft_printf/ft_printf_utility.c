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

void	set_hex_map(char *hex_map, const char is_caps_l)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		hex_map[i] = '0' + i;
		i++;
	}
	if (is_caps_l == 'X')
	{
		while (i < 17)
		{
			hex_map[i] = '7' + i;
			i++;
		}
	}
	else
	{
		while (i < 17)
		{
			hex_map[i] = 'W' + i;
			i++;
		}
	}
	hex_map[i] = '\0';
}

int	count_hex(unsigned long n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

void	save_hex(char *hex_numb, const char *hex_map, unsigned long n, int *pr)
{
	int	i;

	if (!n)
	{
		hex_numb[0] = '0';
		hex_numb[1] = '\0';
	}
	else
	{
		i = count_hex(n) - 1;
		hex_numb[i + 1] = '\0';
		while (i >= 0)
		{
			hex_numb[i] = hex_map[n % 16];
			n /= 16;
			i--;
		}
	}
	*pr += ft_strlen(hex_numb);
}

void	initialize(t_flag *bonus)
{
	bonus->plus_space = 0;
	bonus->spc_zr = ' ';
	bonus->width = 0;
	bonus->padding_right = 0;
	bonus->dot = 0;
	bonus->precision = 0;
	bonus->prefix = 0;
	bonus->index = 0;
}
