/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv17.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 09:11:33 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/22 10:34:02 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_help8(t_v *v, long long i)
{
	if (i == 0 && v->c_prec == 0)
	{
		while (v->c_width - (num_digit(i) - 1) > 0)
			spz_width(v);
	}
	else
	{
		while (v->c_width - num_digit(i) > 0)
			spz_width(v);
	}
}

void	int_help9(t_v *v)
{
	if (!v->c_prec)
		buffadd_string(v, "");
	else
		buffadd_string(v, "0");
}

void	int_help10(t_v *v)
{
	buffadd_string(v, "0");
	v->c_prec--;
}

void	int_help11(t_v *v, long long i)
{
	if (v->c_prec < num_digit(i))
		int_help8(v, i);
	else if (v->c_prec >= num_digit(i))
	{
		while (v->c_width - v->c_prec - v->flag_space > 0)
			spz_width(v);
	}
	if (i < 0)
	{
		buffadd_string(v, "-");
		i = i * -1;
		v->flag_neg = 1;
	}
	else if (i > 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space && i >= 1)
		buffadd_string(v, " ");
	while ((v->c_prec - num_digit(i)) > 0)
		int_help10(v);
	if (i != 0)
		int_help1(v, i);
	else
		int_help9(v);
}

void	int_help12(t_v *v, long long i)
{
	if ((v->f_width && !v->f_prec) || (!v->f_width && !v->f_prec))
		int_help5(v, i);
	else if ((v->f_prec && !v->f_width) || (v->f_prec && v->f_width && \
				v->c_prec >= v->c_width))
	{
		if (v->c_prec == 0 && v->f_prec && i == 0)
			buffadd_string(v, "");
		else
		{
			if (v->c_prec <= num_digit(i))
				int_help6(v, i);
			else if (v->c_prec > num_digit(i))
				int_help7(v, i);
		}
	}
	else if (v->f_prec && v->f_width && v->c_prec < v->c_width)
		int_help11(v, i);
}
