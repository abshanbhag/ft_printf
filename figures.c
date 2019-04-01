/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:05:50 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/22 08:47:43 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	figure_flags(t_v *v)
{
	if (*v->format == '#')
		ht_flag(v);
	else if (*v->format == ' ')
		sp_flag(v);
	else if (*v->format == '-')
		min_flag(v);
	else if (*v->format == '+')
		pl_flag(v);
	else if (*v->format == '0')
		z_flag(v);
	else
		figure_width(v);
}

void	figure_width(t_v *v)
{
	char	widchar[10];
	int		i;

	if (*v->format >= '0' && *v->format <= '9')
	{
		ft_bzero(widchar, sizeof(widchar));
		i = 0;
		while (*v->format >= '0' && *v->format <= '9')
		{
			v->f_width = 1;
			widchar[i++] = *v->format;
			v->format++;
		}
		v->c_width = ft_atoi(widchar);
	}
	figure_precision(v);
}

void	figure_precision(t_v *v)
{
	char	precchar[10];
	int		i;

	if (*v->format == '.')
	{
		v->f_prec = 1;
		ft_bzero(precchar, sizeof(precchar));
		i = 0;
		v->format++;
		while (*v->format >= '0' && *v->format <= '9')
		{
			precchar[i++] = *v->format;
			v->format++;
		}
		v->c_prec = ft_atoi(precchar);
	}
	flags(v);
}

void	flags(t_v *v)
{
	if (*v->format == 'h')
	{
		v->format++;
		if (*v->format == 'h')
			hh_flag(v);
		else
			h_flag(v);
	}
	else if (*v->format == 'l')
	{
		v->format++;
		if (*v->format == 'l')
			ll_flag(v);
		else
			l_flag(v);
	}
	else if (*v->format == 'L')
	{
		v->format++;
		lc_flag(v);
	}
	else
		no_flag(v);
}
