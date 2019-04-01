/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:08:17 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/21 18:34:38 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_help14(t_v *v, long long i)
{
	if (v->l_fl || v->ll_fl)
		oct_help2(v, i);
	else
	{
		while (v->c_width - (num_digit(i) + v->c_prec) > 3)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
}

void	oct_help15(t_v *v, long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while (v->c_width - num_digit(i) > 1)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
	else
	{
		while (v->c_width - (num_digit(i) + v->c_prec) > 2)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
}

void	oct_help16(t_v *v, long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while (v->c_width - num_digit(i) > 1)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
	else
	{
		while (v->c_width - num_digit(i) > 0)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
}

void	oct_help17(t_v *v, long long i)
{
	if ((v->flag_hash && v->c_prec <= num_digit(i) \
				&& v->f_width && v->f_prec) ||
			(v->flag_hash && v->f_width && !v->f_prec))
		oct_help11(v, i);
	else if (!v->flag_hash && v->c_prec <= num_digit(i) \
			&& v->f_width && v->f_prec)
		oct_help8(v, i);
	else if (!v->flag_hash && v->f_width && !v->f_prec)
		oct_help7(v, i);
	else if (v->flag_hash && v->c_prec <= num_digit(i) && !v->f_width)
	{
		if (i != 0 || v->f_prec)
			buffadd_string(v, "0");
	}
	if (v->f_prec == 0 || (v->f_prec && v->c_prec <= num_digit(i) && i != 0))
		oct_help1(v, i);
	if (v->f_prec && v->c_prec == 0 && i == 0 && !v->flag_hash)
		buffadd_string(v, "");
	else if ((v->f_prec && v->c_prec > num_digit(i) && v->f_width \
				&& v->c_prec > v->c_width) \
			|| ((v->f_prec && v->c_prec > num_digit(i) && !v->f_width)))
		oct_help9(v, i);
	else if (v->f_width && v->f_prec && v->c_prec > num_digit(i) \
			&& v->c_width >= v->c_prec)
		oct_help10(v, i);
}

void	oct_help18(t_v *v, long long i)
{
	if (v->flag_hash && v->c_prec <= num_digit(i))
		buffadd_string(v, "0");
	if (!v->f_prec || (v->f_prec && v->c_prec <= num_digit(i)))
		oct_help1(v, i);
	else if ((v->f_prec && v->c_prec > num_digit(i) \
				&& v->f_width && v->c_prec > v->c_width) \
			|| ((v->f_prec && v->c_prec > num_digit(i) && !v->f_width)))
		oct_help12(v, i);
	else if (v->f_width && v->f_prec && v->c_prec > num_digit(i) \
			&& v->c_width >= v->c_prec)
		oct_help13(v, i);
	if (v->flag_hash && v->c_prec <= num_digit(i) && v->f_width && v->f_prec)
		oct_help14(v, i);
	else if (!v->flag_hash && v->c_prec <= num_digit(i) \
			&& v->f_width && v->f_prec)
		oct_help15(v, i);
	else if (v->flag_hash && v->f_width && !v->f_prec)
		oct_help6(v, i);
	else if (!v->flag_hash && v->f_width && !v->f_prec)
		oct_help16(v, i);
}
