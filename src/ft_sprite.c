/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:51:07 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			ft_sprite4(t_all *s, int y, int st, t_tex spr)
{
	int				d;
	unsigned int	*color;

	d = y * 256 - s->win.y * 128 + s->point.spr_h * 128;
	spr.tex_y = ((d * spr.height) / s->point.spr_h) / 256;
	if (spr.tex_y >= spr.height)
		spr.tex_y = spr.height - 1;
	if (spr.tex_y < 0)
		spr.tex_y = 0;
	if (spr.tex_x >= spr.width)
		spr.tex_x = spr.width - 1;
	if (spr.tex_x < 0)
		spr.tex_x = 0;
	color = (unsigned int *)(spr.addr + spr.tex_y * \
		spr.line_length + \
		spr.tex_x * spr.bpp / 8);
	if (*(unsigned int*)color != 0x00000000)
		my_mlx_pixel_put(s, st, y, *(unsigned int*)color);
}

static void			ft_sprite3(t_all *s, t_tex spr)
{
	int				stripe;
	int				y;

	stripe = s->point.start_x;
	y = 0;
	while (stripe < s->point.end_x)
	{
		spr.tex_x = (int)((256 * (stripe - (-s->point.spr_w / 2 + \
			s->point.spr_screen_x)) * \
			spr.width / s->point.spr_w) / 256);
		if (s->point.tform_y > 0 && stripe > 0 && stripe < s->win.x \
			&& s->point.tform_y < s->point.buf[stripe])
		{
			y = s->point.start_y;
			while (y < s->point.end_y)
			{
				ft_sprite4(s, y, stripe, spr);
				y++;
			}
		}
		stripe++;
	}
}

static void			sort_sprites(t_all *s)
{
	int				i;
	t_spr			tmp;

	i = 0;
	while (i < s->point.count)
	{
		s->spr[i].dist = ((s->player.x - s->spr[i].x) * (s->player.x \
			- s->spr[i].x) + (s->player.y - s->spr[i].y) * \
			(s->player.y - s->spr[i].y));
		i++;
	}
	i = 0;
	while (i < s->point.count)
	{
		if (s->spr[i].dist < s->spr[i + 1].dist)
		{
			tmp = s->spr[i];
			s->spr[i] = s->spr[i + 1];
			s->spr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void				ft_sprite(t_all *s)
{
	int				i;

	i = -1;
	sort_sprites(s);
	while (++i < s->point.count)
	{
		s->flag.f_spr = 0;
		ft_sprite1(s, i);
		if (s->flag.f_spr == 2 && s->spr[i].dist > 0.92)
			continue;
		else
		{
			if (s->spr[i].type == '2')
				ft_sprite3(s, s->comp.sprite);
			else if (s->spr[i].type == '3')
				ft_sprite3(s, s->comp.sprite1);
		}
	}
}
