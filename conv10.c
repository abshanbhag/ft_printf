/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:44:03 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/21 14:22:37 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_help7(t_v *v, unsigned long long i)
{
	char	*tmp;

	if (v->x_s)
		tmp = dec_to_hexa(v, i, 'a');
	else
		tmp = dec_to_hexa(v, i, 'A');
	if (!(v->f_prec && !v->c_prec && i == 0))
		buffadd_string(v, tmp);
	free(tmp);
}

void	hex_help8(t_v *v, unsigned long long i)
{
	if (!(i == 0 && v->f_prec))
		hex_help7(v, i);
	else
		buffadd_string(v, "");
}

void	hex_help9(t_v *v, unsigned long long i)
{
	if (v->flag_hash && v->f_width)
		hex_help4(v, i);
	while ((v->c_prec - num_digit(i)) >= 0)
		spz_prec(v);
	hex_help7(v, i);
}

void	hex_help10(t_v *v, unsigned long long i)
{
	if (!v->flag_hash)
		hex_help2(v, i);
	else
		hex_help3(v, i);
	hex_help7(v, i);
}

void	hex_help11(t_v *v, unsigned long long i)
{
	hex_help1(v, i);
	if (!v->f_prec || (v->f_prec && v->c_prec <= num_digit(i)))
		hex_help8(v, i);
	else if ((v->f_prec && v->c_prec > num_digit(i) && v->f_width && \
				v->c_prec >= v->c_width) || \
			((v->f_prec && v->c_prec > num_digit(i) && !v->f_width)))
		hex_help9(v, i);
	else if (v->f_width && v->f_prec && v->c_prec > num_digit(i) \
			&& v->c_width > v->c_prec)
		hex_help10(v, i);
}
