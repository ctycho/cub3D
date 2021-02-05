/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:51:07 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				north_part(t_all *s)
{
	if (s->tex.tex_y >= s->comp.north.height)
		s->tex.tex_y = s->comp.north.height - 1;
	if (s->tex.tex_y < 0)
		s->tex.tex_y = 0;
	if (s->tex.tex_x >= s->comp.north.width)
		s->tex.tex_x = s->comp.north.width - 1;
	if (s->tex.tex_x < 0)
		s->tex.tex_x = 0;
	s->img.src = (unsigned int *)(s->comp.north.addr + s->tex.tex_y * \
		s->comp.north.line_length + s->tex.tex_x * (s->comp.north.bpp / 8));
}

static void				south_part(t_all *s)
{
	if (s->tex.tex_y >= s->comp.north.height)
		s->tex.tex_y = s->comp.north.height - 1;
	if (s->tex.tex_y < 0)
		s->tex.tex_y = 0;
	if (s->tex.tex_x >= s->comp.north.width)
		s->tex.tex_x = s->comp.north.width - 1;
	if (s->tex.tex_x < 0)
		s->tex.tex_x = 0;
	s->img.src = (unsigned int *)(s->comp.south.addr + s->tex.tex_y * \
		s->comp.south.line_length + s->tex.tex_x * (s->comp.south.bpp / 8));
}

static void				west_part(t_all *s)
{
	if (s->tex.tex_y >= s->comp.north.height)
		s->tex.tex_y = s->comp.north.height - 1;
	if (s->tex.tex_y < 0)
		s->tex.tex_y = 0;
	if (s->tex.tex_x >= s->comp.north.width)
		s->tex.tex_x = s->comp.north.width - 1;
	if (s->tex.tex_x < 0)
		s->tex.tex_x = 0;
	s->img.src = (unsigned int *)(s->comp.west.addr + s->tex.tex_y * \
		s->comp.west.line_length + s->tex.tex_x * (s->comp.west.bpp / 8));
}

static void				east_part(t_all *s)
{
	if (s->tex.tex_y >= s->comp.north.height)
		s->tex.tex_y = s->comp.north.height - 1;
	if (s->tex.tex_y < 0)
		s->tex.tex_y = 0;
	if (s->tex.tex_x >= s->comp.north.width)
		s->tex.tex_x = s->comp.north.width - 1;
	if (s->tex.tex_x < 0)
		s->tex.tex_x = 0;
	s->img.src = (unsigned int *)(s->comp.east.addr + s->tex.tex_y * \
		s->comp.east.line_length + s->tex.tex_x * (s->comp.east.bpp / 8));
}

void					wall_height(t_all *s, int x, int y)
{
	if (y <= s->ray.draw_start)
		my_mlx_pixel_put(s, x, y, s->comp.col_c.rgb);
	else if (y > s->ray.draw_start && y < s->ray.draw_end)
	{
		s->tex.tex_y = (int)s->ray.tex_pos;
		s->ray.tex_pos += s->ray.step;
		if (s->hit.side == 0)
		{
			if (s->ray.step_x < 0)
				north_part(s);
			else if (s->ray.step_x >= 0)
				south_part(s);
		}
		else
		{
			if (s->ray.step_y < 0)
				west_part(s);
			else
				east_part(s);
		}
		my_mlx_pixel_put(s, x, y, *(unsigned int*)s->img.src);
	}
	else
		my_mlx_pixel_put(s, x, y, s->comp.col_f.rgb);
}
