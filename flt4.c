/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flt4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:04:48 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/25 08:42:41 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flt_help6(t_v *v, long double i)
{
	while (v->c_width - (num_float(i) + v->c_prec) > 1)
		spz_width(v);
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space)
		buffadd_string(v, " ");
	flt_help2(v, i);
}

void	flt_help7(t_v *v, long double i)
{
	char	*tmp;

	tmp = ft_ldtoa(i);
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space)
		buffadd_string(v, " ");
	if (flt_decp(i))
	{
		while (v->c_width - num_float(i) > 0)
			spz_width(v);
		buffadd_string(v, tmp);
	}
	else if (!flt_decp(i))
	{
		flt_help14(v, i);
		flt_help2(v, i);
	}
	free(tmp);
}

void	flt_help8(t_v *v, long double i)
{
	if (!v->f_prec)
		v->c_prec = 6;
	if (v->c_width <= num_float(i))
		flt_help3(v, i);
	else if (v->c_width > num_float(i))
	{
		if (!v->flag_zero)
		{
			if (flt_decp(i))
				flt_help5(v, i);
			else if (!flt_decp(i))
				flt_help6(v, i);
		}
		else
			flt_help7(v, i);
	}
}

void	flt_help9(t_v *v, long double i)
{
	while (v->c_width - num_float(i) > 0)
		spz_width(v);
}

void	flt_help10(t_v *v, long double i)
{
	char	*tmp;

	tmp = ft_ldtoa(i);
	if (v->f_width && v->f_prec)
		v->c_width = v->c_width - (ft_strlen(tmp) - 3);
	if (!v->f_prec)
		v->c_prec = 6;
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space)
		buffadd_string(v, " ");
	addstrtobuff(v, tmp, v->c_prec);
	while (v->c_width - ft_min(num_float(i), v->c_prec + 1 + \
				ft_strlen(tmp + (i > 0 && v->flag_plus)) > 0))
		spz_width(v);
	free(tmp);
}
