/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:50:03 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/22 08:54:37 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_help1(t_v *v, long long i)
{
	char *tmp;

	tmp = ft_lltoa(i);
	buffadd_string(v, tmp);
	free(tmp);
}

void	int_help2(t_v *v, long long i)
{
	if (i >= 0 && v->flag_plus && !v->flag_neg)
		buffadd_string(v, "+");
	if (v->flag_space && i >= 0)
		buffadd_string(v, " ");
	int_help1(v, i);
}

void	hex_help14(t_v *v, unsigned long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while (v->c_width - num_digit(i) > -3)
			spz_width(v);
	}
	if (num_digit(i) < 5)
		lwidth_m_dig0(v, i);
	else
		lwidth_m_digm1(v, i);
}

void	hex_help15(t_v *v, unsigned long long i)
{
	if (v->l_fl || v->ll_fl)
		lwidth_m_digm1(v, i);
	else
		lwidth_m_dig2(v, i);
	hex_help4(v, i);
}

void	cprec_m_dig0(t_v *v, long long i)
{
	while ((v->c_prec - num_digit(i)) > 0)
		spz_prec(v);
}
