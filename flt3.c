/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flt3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:04:28 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/26 16:20:04 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flt_help1(t_v *v, long double i)
{
	char	*befdecp;
	char	*aftdecp;
	char	*str;

	befdecp = bdecp(i);
	aftdecp = adecp(i);
	str = ft_strjoin(befdecp, ".");
	free(befdecp);
	befdecp = ft_strjoin(str, aftdecp);
	free(aftdecp);
	free(str);
	addstrtobuff(v, befdecp, v->c_prec);
	free(befdecp);
}

void	flt_help2(t_v *v, long double i)
{
	char	*tmp;

	tmp = ft_ldtoa(i);
	buffadd_string(v, tmp);
	buffadd_string(v, ".");
	while (v->c_prec > 0)
	{
		buffadd_string(v, "0");
		v->c_prec--;
	}
}

void	flt_help3(t_v *v, long double i)
{
	int		d;

	d = num_digit(i) + (v->c_prec ? 1 : 0) + v->c_prec;
	while (d && !v->flag_minus && v->c_prec < v->c_width)
	{
		spz_width(v);
		d--;
	}
	if (i < 0)
	{
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space)
		buffadd_string(v, " ");
	flt_help16(v, i);
	flt_help15(v, i);
	while (d && v->flag_minus)
	{
		spz_width(v);
		d--;
	}
}

void	flt_help4(t_v *v, long double i)
{
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
		flt_help1(v, i);
	else if (!flt_decp(i))
		flt_help2(v, i);
}

void	flt_help5(t_v *v, long double i)
{
	char	*tmp;

	tmp = ft_ldtoa(i);
	if (v->f_width && v->f_prec)
		v->c_width = v->c_width - (ft_strlen(tmp) - 3) + v->flag_space;
	if (!v->f_prec)
		v->c_prec = 6;
	if (v->f_width && !v->f_prec)
		flt_help9(v, i);
	if (v->f_prec)
	{
		while (v->c_width - v->flag_space - \
				ft_max(num_float(i), v->c_prec) + 1 + \
				ft_strlen(tmp + (i > 0 && v->flag_plus)) > 0)
			spz_width(v);
	}
	if (i < 0)
	{
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	addstrtobuff(v, tmp, v->c_prec);
	free(tmp);
}
