/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_function.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 14:18:42 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/21 21:52:47 by dmonfrin     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FUNCTION_H
# define FT_PRINTF_FUNCTION_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	int		plus_space;
	char	spc_zr;
	int		width;
	int		padding_right;
	int		dot;
	int		precision;
	int		prefix;
	int		index;
	int		printed_char;
}t_flag;

void	is_flag_c(char c, t_flag *bonus);
void	is_flag_d_i(int n, t_flag *bonus);
void	is_flag_p(void *ptr, t_flag *bonus);
void	is_flag_s(char *s, t_flag *bonus);
void	is_flag_u(unsigned int n, t_flag *bonus);
void	is_flag_x(const char c, unsigned int n, t_flag *bonus);
int		is_width(const char *str, t_flag *bonus);
int		is_flag(char c);
int		is_flag_dot(const char *str, t_flag *bonus);
void	print_plus_minus(int n, t_flag *bonus);
void	print_prefix(char c, unsigned n, t_flag *bonus);
void	print_padding(int width, const char c, int *printed);
void	print_null_ptr(t_flag *bonus);
void	ft_putjustnbr(int n, int fd, t_flag *bonus);
void	save_hex(char *hex_numb, const char *hex_map, unsigned long n, int *pr);
void	set_hex_map(char *hex_map, const char is_caps_l);
int		count_hex(unsigned long n);
void	initialize(t_flag *bonus);

#endif
