/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 08:47:55 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/29 11:38:05 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_v *v, char str)
{
	if (v->f_width)
	{
		if (!v->flag_minus)
		{
			char_space(v);
			write(1, &str, 1);
		}
		else
		{
			write(1, &str, 1);
			char_space(v);
		}
	}
	else
		write(1, &str, 1);
	v->a++;
}

void	print_perc(t_v *v)
{
	char c;

	c = '%';
	if (v->f_width)
	{
		if (!v->flag_minus)
		{
			char_space(v);
			write(1, &c, 1);
		}
		else
		{
			write(1, &c, 1);
			char_space(v);
		}
	}
	else
		write(1, &c, 1);
	v->a++;
}

void	print_p(t_v *v)
{
	char *a;
	void *i;

	i = va_arg(v->ap, void *);
	a = dec_to_hexa(v, (unsigned long long)i, 'a');
	if (v->f_width && !v->flag_minus)
	{
		if (v->flag_zero)
			buffadd_string(v, "0x");
		while (v->c_width - (ft_strlen(a) + 2) > 0)
			spz_width(v);
	}
	if (!v->flag_zero)
		buffadd_string(v, "0x");
	buffadd_string(v, a);
	if (v->flag_minus)
	{
		while (v->c_width - (ft_strlen(a) + 2) > 0)
			spz_width(v);
	}
	free(a);
	reset_flags(v);
}

void	print_s(t_v *v, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (v->f_prec == 0 && v->f_width == 0)
		buffadd_string(v, str);
	else if (v->f_width || v->f_prec)
	{
		if ((v->f_width && v->f_prec && (v->c_width <= v->c_prec)) \
				|| (!v->f_width && v->f_prec))
			s_help1(v, str);
		else if (v->f_width && v->f_prec && (v->c_width > v->c_prec))
			s_help2(v, str);
		else if (v->f_width && !v->f_prec)
			s_help3(v, str);
	}
	reset_flags(v);
}

void	print_flt(t_v *v, long double i)
{
	v->flt_fl = 1;
	if (v->flag_plus && v->flag_space)
		v->flag_space = 0;
	if (!v->flag_minus)
	{
		if ((v->f_width && !v->f_prec) || (!v->f_width && !v->f_prec))
			flt_help8(v, i);
		else if (v->f_prec && !v->f_width)
			flt_help4(v, i);
		else if (v->f_prec && v->f_width)
			flt_help8(v, i);
	}
	else
	{
		if ((v->f_width && !v->f_prec) || (!v->f_width && !v->f_prec))
			flt_help13(v, i);
		else if (v->f_prec && !v->f_width)
			flt_help4(v, i);
		else if (v->f_prec && v->f_width)
			flt_help13(v, i);
	}
	reset_flags(v);
}
