/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:40:21 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/21 18:06:10 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_help9(t_v *v, long long i)
{
	if (v->f_width && v->c_width < num_digit(i))
	{
		while ((v->c_prec - num_digit(i)) > 1)
		{
			buffadd_string(v, "0");
			v->c_prec--;
		}
	}
	else
	{
		while ((v->c_prec - num_digit(i)) > 0)
		{
			buffadd_string(v, "0");
			v->c_prec--;
		}
	}
	oct_help1(v, i);
}

void	oct_help10(t_v *v, long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while ((v->c_width - v->c_prec) > 1)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
	else
	{
		while ((v->c_width - v->c_prec) > 0)
		{
			buffadd_string(v, " ");
			v->c_width--;
		}
	}
	while ((v->c_prec - num_digit(i)) > 0)
	{
		buffadd_string(v, "0");
		v->c_prec--;
	}
	oct_help1(v, i);
}

void	oct_help11(t_v *v, long long i)
{
	oct_help6(v, i);
	buffadd_string(v, "0");
}

void	oct_help12(t_v *v, long long i)
{
	while ((v->c_prec - num_digit(i)) > 0)
	{
		buffadd_string(v, "0");
		v->c_prec--;
	}
	oct_help1(v, i);
}

void	oct_help13(t_v *v, long long i)
{
	while ((v->c_prec - num_digit(i)) > 0)
	{
		buffadd_string(v, "0");
		v->c_prec--;
	}
	oct_help1(v, i);
	oct_help3(v, i);
}
