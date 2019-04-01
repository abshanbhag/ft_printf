/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:06:23 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/29 11:40:31 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_v		v;

	ft_bzero(&v, sizeof(v));
	v.fd = 1;
	if (format == NULL)
		return (0);
	v.format = (char *)format;
	va_start(v.ap, format);
	while (*v.format)
	{
		if (*v.format == '%' || *v.format == '{')
			figure_stuff(&v);
		else
			buffadd(&v);
		if (*v.format)
			v.format++;
	}
	va_end(v.ap);
	return (v.a);
}

int		ft_fdprintf(int fd, const char *format, ...)
{
	t_v		v;

	ft_bzero(&v, sizeof(v));
	v.fd = fd;
	if (format == NULL)
		return (0);
	v.format = (char *)format;
	va_start(v.ap, format);
	while (*v.format)
	{
		if (*v.format == '%' || *v.format == '{')
			figure_stuff(&v);
		else
			buffadd(&v);
		if (*v.format)
			v.format++;
	}
	va_end(v.ap);
	return (v.a);
}

void	figure_stuff(t_v *v)
{
	if (*v->format == '%')
	{
		v->format++;
		if (*v->format == '%')
			buffadd(v);
		else
			figure_flags(v);
	}
	else
	{
		v->format++;
		figure_colors(v);
	}
}

void	buffadd(t_v *v)
{
	write(1, &*v->format, 1);
	v->a++;
}

int		num_digit(long long i)
{
	int num_count;

	num_count = 1;
	while (i /= 10)
		num_count++;
	return (num_count);
}
