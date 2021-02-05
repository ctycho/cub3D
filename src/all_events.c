/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/02/04 18:05:11 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_rotate(t_all *s, double m)
{
	s->dir.old_dir_x = s->dir.x;
	s->dir.x = s->dir.x * cos(m * ROTSPEED) - s->dir.y * \
		sin(m * ROTSPEED);
	s->dir.y = s->dir.old_dir_x * sin(m * ROTSPEED) + s->dir.y * \
		cos(m * ROTSPEED);
	s->dir.old_plane_x = s->dir.plane_x;
	s->dir.plane_x = s->dir.plane_x * cos(m * ROTSPEED) - s->dir.plane_y * \
		sin(m * ROTSPEED);
	s->dir.plane_y = s->dir.old_plane_x * sin(m * ROTSPEED) + s->dir.plane_y * \
		cos(m * ROTSPEED);
}

static void		y_coordinate(t_all *s)
{
	if (s->flag.up == 1)
	{
		if (s->map.world[(int)(s->player.x + s->dir.x * WALL)]\
			[(int)s->player.y] == '0' || s->map.world[(int)(s->player.x + \
			s->dir.x * WALL)][(int)s->player.y] == '3')
			s->player.x += s->dir.x * SPEED;
		if (s->map.world[(int)s->player.x][(int)(s->player.y + \
			s->dir.y * WALL)] == '0' || s->map.world[(int)s->player.x]\
			[(int)(s->player.y + s->dir.y * WALL)] == '3')
			s->player.y += s->dir.y * SPEED;
	}
	if (s->flag.down == 1)
	{
		if (s->map.world[(int)(s->player.x - s->dir.x * WALL)]\
			[(int)s->player.y] == '0' || s->map.world[(int)(s->player.x \
			- s->dir.x * WALL)][(int)s->player.y] == '3')
			s->player.x -= s->dir.x * SPEED;
		if (s->map.world[(int)s->player.x][(int)(s->player.y - \
			s->dir.y * WALL)] == '0' || s->map.world[(int)s->player.x]\
			[(int)(s->player.y - s->dir.y * WALL)] == '3')
			s->player.y -= s->dir.y * SPEED;
	}
}

static void		x_coordinate(t_all *s)
{
	if (s->flag.left == 1)
	{
		if (s->map.world[(int)(s->player.x - s->dir.y * WALL)][(int)\
			s->player.y] == '0' || s->map.world[(int)(s->player.x - \
			s->dir.y * WALL)][(int)s->player.y] == '3')
			s->player.x -= s->dir.y * SPEED;
		if (s->map.world[(int)s->player.x][(int)(s->player.y + \
			s->dir.x * WALL)] == '0' || s->map.world[(int)s->player.x]\
			[(int)(s->player.y + s->dir.x * WALL)] == '3')
			s->player.y += s->dir.x * SPEED;
	}
	if (s->flag.right == 1)
	{
		if (s->map.world[(int)(s->player.x + s->dir.y * WALL)]\
			[(int)s->player.y] == '0' || s->map.world[(int)\
			(s->player.x + s->dir.y * WALL)][(int)s->player.y] == '3')
			s->player.x += s->dir.y * SPEED;
		if (s->map.world[(int)s->player.x][(int)(s->player.y - \
			s->dir.x * WALL)] == '0' || s->map.world[(int)s->player.x]\
			[(int)(s->player.y - s->dir.x * WALL)] == '3')
			s->player.y -= s->dir.x * SPEED;
	}
}

int				all_events(t_all *s)
{
	y_coordinate(s);
	x_coordinate(s);
	if (s->flag.turn_l == 1)
		ft_rotate(s, 1);
	if (s->flag.turn_r == 1)
		ft_rotate(s, -1);
	ft_wall(s);
	ft_sprite(s);
	if (s->flag.save == 1)
		ft_bitmap(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	return (1);
}
