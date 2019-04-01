/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:53:58 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/19 13:08:05 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	h_flag(t_v *v)
{
	v->h_fl = 1;
	if (*v->format == 'd' || *v->format == 'i')
		print_int(v, (short)va_arg(v->ap, int));
	else if (*v->format == 'p')
		print_p(v);
	else if (*v->format == 'o')
		print_o(v, (unsigned short)va_arg(v->ap, int));
	else if (*v->format == 'u')
		print_u(v, (unsigned short)va_arg(v->ap, int));
	else if (*v->format == 'x')
		print_x(v, (unsigned short)va_arg(v->ap, int), 0);
	else if (*v->format == 'X')
		print_x(v, (unsigned short)va_arg(v->ap, int), 1);
	else if (*v->format != '\0')
		buffadd(v);
	v->h_fl = 0;
}

void	hh_flag(t_v *v)
{
	v->hh_fl = 1;
	v->format++;
	if (*v->format == 'd' || *v->format == 'i')
		print_int(v, (char)va_arg(v->ap, int));
	else if (*v->format == 'p')
		print_p(v);
	else if (*v->format == 'o')
		print_o(v, (unsigned char)va_arg(v->ap, int));
	else if (*v->format == 'u')
		print_u(v, (unsigned char)va_arg(v->ap, int));
	else if (*v->format == 'x')
		print_x(v, (unsigned char)va_arg(v->ap, int), 0);
	else if (*v->format == 'X')
		print_x(v, (unsigned char)va_arg(v->ap, int), 1);
	else if (*v->format != '\0')
		buffadd(v);
	v->hh_fl = 0;
}

void	l_flag(t_v *v)
{
	v->l_fl = 1;
	if (*v->format == 'd' || *v->format == 'i')
		print_int(v, (long)va_arg(v->ap, long));
	else if (*v->format == 'p')
		print_p(v);
	else if (*v->format == 'o')
		print_o(v, (unsigned long long)va_arg(v->ap, unsigned long));
	else if (*v->format == 'u')
		print_u(v, (unsigned long)va_arg(v->ap, unsigned long));
	else if (*v->format == 'x')
		print_x(v, (unsigned long)va_arg(v->ap, unsigned long), 0);
	else if (*v->format == 'X')
		print_x(v, (unsigned long)va_arg(v->ap, unsigned long), 1);
	else if (*v->format == 'f')
		print_flt(v, (double)va_arg(v->ap, double));
	else if (*v->format != '\0')
		buffadd(v);
	v->l_fl = 0;
}

void	ll_flag(t_v *v)
{
	v->ll_fl = 1;
	v->format++;
	if (*v->format == 'd' || *v->format == 'i')
		print_int(v, (long long)va_arg(v->ap, long long));
	else if (*v->format == 'p')
		print_p(v);
	else if (*v->format == 'o')
		print_o(v, (unsigned long long)va_arg(v->ap, unsigned long long));
	else if (*v->format == 'u')
		print_u(v, (unsigned long long)va_arg(v->ap, unsigned long long));
	else if (*v->format == 'x')
		print_x(v, (unsigned long long)va_arg(v->ap, unsigned long long), 0);
	else if (*v->format == 'X')
		print_x(v, (unsigned long long)va_arg(v->ap, unsigned long long), 1);
	else if (*v->format != '\0')
		buffadd(v);
	v->ll_fl = 0;
}

void	no_flag(t_v *v)
{
	if (*v->format == 'c')
		print_char(v, va_arg(v->ap, int));
	else if (*v->format == 's')
		print_s(v, va_arg(v->ap, char *));
	else if (*v->format == '%')
		print_perc(v);
	else if (*v->format == 'p')
		print_p(v);
	else if (*v->format == 'd' || *v->format == 'i')
		print_int(v, va_arg(v->ap, int));
	else if (*v->format == 'o')
		print_o(v, (unsigned int)va_arg(v->ap, int));
	else if (*v->format == 'u')
		print_u(v, va_arg(v->ap, unsigned int));
	else if (*v->format == 'x')
		print_x(v, (unsigned int)va_arg(v->ap, int), 0);
	else if (*v->format == 'X')
		print_x(v, (unsigned int)va_arg(v->ap, int), 1);
	else if (*v->format == 'f')
		print_flt(v, va_arg(v->ap, double));
	else if (*v->format != '\0')
		buffadd(v);
}
