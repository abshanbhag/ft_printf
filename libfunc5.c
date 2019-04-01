/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:45:32 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/11 14:47:59 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	str = b;
	i = 0;
	while (i < len)
		str[i++] = c;
	return (str);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem == NULL ? NULL : mem);
}
