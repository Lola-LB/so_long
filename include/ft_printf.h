/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:08:41 by lle-bret          #+#    #+#             */
/*   Updated: 2022/10/28 13:58:29 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stddef.h>

typedef struct s_flag {
	int	sharp;
	int	zero;
	int	minus;
	int	plus;
	int	space;
}	t_flag;

typedef struct s_modifier {
	int	hh;
	int	h;
	int	ll;
	int	l;
	int	j;
	int	z;
}	t_modifier;

typedef struct s_mode {
	t_flag		*flag;
	t_modifier	*modifier;
	int			width;
	int			precision;
	char		conversion;
}	t_mode;

int			ft_printf(const char *format, ...);

// Mode
t_mode		*create_mode(void);
void		init_mode(t_mode *mode);
void		free_mode(t_mode *mode);

// Util
void		*malloc_error(void);
char		*ft_prepend(char *to_print, char *to_add);
char		*ft_append(char *to_print, char *to_add);

// Parse
const char	*get_flag(const char *format, t_mode *mode);
const char	*get_width(const char *format, t_mode *mode);
const char	*get_precision(const char *format, t_mode *mode);
const char	*get_modifier(const char *format, t_mode *mode);

// Convert
char		*convert_int(intmax_t n, t_mode *mode);
char		*convert_str(char *str, t_mode *mode);
char		*convert_char(char c);

// Sort
char		*sort_int(va_list *ap, t_mode *mode);
char		*sort_uint(va_list *ap, t_mode *mode);
char		*sort_str(va_list *ap, t_mode *mode);
char		*sort_ptr(va_list *ap, t_mode *mode);

// Print
char		*get_to_print(va_list *ap, t_mode *mode);
int			print(char **to_print, t_mode *mode);

// Flags
char		*add_alternate(char *to_print, t_mode *mode);
char		*add_sign(char *to_print, t_mode *mode);
char		*add_precision(char *to_print, t_mode *mode);

// Padding
char		*add_padding(char *to_print, t_mode *mode);

#endif
