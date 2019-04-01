/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:31:46 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/29 11:37:32 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_space(t_v *v)
{
	if (v->f_width)
	{
		while ((v->c_width - 1) > 0)
			spz_width(v);
	}
}

void	print_strspace(t_v *v, char *str)
{
	while ((v->c_width - ft_strlen(str)) > 0)
		spz_width(v);
}

void	print_strchar(t_v *v, char *str)
{
	int i;

	i = 0;
	while (v->c_prec - i > 0 && str[i])
	{
		write(1, &str[i++], 1);
		v->a++;
	}
}

void	width_m_prec(t_v *v)
{
	while ((v->c_width - v->c_prec) > 0)
		spz_width(v);
}

void	width_m_prec2(t_v *v)
{
	while ((v->c_width - v->c_prec) > 2)
		spz_width(v);
}
