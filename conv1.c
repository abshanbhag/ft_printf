/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:08:51 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/22 11:07:29 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_v *v, long long i)
{
	v->int_fl = 1;
	if (v->flag_plus && v->flag_space)
		v->flag_space = 0;
	v->c_width -= (v->flag_plus || i < 0);
	if (!v->flag_minus)
		int_help12(v, i);
	else
		int_help18(v, i);
	reset_flags(v);
}

void	int_help18(t_v *v, long long i)
{
	if ((v->f_width && !v->f_prec) || (!v->f_width && !v->f_prec))
	{
		if (v->c_width <= num_digit(i))
			int_help13(v, i);
		else if (v->c_width > num_digit(i))
			int_help15(v, i);
	}
	else if ((v->f_prec && !v->f_width) || (v->f_prec && v->f_width \
				&& v->c_prec >= v->c_width))
	{
		if (v->c_prec <= num_digit(i))
			int_help13(v, i);
		else if (v->c_prec > num_digit(i))
			int_help16(v, i);
	}
	else if (v->f_prec && v->f_width && v->c_prec < v->c_width)
		int_help17(v, i);
}

void	print_o(t_v *v, unsigned long long i)
{
	if (!v->flag_minus)
		oct_help17(v, i);
	else
		oct_help18(v, i);
	reset_flags(v);
}

void	print_u(t_v *v, unsigned long long i)
{
	v->u_fl = 1;
	if (!v->flag_minus)
		u_help3(v, i);
	else
	{
		if (v->f_prec && v->c_prec > num_digit(i))
			u_help4(v, i);
		else if ((!v->f_prec && !v->f_width) || \
		(v->f_prec && v->c_prec <= num_digit(i)) || \
		(v->f_width && v->c_width <= num_digit(i)))
			u_help5(v, i);
		else if (v->f_width && (v->c_prec <= num_digit(i)))
		{
			u_help1(v, i);
			u_help2(v, i);
		}
	}
	reset_flags(v);
}

void	print_x(t_v *v, unsigned long long i, int j)
{
	if (j == 0)
		v->x_s = 1;
	else
		v->x_l = 1;
	if (!v->flag_minus)
		hex_help11(v, i);
	else
		hex_help13(v, i);
	reset_flags(v);
}
