/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:51:07 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(t_all *s, int x, int y, int color)
{
	char		*dst;

	dst = s->img.addr + (y * s->img.line_length + x * \
		(s->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void			count_lines(t_all *s, char *line)
{
	char		*tmp;

	tmp = ft_strdup(line);
	s->flag.skip = 0;
	ft_lstadd_back(&s->head, ft_lstnew(tmp));
	s->flag.count_line++;
}

static void		ft_color_1(char *line, int *i)
{
	while (line[*i] != '\0')
	{
		if (line[*i] != ' ')
			ft_error(-4);
		(*i)++;
	}
}

int				ft_color(t_all *s, t_tex *color, char *line, int *i)
{
	color->flag_1 = 0;
	(*i)++;
	if (!(s->color.r = ft_atoi_cub(line, i)))
		ft_error(-5);
	skip_space(line, i);
	if (line[*i] != ',')
		ft_error(-5);
	(*i)++;
	if (!(s->color.g = ft_atoi_cub(line, i)))
		ft_error(-5);
	skip_space(line, i);
	if (line[*i] != ',')
		ft_error(-5);
	(*i)++;
	if (!(s->color.b = ft_atoi_cub(line, i)))
		ft_error(-5);
	ft_color_1(line, i);
	if (s->color.r > 255 || s->color.g > 255 || s->color.b > 255)
		ft_error(-5);
	color->rgb = create_rgb(s->color.r, s->color.g, s->color.b);
	s->flag.count++;
	return (0);
}

int				create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
