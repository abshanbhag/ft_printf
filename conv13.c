/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:43:22 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/22 08:48:44 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_help4(t_v *v, long long i)
{
	if (v->flag_zero)
	{
		while (v->c_width - num_digit(i) > 1)
		{
			buffadd_string(v, "0");
			v->c_width--;
		}
	}
	else
	{
		while (v->c_width - num_digit(i) > 1)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
}

void	oct_help5(t_v *v, long long i)
{
	if (v->flag_zero)
	{
		while (v->c_width - num_digit(i) > 0)
		{
			buffadd_string(v, "0");
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

void	oct_help6(t_v *v, long long i)
{
	if (v->l_fl || v->ll_fl)
		oct_help2(v, i);
	else
		oct_help3(v, i);
}

void	oct_help7(t_v *v, long long i)
{
	if (v->l_fl || v->ll_fl)
		oct_help4(v, i);
	else
		oct_help5(v, i);
}

void	oct_help8(t_v *v, long long i)
{
	if (i != 0)
	{
		while (v->c_width - num_digit(i) > 1)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
	else
	{
		while (v->c_width - 0 > 0)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
}
