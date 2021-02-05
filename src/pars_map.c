/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:51:07 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_rabish(t_all *s)
{
	Y = -1;
	while (MAP[++Y])
	{
		X = -1;
		while (MAP[Y][++X])
		{
			if (MAP[Y][X] != ' ' && MAP[Y][X] != '1' && MAP[Y][X] != '2' && \
				MAP[Y][X] != '3' && MAP[Y][X] != 'N' && MAP[Y][X] != 'S' && \
				MAP[Y][X] != 'W' && MAP[Y][X] != 'E' && MAP[Y][X] != '0')
				ft_error(-18);
		}
	}
}

static void		check_around(t_all *s)
{
	int		i;
	int		j;

	i = -1;
	j = s->flag.count_line - 1;
	while (MAP[0][++i])
	{
		if (MAP[0][i] != ' ' && MAP[0][i] != '1')
			ft_error(-16);
	}
	i = -1;
	while (MAP[++i])
	{
		if (MAP[i][0] != ' ' && MAP[i][0] != '1')
			ft_error(-16);
	}
	i = -1;
	while (MAP[j][++i])
	{
		if (MAP[j][i] != ' ' && MAP[j][i] != '1')
			ft_error(-16);
	}
}

static void		check_inside(t_all *s)
{
	Y = 0;
	while (MAP[Y])
	{
		X = 0;
		while (MAP[Y][X])
		{
			if (MAP[Y][X] == '0' || MAP[Y][X] == 'N' || MAP[Y][X] == 'W' \
				|| MAP[Y][X] == 'S' || MAP[Y][X] == 'E' || \
				MAP[Y][X] == '2' || MAP[Y][X] == '3')
			{
				if (MAP[Y - 1][X - 1] == '\0' || MAP[Y - 1][X - 1] == ' ' || \
					MAP[Y - 1][X] == '\0' || MAP[Y - 1][X] == ' ' || \
					MAP[Y - 1][X + 1] == '\0' || MAP[Y - 1][X + 1] == ' ' || \
					MAP[Y][X - 1] == '\0' || MAP[Y][X - 1] == ' ' || \
					MAP[Y][X + 1] == '\0' || MAP[Y][X + 1] == ' ' || \
					MAP[Y + 1][X - 1] == '\0' || MAP[Y + 1][X - 1] == ' ' || \
					MAP[Y + 1][X] == '\0' || MAP[Y + 1][X] == ' ' || \
					MAP[Y + 1][X + 1] == '\0' || MAP[Y + 1][X + 1] == ' ')
					ft_error(-15);
			}
			X++;
		}
		Y++;
	}
}

static void		check_length(t_all *s, int m)
{
	int		i;
	int		j;

	Y = 0;
	while (Y < m - 1)
	{
		X = 0;
		i = ft_strlen(MAP[Y]);
		j = ft_strlen(MAP[Y + 1]);
		if (j > i)
		{
			X = i;
			while (MAP[Y + 1][X])
			{
				if (MAP[Y + 1][X] == '0' || \
				MAP[Y + 1][X] == '2' || \
				MAP[Y + 1][X] == '3')
					ft_error(-17);
				X++;
			}
		}
		Y++;
	}
}

void			ft_map(t_all *s)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		m;

	tmp = s->head;
	m = 0;
	if (!(s->map.world = calloc((s->flag.count_line + 1), sizeof(char *))))
		ft_error(-9);
	while (tmp)
	{
		MAP[m] = tmp->content;
		m++;
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
	check_rabish(s);
	draw_player(s);
	check_around(s);
	check_length(s, m);
	check_inside(s);
	if (!(s->spr = (t_spr *)malloc(sizeof(t_spr) * s->point.count)))
		ft_error(-9);
	draw_sprite(s);
}
