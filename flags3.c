/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 08:36:20 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/08 08:36:46 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lc_flag(t_v *v)
{
	v->lc_fl = 1;
	if (*v->format == 'f')
		print_flt(v, (long double)va_arg(v->ap, long double));
	v->lc_fl = 0;
}

void	reset_flags(t_v *v)
{
	v->f_prec = 0;
	v->c_prec = 0;
	v->f_width = 0;
	v->c_width = 0;
	v->flag_plus = 0;
	v->flag_space = 0;
	v->flag_neg = 0;
	v->flag_hash = 0;
	v->flag_minus = 0;
	v->flag_zero = 0;
	v->x_s = 0;
	v->x_l = 0;
	v->c_i = 0;
	v->hex_o = 0;
	v->hex_rem = 0;
	v->oct_fl = 0;
	v->int_fl = 0;
	v->flt_fl = 0;
	v->u_fl = 0;
}
