/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 14:20:22 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/13 14:20:29 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_function.h"

void	is_flag_d_i(int n, t_flag *bonus)
{
	if (n == 0 && bonus->dot && bonus->precision == 0)
		print_padding(bonus->width, ' ', &bonus->printed_char);
	else
	{
		if (bonus->dot)
			bonus->spc_zr = ' ';
		bonus->precision -= ft_intlen(n);
		if (bonus->precision < 0)
			bonus->precision = 0;
		bonus->width -= (ft_intlen(n) + bonus->precision);
		if (bonus->plus_space || n < 0)
			bonus->width -= 1;
		if (!bonus->padding_right && bonus->spc_zr == '0')
			print_plus_minus(n, bonus);
		if (!bonus->padding_right)
			print_padding(bonus->width, bonus->spc_zr, &bonus->printed_char);
		if (bonus->spc_zr != '0' || bonus->padding_right)
			print_plus_minus(n, bonus);
		print_padding(bonus->precision, '0', &bonus->printed_char);
		ft_putjustnbr(n, 1, bonus);
		if (bonus->padding_right)
			print_padding(bonus->width, ' ', &bonus->printed_char);
	}
}

void	is_flag_u(unsigned int n, t_flag *bonus)
{
	if (bonus->dot)
		bonus->spc_zr = ' ';
	if (!n && bonus->dot && !bonus->precision)
		print_padding(bonus->width, ' ', &bonus->printed_char);
	else
	{
		bonus->precision -= ft_uintlen(n);
		if (bonus->precision < 0)
			bonus->precision = 0;
		bonus->width -= (ft_uintlen(n) + bonus->precision);
		if (!bonus->padding_right)
			print_padding(bonus->width, bonus->spc_zr, &bonus->printed_char);
		bonus->printed_char += ft_uintlen(n);
		print_padding(bonus->precision, '0', &bonus->printed_char);
		ft_putunbr_fd(n, 1);
		if (bonus->padding_right)
			print_padding(bonus->width, ' ', &bonus->printed_char);
	}
}

void	is_flag_x(const char c, unsigned int n, t_flag *bonus)
{
	char	hex_map[17];
	char	hex_numb[9];

	if (!n && bonus->dot && !bonus->precision)
		print_padding(bonus->width, ' ', &bonus->printed_char);
	else
	{
		set_hex_map(hex_map, c);
		save_hex(hex_numb, hex_map, n, &bonus->printed_char);
		bonus->precision -= ft_strlen(hex_numb);
		if (bonus->precision < 0)
				bonus->precision = 0;
		bonus->width -= (ft_strlen(hex_numb) + bonus->precision);
		if (n)
			bonus->width -= bonus->prefix;
		if (!bonus->padding_right && (bonus->spc_zr != '0' || bonus->dot))
			print_padding(bonus->width, ' ', &bonus->printed_char);
		print_prefix(c, n, bonus);
		if (!bonus->padding_right && (bonus->spc_zr == '0' && !bonus->dot))
			print_padding(bonus->width, bonus->spc_zr, &bonus->printed_char);
		print_padding(bonus->precision, '0', &bonus->printed_char);
		ft_putstr_fd(hex_numb, 1);
		if (bonus->padding_right)
			print_padding(bonus->width, ' ', &bonus->printed_char);
	}
}

void	is_flag_p(void *ptr, t_flag *bonus)
{
	char	hex_map[17];
	char	hex_numb[13];

	bonus->prefix = 2;
	if (ptr == NULL)
		print_null_ptr(bonus);
	else
	{	
		set_hex_map(hex_map, 'x');
		save_hex(hex_numb, hex_map, (unsigned long)ptr, &bonus->printed_char);
		bonus->precision -= ft_strlen(hex_numb);
		if (bonus->precision < 0)
			bonus->precision = 0;
		bonus->width -= ft_strlen(hex_numb) + 2 + bonus->precision;
		if (!bonus->padding_right && bonus->spc_zr == ' ')
			print_padding(bonus->width, bonus->spc_zr, &bonus->printed_char);
		print_prefix('x', 1, bonus);
		if (!bonus->padding_right && bonus->spc_zr == '0')
			print_padding(bonus->width, bonus->spc_zr, &bonus->printed_char);
		print_padding(bonus->precision, '0', &bonus->printed_char);
		ft_putstr_fd(hex_numb, 1);
		if (bonus->padding_right)
			print_padding(bonus->width, ' ', &bonus->printed_char);
	}
}

void	is_flag_s(char *s, t_flag *bonus)
{
	int	to_print;

	if (s == NULL)
	{
		if (!bonus->dot || bonus->precision >= 6)
			to_print = 6;
		else
			to_print = bonus->precision;
	}
	else if (!bonus->dot || bonus->precision >= (int)ft_strlen(s))
		to_print = ft_strlen(s);
	else
		to_print = bonus->precision;
	bonus->width -= to_print;
	if (!bonus->padding_right)
		print_padding(bonus->width, bonus->spc_zr, &bonus->printed_char);
	if (s == NULL)
		write(1, "(null)", to_print);
	else
		write(1, s, to_print);
	if (bonus->padding_right)
		print_padding(bonus->width, ' ', &bonus->printed_char);
	bonus->printed_char += to_print;
}
