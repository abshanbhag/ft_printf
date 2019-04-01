/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:58:41 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/21 16:37:29 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_help4(t_v *v, unsigned long long i)
{
	cprec_m_dig0(v, i);
	u_help1(v, i);
	if (v->f_width && v->c_width > v->c_prec)
	{
		if (!v->h_fl && !v->hh_fl)
			width_m_prec2(v);
		else
			width_m_prec3(v);
	}
}

void	u_help5(t_v *v, unsigned long long i)
{
	u_help1(v, i);
	if (v->l_fl || v->ll_fl)
		lwidth_m_dig0(v, i);
}

void	oct_help1(t_v *v, long long i)
{
	char *tmp;

	tmp = ft_lltoa_base(i, 8, 'A');
	buffadd_string(v, tmp);
	free(tmp);
}

void	oct_help2(t_v *v, long long i)
{
	if (v->flag_zero)
	{
		while (v->c_width - (num_digit(i) + 1) > 1)
		{
			buffadd_string(v, "0");
			v->c_width--;
		}
	}
	else
	{
		while (v->c_width - (num_digit(i) + 1) > 1)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
}

void	oct_help3(t_v *v, long long i)
{
	if (v->flag_zero)
	{
		while (v->c_width - (num_digit(i) + 1) > 0)
		{
			buffadd_string(v, "0");
			v->c_width--;
		}
	}
	else
	{
		while (v->c_width - (num_digit(i) + 1) > 0)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
}
