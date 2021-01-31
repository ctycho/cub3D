/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_spr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 07:40:53 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 20:36:24 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_texture_1(char *line, int *i)
{
	while (line[*i] != '\0')
	{
		if (line[*i] != ' ')
			ft_error(-6);
		(*i)++;
	}
}

static void			put_direction_1(t_all *s)
{
	if (MAP[Y][X] == 'E')
	{
		s->dir.x = 0;
		s->dir.y = 1;
		s->dir.plane_x = 0.66;
		s->dir.plane_y = 0;
	}
	if (MAP[Y][X] == 'S')
	{
		s->dir.x = 1;
		s->dir.y = 0;
		s->dir.plane_x = 0;
		s->dir.plane_y = -0.66;
	}
}

static void			put_direction(t_all *s)
{
	if (MAP[Y][X] == 'N')
	{
		s->dir.x = -1;
		s->dir.y = 0;
		s->dir.plane_x = 0;
		s->dir.plane_y = 0.66;
	}
	if (MAP[Y][X] == 'W')
	{
		s->dir.x = 0;
		s->dir.y = -1;
		s->dir.plane_x = -0.66;
		s->dir.plane_y = 0;
	}
}

void				draw_player(t_all *s)
{
	Y = -1;

	while (MAP[++Y])
	{
		X = -1;
		while (MAP[Y][++X])
		{
			if (ft_strchr("WESN", MAP[Y][X]) != NULL)
			{
				s->flag.count_p++;
				put_direction(s);
				put_direction_1(s);
				s->player.y = X + 0.5;
				s->player.x = Y + 0.5;
				MAP[Y][X] = '0';
			}
			if (MAP[Y][X] == '2' || MAP[Y][X] == '3')
				s->point.count++;
		}
	}
	if (s->flag.count_p != 1)
		ft_error(-13);
}

void				draw_sprite(t_all *s)
{
	int				num;

	Y = -1;
	num = 0;
	while (MAP[++Y])
	{
		X = -1;
		while (MAP[Y][++X])
		{
			if (MAP[Y][X] == '2')
			{
				s->spr[num].type = '2';
				s->spr[num].y = X + 0.5;
				s->spr[num].x = Y + 0.5;
				num++;
			}
			if (MAP[Y][X] == '3')
			{
				s->spr[num].type = '3';
				s->spr[num].y = X + 0.5;
				s->spr[num].x = Y + 0.5;
				num++;
			}
		}
	}
}
