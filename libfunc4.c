/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:05:25 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/11 14:39:40 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*insert_c(char *s1, char c, unsigned long long n)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst = ft_strdup(s1);
	free(s1);
	s1 = malloc(ft_strlen(dst) + 2);
	while (i < (size_t)ft_strlen(dst) + 1)
	{
		if (i == n)
		{
			s1[j++] = c;
			s1[j++] = dst[i++];
		}
		else
			s1[j++] = dst[i++];
	}
	s1[j] = '\0';
	free(dst);
	return (s1);
}

char		*replace_c(char *s1, char c, unsigned long long n)
{
	char	*dst;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	dst = malloc(ft_strlen(s1) + 1);
	while (i < (size_t)ft_strlen(s1))
	{
		if (i == n)
		{
			dst[j++] = c;
			i++;
		}
		else
			dst[j++] = s1[i++];
	}
	dst[j] = '\0';
	free(s1);
	s1 = ft_strdup(dst);
	free(dst);
	return (s1);
}

long double	ft_pow(long double base, long double ex)
{
	long double	res;

	res = 1;
	while (ex-- != 0)
		res *= base;
	return (res);
}

char		*str_chop(char *str, int n)
{
	char	*pork;
	int		len;

	len = ft_strlen(str) - n;
	if (!len)
	{
		pork = ft_memalloc(1);
		return (pork);
	}
	pork = malloc(len + 1);
	pork[len] = '\0';
	while (len--)
		pork[len] = str[len];
	return (pork);
}

char		*str_chop2(char *str, int n)
{
	char	*pork;
	int		i;

	i = -1;
	if (ft_strlen(str) - n <= 0)
		return (NULL);
	pork = malloc(ft_strlen(str) - n + 1);
	pork[ft_strlen(str) - n] = '\0';
	while (++i < (int)ft_strlen(str) - n)
		pork[i] = str[i + n];
	free(str);
	str = ft_strdup(pork);
	free(pork);
	return (str);
}
