/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:18:47 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/26 14:39:14 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spz_width(t_v *v)
{
	if (v->flag_zero && !v->flag_minus && !v->m_fl)
	{
		if ((v->oct_fl && v->f_prec) || (v->u_fl && v->f_prec) \
			|| (v->x_s && v->f_prec) || (v->x_l && v->f_prec) \
			|| (v->int_fl && v->f_prec))
			buffadd_string(v, " ");
		else
			buffadd_string(v, "0");
	}
	else
		buffadd_string(v, " ");
	v->c_width--;
}

void	spz_prec(t_v *v)
{
	buffadd_string(v, "0");
	v->c_prec--;
}

void	lwidth_m_digm1(t_v *v, long long i)
{
	while (v->c_width - num_digit(i) > -1)
		spz_width(v);
}

void	lwidth_m_dig0(t_v *v, long long i)
{
	while (v->c_width - num_digit(i) + (v->f_prec && v->c_prec == 0) - \
			(v->flag_space) > 0)
		spz_width(v);
}

void	lwidth_m_dig1(t_v *v, long long i)
{
	while (v->c_width - num_digit(i) > 1)
		spz_width(v);
}
