/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:29:57 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 22:18:30 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_around(t_all *s)
{
	int		i = 0;
	int 	j = s->flag.count_line - 1;

	while (MAP[0][i])
	{
		if (MAP[0][i] != ' ' && MAP[0][i] != '1')
			ft_error(-16);
		i++;
	}
	i = 0;
	while (MAP[i])
	{
		if (MAP[i][0] != ' ' && MAP[i][0] != '1')
			ft_error(-16);
		i++;
	}
	i = 0;
	while (MAP[j][i])
	{
		if (MAP[j][i] != ' ' && MAP[j][i] != '1')
			ft_error(-16);
		i++;
	}
}

static void		check_inside(t_all *s)
{
	int		i = 0;
	int 	j = 0;

	while (MAP[i])
	{
		j = 0;
		while (MAP[i][j])
		{
			if (MAP[i][j] == '0' || MAP[i][j] == 'N' || MAP[i][j] == 'W' || MAP[i][j] == 'S' || MAP[i][j] == 'E' || MAP[i][j] == '2' || MAP[i][j] == '3')
			{
				if (MAP[i - 1][j - 1] == '\0' || MAP[i - 1][j - 1] == ' ' || \
					MAP[i - 1][j] == '\0' || MAP[i - 1][j] == ' ' || \
					MAP[i - 1][j + 1] == '\0' || MAP[i - 1][j + 1] == ' ' || \
					MAP[i][j - 1] == '\0' || MAP[i][j - 1] == ' ' || \
					MAP[i][j + 1] == '\0' || MAP[i][j + 1] == ' ' || \
					MAP[i + 1][j - 1] == '\0' || MAP[i + 1][j -1] == ' ' || \
					MAP[i + 1][j] == '\0' || MAP[i + 1][j] == ' ' || \
					MAP[i + 1][j + 1] == '\0' || MAP[i + 1][j + 1] == ' ')
					ft_error(-15);
			}
			j++;
		}
		i++;
	}
}

static void		check_length(t_all *s, int m)
{
	int		i = 0;
	int		j = 0;
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
	draw_player(s);
	check_around(s);
	check_length(s, m);
	check_inside(s);
	if (!(s->point.buf = (double *)malloc(sizeof(double) * s->win.x)))
		return ;
	if (!(s->spr = (t_spr *)malloc(sizeof(t_spr) * s->point.count)))
		return ;	
	draw_sprite(s);
}
