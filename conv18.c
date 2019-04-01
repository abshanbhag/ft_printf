/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv18.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 09:11:53 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/26 16:37:33 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_help13(t_v *v, long long i)
{
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space && i >= 0)
		buffadd_string(v, " ");
	int_help1(v, i);
}

void	int_help14(t_v *v, long long i)
{
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space && i >= 0)
	{
		buffadd_string(v, " ");
	}
	int_help1(v, i);
	lwidth_m_dig0(v, i);
}

void	int_help15(t_v *v, long long i)
{
	if (!v->flag_zero)
		int_help14(v, i);
	else
	{
		if (i < 0)
		{
			buffadd_string(v, "-");
			i = i * -1;
			v->flag_neg = 1;
		}
		else if (i >= 0 && v->flag_plus && !v->flag_neg)
			buffadd_string(v, "+");
		if (v->flag_space && i >= 0)
			buffadd_string(v, " ");
		int_help1(v, i);
		lwidth_m_dig0(v, i);
	}
}

void	int_help16(t_v *v, long long i)
{
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space && i >= 0)
		buffadd_string(v, " ");
	while ((v->c_prec - num_digit(i)) > 0)
	{
		buffadd_string(v, "0");
		v->c_prec--;
	}
	int_help1(v, i);
}

void	int_help17(t_v *v, long long i)
{
	int prec;

	prec = v->c_prec;
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space && i >= 0)
		buffadd_string(v, " ");
	while ((v->c_prec - num_digit(i)) > 0)
	{
		buffadd_string(v, "0");
		v->c_prec--;
	}
	int_help1(v, i);
	while (v->c_width - ft_max(num_digit(i), prec) - (v->flag_plus) + \
			(v->flag_plus && v->flag_minus) > 0)
		spz_width(v);
}
