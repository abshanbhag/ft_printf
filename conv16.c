/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 09:09:29 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/22 10:46:54 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_help3(t_v *v, long long i)
{
	lwidth_m_dig0(v, i);
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

void	int_help4(t_v *v, long long i)
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
	lwidth_m_dig0(v, i);
	if (i != 0 || v->flag_plus)
		int_help1(v, i);
}

void	int_help5(t_v *v, long long i)
{
	if (v->c_width <= num_digit(i))
		int_help2(v, i);
	else if (v->c_width > num_digit(i))
	{
		if (!v->flag_zero)
			int_help3(v, i);
		else
			int_help4(v, i);
	}
}

void	int_help6(t_v *v, long long i)
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
	if (i == 0)
		buffadd_string(v, "");
	else
		int_help1(v, i);
}

void	int_help7(t_v *v, long long i)
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
	while ((v->c_prec - num_digit(i)) > 0 && i >= 0)
	{
		buffadd_string(v, "0");
		v->c_prec--;
	}
	int_help1(v, i);
}
