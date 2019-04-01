/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:33:23 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/21 15:31:44 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_help12(t_v *v, unsigned long long i)
{
	while ((v->c_prec - num_digit(i)) > -1)
		spz_prec(v);
	hex_help7(v, i);
}

void	hex_help13(t_v *v, unsigned long long i)
{
	v->flag_zero = 0;
	if (v->flag_hash)
		hex_help4(v, i);
	if (!v->f_prec || (v->f_prec && v->c_prec <= num_digit(i)))
		hex_help7(v, i);
	hex_help1(v, i);
	if ((v->f_prec && v->c_prec > num_digit(i) && v->f_width && \
				v->c_prec >= v->c_width) || \
			((v->f_prec && v->c_prec > num_digit(i) && !v->f_width)))
		hex_help12(v, i);
	else if (v->f_width && v->f_prec && v->c_prec > num_digit(i) \
			&& v->c_width > v->c_prec)
	{
		hex_help12(v, i);
		if (!v->flag_hash)
			hex_help5(v, i);
		else
			hex_help6(v, i);
	}
}

void	u_help1(t_v *v, unsigned long long i)
{
	char	*tmp;

	tmp = ft_lltoa_u(i);
	buffadd_string(v, tmp);
	free(tmp);
}

void	u_help2(t_v *v, unsigned long long i)
{
	if (v->c_width > num_digit(i))
		lwidth_m_dig0(v, i);
}

void	u_help3(t_v *v, unsigned long long i)
{
	if (v->f_width && (v->c_prec <= num_digit(i)))
		u_help2(v, i);
	if ((!v->f_prec && !v->f_width) || \
			(v->f_prec && v->c_prec <= num_digit(i)) || \
			(v->f_width && v->c_width <= num_digit(i)))
	{
		if (v->f_prec && v->c_prec == 0 && i == 0)
			buffadd_string(v, "");
		else
		{
			if (v->c_prec > v->c_width)
			{
				while (v->c_prec - num_digit(i) > 0)
					spz_prec(v);
			}
			u_help1(v, i);
		}
	}
	else if (v->f_prec && v->c_prec > num_digit(i))
	{
		if (v->f_width && v->c_width > v->c_prec)
			width_m_prec(v);
		cprec_m_dig0(v, i);
		u_help1(v, i);
	}
}
