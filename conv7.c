/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:40:19 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/18 14:52:56 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lwidth_m_dig2(t_v *v, long long i)
{
	while (v->c_width - num_digit(i) > 2)
		spz_width(v);
}

void	hex_help5(t_v *v, unsigned long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while ((v->c_width - v->c_prec) > -1)
			spz_width(v);
	}
	else if (v->h_fl || v->hh_fl)
	{
		while ((v->c_width - (v->c_prec + num_digit(i))) > 4)
			spz_width(v);
	}
	else
		lwidth_m_dig2(v, i);
}

void	hex_help6(t_v *v, unsigned long long i)
{
	if (v->l_fl || v->ll_fl)
	{
		while ((v->c_width - (v->c_prec + num_digit(i))) > -3)
			spz_width(v);
	}
	else if (v->h_fl || v->hh_fl)
	{
		while ((v->c_width - (v->c_prec + num_digit(i))) > 6)
			spz_width(v);
	}
	else
		lwidth_m_dig4(v, i);
}

char	*bdecp(long double i)
{
	char	*str;
	char	*s;
	int		len;
	int		j;

	s = ft_ldtoa(i);
	len = ft_strlen(ft_strlenc(s, '.') + s + 1);
	j = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (s[j] != '.' && s[j] != '\0')
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}

char	*adecp(long double i)
{
	char	*str;
	char	*s;
	int		len;
	int		j;
	int		k;

	s = ft_ldtoa(i);
	len = ft_strlen(ft_strlenc(s, '.') + s);
	j = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * (len));
	while (s[j] != '.')
		j++;
	j++;
	while (s[j] != '\0')
	{
		str[k] = s[j];
		j++;
		k++;
	}
	str[k] = '\0';
	free(s);
	return (str);
}
