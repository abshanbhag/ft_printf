/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:04:55 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/29 11:39:15 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	figure_colors(t_v *v)
{
	char	color[MAX_COLOR_SIZE];
	int		c_index;

	c_index = 0;
	ft_bzero(&color, MAX_COLOR_SIZE);
	while (*v->format != '{' && *v->format != '}' &&\
			*v->format && c_index < MAX_COLOR_SIZE)
	{
		color[c_index++] = *v->format++;
	}
	if (*v->format == '}')
		figure_actual_color(v, color);
	else
		figure_not_color(v);
}

void	buffadd_string(t_v *v, char *str)
{
	while (*str)
	{
		write(1, str++, 1);
		v->a++;
	}
}

void	figure_not_color(t_v *v)
{
	v->format--;
	while (*v->format != '{')
		v->format--;
	buffadd_string(v, "{");
}

int		ft_strncmpcolor(const char *col1, const char *col2)
{
	size_t i;

	i = 0;
	while (i < MAX_COLOR_SIZE)
	{
		if (col1[i] == '\0' && col2[i] == '\0')
			return (1);
		if (col1[i] != col2[i])
			return (0);
		i++;
	}
	return (0);
}

void	figure_actual_color(t_v *v, char *color)
{
	if (ft_strncmpcolor(color, "black"))
		buffadd_string(v, COL_BLACK);
	else if (ft_strncmpcolor(color, "red"))
		buffadd_string(v, COL_RED);
	else if (ft_strncmpcolor(color, "green"))
		buffadd_string(v, COL_GREEN);
	else if (ft_strncmpcolor(color, "yellow"))
		buffadd_string(v, COL_YELLOW);
	else if (ft_strncmpcolor(color, "blue"))
		buffadd_string(v, COL_BLUE);
	else if (ft_strncmpcolor(color, "purple"))
		buffadd_string(v, COL_PURPLE);
	else if (ft_strncmpcolor(color, "cyan"))
		buffadd_string(v, COL_CYAN);
	else if (ft_strncmpcolor(color, "white"))
		buffadd_string(v, COL_WHITE);
	else if (ft_strncmpcolor(color, "eoc"))
		buffadd_string(v, COL_RESET);
	else
		figure_not_color(v);
}
