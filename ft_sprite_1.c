/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:51:07 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			ft_sprite2(t_all *s)
{
	s->point.spr_h = abs((int)(s->win.y / s->point.tform_y));
	s->point.start_y = (s->win.y / 2) - (s->point.spr_h / 2);
	if (s->point.start_y < 0)
		s->point.start_y = 0;
	s->point.end_y = (s->point.spr_h / 2) + (s->win.y / 2);
	if (s->point.end_y >= s->win.y)
		s->point.end_y = s->win.y - 1;
	s->point.spr_w = abs((int)(s->win.x / s->point.tform_y));
	s->point.start_x = -s->point.spr_w / 2 + s->point.spr_screen_x;
	if (s->point.start_x < 0)
	{
		s->point.start_x = 0;
		s->flag.f_spr++;
	}
	s->point.end_x = s->point.spr_w / 2 + s->point.spr_screen_x;
	if (s->point.end_x >= s->win.x)
	{
		s->point.end_x = s->win.x;
		s->flag.f_spr++;
	}
}

void				ft_sprite1(t_all *s, int i)
{
	double			inv_det;

	s->point.spr_x = s->spr[i].x - s->player.x;
	s->point.spr_y = s->spr[i].y - s->player.y;
	inv_det = 1.0 / (s->dir.plane_x * s->dir.y - s->dir.x * s->dir.plane_y);
	s->point.tform_x = inv_det * (s->dir.y * s->point.spr_x - s->dir.x \
		* s->point.spr_y);
	s->point.tform_y = inv_det * (-s->dir.plane_y * s->point.spr_x + \
		s->dir.plane_x * s->point.spr_y);
	s->point.spr_screen_x = (int)((s->win.x / 2) * \
		(1 + s->point.tform_x / s->point.tform_y));
	ft_sprite2(s);
}
