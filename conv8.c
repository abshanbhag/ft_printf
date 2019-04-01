/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:51:45 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/18 15:02:26 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_help1(t_v *v, char *str)
{
	if (!v->flag_minus)
	{
		if (v->c_prec > ft_strlen(str))
			print_strspace(v, str);
		print_strchar(v, str);
	}
	else
	{
		print_strchar(v, str);
		if (v->c_prec > ft_strlen(str))
			print_strspace(v, str);
	}
}

void	s_help2(t_v *v, char *str)
{
	if (!v->flag_minus)
	{
		if (v->c_prec > ft_strlen(str))
			print_strspace(v, str);
		else if (v->c_prec <= ft_strlen(str))
			width_m_prec(v);
		print_strchar(v, str);
	}
	else if (v->flag_minus)
	{
		print_strchar(v, str);
		if (v->c_prec > ft_strlen(str))
			print_strspace(v, str);
		else if (v->c_prec <= ft_strlen(str))
			width_m_prec(v);
	}
}

void	s_help3(t_v *v, char *str)
{
	if (!v->flag_minus)
	{
		if (v->c_width > ft_strlen(str))
			print_strspace(v, str);
		buffadd_string(v, str);
	}
	else if (v->flag_minus)
	{
		buffadd_string(v, str);
		if (v->c_width > ft_strlen(str))
			print_strspace(v, str);
	}
}

int		ft_min(int x, int y)
{
	return (x < y ? x : y);
}

void	width_m_prec3(t_v *v)
{
	while ((v->c_width - v->c_prec) > 6)
		spz_width(v);
}
