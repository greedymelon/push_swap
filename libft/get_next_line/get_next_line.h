/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 13:39:34 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/16 15:07:09 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# if BUFFER_SIZE <= 0 || BUFFER_SIZE > 65536
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX _SC_OPEN_MAX
# endif

# include "../libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoing(char *s1, char *s2, int n);
char	*is_end(char *str);
void	set_zero(char *b);
#endif
