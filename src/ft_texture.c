/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:51:07 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_wall4(t_all *s)
{
	if (s->hit.side == 0)
		s->ray.perp_wall_dist = (s->map.map_x - s->player.x + \
			(1 - s->ray.step_x) / 2) / s->ray.x;
	else
		s->ray.perp_wall_dist = (s->map.map_y - s->player.y + \
			(1 - s->ray.step_y) / 2) / s->ray.y;
	s->tex.line_h = (int)(s->win.y / s->ray.perp_wall_dist);
	s->ray.draw_start = (s->win.y / 2) - (s->tex.line_h / 2);
	if (s->ray.draw_start < 0)
		s->ray.draw_start = 0;
	s->ray.draw_end = (s->tex.line_h / 2) + (s->win.y / 2);
	if (s->ray.draw_end >= s->win.y)
		s->ray.draw_end = s->win.y - 1;
	if (s->hit.side == 0)
		s->tex.wall_x = s->player.y + s->ray.perp_wall_dist * s->ray.y;
	else
		s->tex.wall_x = s->player.x + s->ray.perp_wall_dist * s->ray.x;
	s->tex.wall_x -= floor((s->tex.wall_x));
	s->tex.tex_x = (int)(s->tex.wall_x * (double)s->comp.north.width);
	if (s->hit.side == 0 && s->ray.x > 0)
		s->tex.tex_x = s->comp.north.width - s->tex.tex_x - 1;
	if (s->hit.side == 1 && s->ray.y < 0)
		s->tex.tex_x = s->comp.north.width - s->tex.tex_x - 1;
}

void				ft_wall3(t_all *s)
{
	int				hit;

	hit = 0;
	while (hit == 0)
	{
		if (s->ray.side_dist_x < s->ray.side_dist_y)
		{
			s->ray.side_dist_x += s->ray.delta_dist_x;
			s->map.map_x += s->ray.step_x;
			s->hit.side = 0;
		}
		else
		{
			s->ray.side_dist_y += s->ray.delta_dist_y;
			s->map.map_y += s->ray.step_y;
			s->hit.side = 1;
		}
		if (s->map.world[s->map.map_x][s->map.map_y] == '1')
			hit = 1;
	}
}

void				ft_wall2(t_all *s)
{
	if (s->ray.x < 0)
	{
		s->ray.step_x = -1;
		s->ray.side_dist_x = (s->player.x - s->map.map_x) * s->ray.delta_dist_x;
	}
	else
	{
		s->ray.step_x = 1;
		s->ray.side_dist_x = (s->map.map_x + 1.0 - s->player.x) * \
			s->ray.delta_dist_x;
	}
	if (s->ray.y < 0)
	{
		s->ray.step_y = -1;
		s->ray.side_dist_y = (s->player.y - s->map.map_y) * s->ray.delta_dist_y;
	}
	else
	{
		s->ray.step_y = 1;
		s->ray.side_dist_y = (s->map.map_y + 1.0 - s->player.y) * \
			s->ray.delta_dist_y;
	}
}

static void			ft_wall1(t_all *s, int x)
{
	double camera_x;

	camera_x = 2 * x / (double)s->win.x - 1;
	s->ray.x = s->dir.x + s->dir.plane_x * camera_x;
	s->ray.y = s->dir.y + s->dir.plane_y * camera_x;
	s->map.map_x = (int)s->player.x;
	s->map.map_y = (int)s->player.y;
	s->ray.delta_dist_x = sqrt(1 + \
		(s->ray.y * s->ray.y) / (s->ray.x * s->ray.x));
	s->ray.delta_dist_y = sqrt(1 + \
		(s->ray.x * s->ray.x) / (s->ray.y * s->ray.y));
}

void				ft_wall(t_all *s)
{
	int		x;
	int		y;

	x = 1;
	y = 0;
	while (x < s->win.x)
	{
		ft_wall1(s, x);
		ft_wall2(s);
		ft_wall3(s);
		ft_wall4(s);
		s->ray.step = 1.0 * s->comp.north.height / s->tex.line_h;
		s->ray.tex_pos = (s->ray.draw_start - s->win.y / 2 + \
			s->tex.line_h / 2) * s->ray.step;
		y = 0;
		while (y < s->win.y)
		{
			wall_height(s, x, y);
			y++;
		}
		s->point.buf[x] = s->ray.perp_wall_dist;
		x++;
	}
}
