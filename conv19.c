/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv19.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:20:21 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/26 16:19:00 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

void	flt_help15(t_v *v, long double i)
{
	int		ff;

	ff = 0;
	while (v->c_prec - (num_float(i) - num_digit(i)) > ff)
	{
		buffadd_string(v, "0");
		ff++;
	}
}

void	flt_help16(t_v *v, long double i)
{
	char	*tmp;

	tmp = ft_ldtoa(i);
	if (flt_decp(i))
		addstrtobuff(v, tmp, v->c_prec);
	else if (!flt_decp(i))
		flt_help2(v, i);
	free(tmp);
}
