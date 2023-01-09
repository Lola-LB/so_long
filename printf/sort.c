/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolalebreton <lolalebreton@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:50:26 by lle-bret          #+#    #+#             */
/*   Updated: 2022/10/17 11:56:37 by lolalebreto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*sort_int(va_list *ap, t_mode *mode)
{
	char	*to_print;
	int		n;

	to_print = 0;
	if (mode->modifier->j)
		to_print = convert_int(va_arg(*ap, intmax_t), mode);
	else if (mode->modifier->z)
		to_print = convert_int((intmax_t) va_arg(*ap, ptrdiff_t), mode);
	else if (mode->modifier->ll)
		to_print = convert_int((intmax_t) va_arg(*ap, long long), mode);
	else if (mode->modifier->l)
		to_print = convert_int((intmax_t) va_arg(*ap, long), mode);
	else if (mode->modifier->hh)
	{
		n = va_arg(*ap, int) % 256;
		if (n > 127)
			n -= 256;
		to_print = convert_int((intmax_t) n, mode);
	}
	else if (mode->modifier->h)
		to_print = convert_int((intmax_t)(short) va_arg(*ap, int), mode);
	else
		to_print = convert_int((intmax_t) va_arg(*ap, int), mode);
	return (to_print);
}

char	*sort_uint(va_list *ap, t_mode *mode)
{
	char	*to_print;
	int		n;

	to_print = 0;
	if (mode->modifier->j)
		to_print = convert_int(va_arg(*ap, uintmax_t), mode);
	else if (mode->modifier->z)
		to_print = convert_int((intmax_t) va_arg(*ap, ptrdiff_t), mode);
	else if (mode->modifier->ll)
		to_print = convert_int((intmax_t)
				va_arg(*ap, unsigned long long), mode);
	else if (mode->modifier->l)
		to_print = convert_int((intmax_t) va_arg(*ap, unsigned long), mode);
	else if (mode->modifier->h)
		to_print = convert_int((intmax_t)(short)
				va_arg(*ap, unsigned int), mode);
	else if (mode->modifier->hh)
	{
		n = va_arg(*ap, int) % 256;
		to_print = convert_int((intmax_t) n, mode);
	}
	else
		to_print = convert_int((intmax_t) va_arg(*ap, unsigned int), mode);
	return (to_print);
}

char	*sort_str(va_list *ap, t_mode *mode)
{
	char	*to_print;

	to_print = 0;
	if (mode->conversion == 's')
	{
		if (mode->modifier->l)
			to_print = convert_str((char *) va_arg(*ap, wchar_t *), mode);
		else
			to_print = convert_str(va_arg(*ap, char *), mode);
	}
	else if (mode->conversion == 'c')
	{	
		if (mode->modifier->l)
			to_print = convert_char(va_arg(*ap, wint_t));
		else
			to_print = convert_char((unsigned char) va_arg(*ap, int));
	}
	return (to_print);
}

char	*sort_ptr(va_list *ap, t_mode *mode)
{
	char	*to_print;

	mode->flag->sharp = 1;
	to_print = convert_int((intmax_t) va_arg(*ap, ptrdiff_t), mode);
	return (to_print);
}
