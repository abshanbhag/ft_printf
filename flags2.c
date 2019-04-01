/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:00:04 by ashanbha          #+#    #+#             */
/*   Updated: 2019/02/11 09:01:02 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ht_flag(t_v *v)
{
	v->flag_hash = 1;
	v->format++;
	figure_flags(v);
}

void	pl_flag(t_v *v)
{
	v->flag_plus = 1;
	v->format++;
	figure_flags(v);
}

void	sp_flag(t_v *v)
{
	v->flag_space = 1;
	v->format++;
	figure_flags(v);
}

void	min_flag(t_v *v)
{
	v->flag_minus = 1;
	v->format++;
	figure_flags(v);
}

void	z_flag(t_v *v)
{
	v->flag_zero = 1;
	v->format++;
	figure_flags(v);
}
