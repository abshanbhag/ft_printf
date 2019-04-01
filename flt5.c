/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flt5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:05:12 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/29 11:39:55 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flt_help11(t_v *v, long double i)
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
	flt_help2(v, i);
	while (v->c_width - (num_float(i) + v->c_prec) > 1)
		spz_width(v);
}

void	flt_help12(t_v *v, long double i)
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
		buffadd_string(v, tmp);
		while (v->c_width - num_float(i) > 0)
			spz_width(v);
	}
	else if (!flt_decp(i))
	{
		flt_help2(v, i);
		flt_help14(v, i);
	}
	free(tmp);
}

void	flt_help13(t_v *v, long double i)
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
				flt_help10(v, i);
			else if (!flt_decp(i))
				flt_help11(v, i);
		}
		else
			flt_help12(v, i);
	}
}

void	flt_help14(t_v *v, long double i)
{
	while (v->c_width - (num_float(i) + v->c_prec) > 1)
		spz_width(v);
}

void	addstrtobuff(t_v *v, char *str, int limit)
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (str[i])
	{
		if (found)
			limit--;
		if (str[i] == '.')
			found = 1;
		if ((limit >= 0 || !found) && ((!(limit == 0 && str[i] == '.') \
						|| v->flag_hash)))
		{
			write(1, &str[i], 1);
			v->c_prec--;
			i++;
			v->a++;
		}
		else
			i++;
	}
}
