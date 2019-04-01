/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 08:51:25 by ashanbha          #+#    #+#             */
/*   Updated: 2019/02/04 08:52:39 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		a;
	int		slen;
	char	*copy;

	slen = 0;
	while (s1[slen])
		slen++;
	copy = (char*)malloc(slen + 1);
	if (copy != NULL)
	{
		a = 0;
		while (s1[a])
		{
			copy[a] = s1[a];
			a++;
		}
		copy[a] = '\0';
	}
	return (copy);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strlenc(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
