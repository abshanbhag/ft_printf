/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:16:49 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/19 13:06:03 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*dec_to_hexa(t_v *v, unsigned long long n, char str)
{
	char	hexa_deci_num[17];
	int		i;
	int		rem;
	char	*hex;

	if (n == 0)
		return (dec_to_hexa_prp(v));
	hex = (char *)malloc(sizeof(char) * 17);
	ft_bzero(&hexa_deci_num, 17);
	ft_bzero(hex, 17);
	i = 0;
	while (n != 0)
	{
		rem = n % 16;
		if (rem < 10)
		{
			hexa_deci_num[i++] = rem + '0';
		}
		else
		{
			hexa_deci_num[i++] = (rem - 10) + str;
		}
		n = n / 16;
	}
	return (dec_to_hexa_e(hex, hexa_deci_num, i));
}

char		*dec_to_hexa_prp(t_v *v)
{
	if (v->gv)
		return (ft_strdup(""));
	else
		return (ft_strdup("0"));
}

char		*dec_to_hexa_e
	(char *hex, char *hexa_deci_num, int i)
{
	int o;

	o = 0;
	while (i > 0)
	{
		hex[o] = hexa_deci_num[i - 1];
		i--;
		o++;
	}
	return (hex);
}

int			num_float(long double i)
{
	char	*s;
	int		num;

	num = 0;
	s = ft_ldtoa(i);
	while (s[num] != '\0')
		num++;
	free(s);
	return (num);
}

void		lwidth_m_dig4(t_v *v, long long i)
{
	while (v->c_width - num_digit(i) > 4)
		spz_width(v);
}
