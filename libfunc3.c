/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:52:38 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/18 14:50:48 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lltoa_isnegative(long long *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_lltoa(long long n)
{
	char	*str;
	char	*t;
	char	*u;
	int		i;

	str = malloc(30);
	t = str;
	if (n < 0)
		*t++ = '-';
	if (n > 0)
		n = -n;
	if (n <= -10)
	{
		u = ft_lltoa(-(n / 10));
		i = 0;
		while (u[i])
			*t++ = u[i++];
		free(u);
	}
	*t = '0' - n % 10;
	*(t + 1) = '\0';
	return (str);
}

char	*ft_lltoa_u(unsigned long long n)
{
	unsigned long long		tmpn;
	unsigned int			len;
	unsigned int			negative;
	char					*str;

	tmpn = n;
	len = 2;
	negative = 0;
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_lltoa_base(unsigned long value, int base, char up)
{
	char			*s;
	unsigned long	n;
	int				sign;
	int				i;

	n = value;
	sign = 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + up - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char	*ft_ldtoa(long double n)
{
	char	*first;
	size_t	len;
	int		neg;

	neg = (n < 0) ? 1 : 0;
	if ((long long)n == 0)
		return (low_carb_potato(n, neg));
	first = ft_lltoa((long long)n);
	if (neg)
		first = str_chop2(first, 1);
	len = ft_strlen(first);
	if (len > 1 && len < 19)
		n = potato_magic(n, first, len);
	else if (len == 19)
	{
		free(first);
		first = ft_lltoa((long long)(n / 10));
		return (potato_supreme(n, first, neg));
	}
	n *= ft_pow(10, 7);
	return (!n ? first : mighty_potato(n, first, len, neg));
}
