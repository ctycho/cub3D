/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:43:50 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 21:56:12 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			ft_sprite3(t_all *s, int y, int tex_x, int stripe, t_tex spr)
{
	int				d;
	int				tex_y;
	unsigned int	*color;

	d = y * 256 - s->win.y * 128 + s->point.spr_h * 128;
	tex_y = ((d * spr.height) / s->point.spr_h) / 256;
	// if (tex_y >= spr.height)
	// 	tex_y = spr.height - 1;
	// if (tex_y < 0)
	// 	tex_y = 0;
	// if (tex_x >= spr.width)
	// 	tex_x = spr.width - 1;
	// if (tex_x < 0)
	// 	tex_x = 0;
	color = (unsigned int *)(spr.addr + tex_y * \
		spr.line_length + \
		tex_x * spr.bpp / 8);
	if (*(unsigned int*)color != 0x00000000)
		my_mlx_pixel_put(s, stripe, y, *(unsigned int*)color);
}

static void			ft_sprite2(t_all *s, t_tex spr)
{
	int				stripe;
	int				tex_x;
	int				y;
	double			sprite_dist;

	stripe = s->point.start_x;
	y = 0;
	while (stripe < s->point.end_x)
	{
		tex_x = (int)((256 * (stripe - (-s->point.spr_w / 2 + \
			s->point.spr_screen_x)) * \
			spr.width / s->point.spr_w) / 256);
		if (s->point.tform_y > 0 && stripe > 0 && stripe < s->win.x && s->point.tform_y < s->point.buf[stripe])
		{
			y = s->point.start_y;
			while (y < s->point.end_y)
			{
				ft_sprite3(s, y, tex_x, stripe, spr);
				y++;
			}
		}
		stripe++;
	}

}

static void			ft_sprite1(t_all *s, int i)
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
	s->point.spr_h = abs((int)(s->win.y / s->point.tform_y));
	// printf("height %d\n", s->point.spr_h);
	s->point.start_y = (s->win.y / 2) - (s->point.spr_h / 2);
	if (s->point.start_y < 0)
		s->point.start_y = 0;
	s->point.end_y = (s->point.spr_h / 2) + (s->win.y / 2);
	if (s->point.end_y >= s->win.y)
		s->point.end_y = s->win.y - 1;
	s->point.spr_w = abs((int)(s->win.x / s->point.tform_y)); //here
	// printf("width %d\n", s->point.spr_w);
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

	// printf("%d\n", s->point.end_x);
	// if (s->point.start_x < 0)
	// {
	// 	s->point.start_x = 0;
	// 	s->flag.f_spr++;
	// }
	// if (s->point.end_x >= s->win.x)
	// {
	// 	s->point.end_x = s->win.x - 1;
	// 	s->flag.f_spr++;
	// }
}

static void			sort_sprites(t_all *s)
{
	int				i;
	t_spr			tmp;

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
	unsigned int	*color;
	int				i;

	i = -1;
	while (++i < s->point.count)
	{
		s->spr[i].dist = ((s->player.x - s->spr[i].x) * (s->player.x \
			- s->spr[i].x) + (s->player.y - s->spr[i].y) * \
			(s->player.y - s->spr[i].y));
	}
	sort_sprites(s);
	i = -1;
	while (++i < s->point.count)
	{
		s->flag.f_spr = 0;
		ft_sprite1(s, i);
		if (s->flag.f_spr == 2 && s->spr[i].dist > 1)
		{
			continue;
		}
		else
		{
			if (s->spr[i].type == '2')
				ft_sprite2(s, s->comp.sprite);
			else if (s->spr[i].type == '3')
				ft_sprite2(s, s->comp.sprite1);
		}
	}
}


// static void			ft_sprite4(t_all *s, int y, int st, t_tex spr)
// {
// 	int				d;
// 	unsigned int	*color;

// 	d = y * 256 - s->win.y * 128 + s->point.spr_h * 128;
// 	spr.tex_y = ((d * spr.height) / s->point.spr_h) / 256;
// 	if (spr.tex_y >= spr.height)
// 		spr.tex_y = spr.height - 1;
// 	if (spr.tex_y < 0)
// 		spr.tex_y = 0;
// 	if (spr.tex_x >= spr.width)
// 		spr.tex_x = spr.width - 1;
// 	if (spr.tex_x < 0)
// 		spr.tex_x = 0;
// 	color = (unsigned int *)(spr.addr + spr.tex_y * \
// 		spr.line_length + \
// 		spr.tex_x * spr.bpp / 8);
// 	if (*(unsigned int*)color != 0x00000000)
// 		my_mlx_pixel_put(s, st, y, *(unsigned int*)color);
// }

// static void			ft_sprite3(t_all *s, t_tex spr)
// {
// 	int				stripe;
// 	int				y;
// 	double			sprite_dist;

// 	stripe = s->point.start_x;
// 	y = 0;
// 	while (stripe < s->point.end_x)
// 	{
// 		spr.tex_x = (int)((256 * (stripe - (-s->point.spr_w / 2 + \
// 			s->point.spr_screen_x)) * \
// 			spr.width / s->point.spr_w) / 256);
// 		if (s->point.tform_y > 0 && stripe > 0 && stripe < s->win.x \
// 			&& s->point.tform_y < s->point.buf[stripe])
// 		{
// 			y = s->point.start_y;
// 			while (y < s->point.end_y)
// 			{
// 				ft_sprite4(s, y, stripe, spr);
// 				y++;
// 			}
// 		}
// 		stripe++;
// 	}
// }

// static void			sort_sprites(t_all *s)
// {
// 	int				i;
// 	t_spr			tmp;

// 	i = 0;
// 	while (i < s->point.count)
// 	{
// 		s->spr[i].dist = ((s->player.x - s->spr[i].x) * (s->player.x \
// 			- s->spr[i].x) + (s->player.y - s->spr[i].y) * \
// 			(s->player.y - s->spr[i].y));
// 		i++;
// 	}
// 	i = 0;
// 	while (i < s->point.count)
// 	{
// 		if (s->spr[i].dist < s->spr[i + 1].dist)
// 		{
// 			tmp = s->spr[i];
// 			s->spr[i] = s->spr[i + 1];
// 			s->spr[i + 1] = tmp;
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// }

// void				ft_sprite(t_all *s)
// {
// 	unsigned int	*color;
// 	int				i;

// 	i = -1;
// 	sort_sprites(s);
// 	while (++i < s->point.count)
// 	{
// 		s->flag.f_spr = 0;
// 		ft_sprite1(s, i);
// 		if (s->flag.f_spr == 2 && s->spr[i].dist > 0.92)
// 			continue;
// 		else
// 		{
// 			if (s->spr[i].type == '2')
// 				ft_sprite3(s, s->comp.sprite);
// 			else if (s->spr[i].type == '3')
// 				ft_sprite3(s, s->comp.sprite1);
// 		}
// 	}
// }
