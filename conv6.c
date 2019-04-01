/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:35:58 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/22 08:56:48 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_help1(t_v *v, unsigned long long i)
{
	if (v->flag_hash && v->flag_zero && (v->f_width > v->f_prec))
		hex_help4(v, i);
	if (v->flag_hash && !v->f_width && !v->flag_zero)
		hex_help4(v, i);
	if (v->c_prec <= num_digit(i) && v->f_width)
	{
		if (!v->flag_hash)
			hex_help14(v, i);
		else
			hex_help15(v, i);
	}
}

void	hex_help2(t_v *v, unsigned long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while ((v->c_width - v->c_prec) > -1)
			spz_width(v);
	}
	else
		width_m_prec(v);
	while ((v->c_prec - num_digit(i)) > -1)
		spz_prec(v);
}

void	hex_help3(t_v *v, unsigned long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while ((v->c_width - (v->c_prec + num_digit(i))) > -3)
			spz_width(v);
	}
	else
	{
		while ((v->c_width - v->c_prec) > 2)
			spz_width(v);
	}
	hex_help4(v, i);
	while ((v->c_prec - num_digit(i)) > -1)
		spz_prec(v);
}

void	hex_help4(t_v *v, unsigned long long i)
{
	if ((i > 0) || (i == 0 && v->flag_zero))
	{
		if (!v->c_i)
		{
			if (v->x_l)
				buffadd_string(v, "0X");
			else
				buffadd_string(v, "0x");
		}
	}
	v->c_i = 1;
}

int		flt_decp(long double i)
{
	char	*s;
	int		j;

	j = 0;
	s = ft_ldtoa(i);
	while (s[j] != '\0')
	{
		if (s[j] == '.')
		{
			free(s);
			return (1);
		}
		j++;
	}
	free(s);
	return (0);
}
