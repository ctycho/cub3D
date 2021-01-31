/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:45:54 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 20:27:37 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int		check_sprite(t_all *s, char *line, int i)
// {
// 	s->point.count++;
// 	if (line[i - 1] == ' ' || line[i + 1] == ' ')
// 		ft_error(-12);
// 	if (i <= s->map.line_cur)
// 	{
// 		if (MAP[Y + 1][i] == ' ')
// 			ft_error(-12);
// 	}
// 	return (0);
// }

// static int		check_zero(t_all *s, char *line, int i)
// {
// 	if (line[i - 1] == ' ' || line[i + 1] == ' ')
// 		ft_error(-12);
// 	if (i <= s->map.line_cur)
// 	{
// 		if (MAP[Y + 1][i] == ' ')
// 			ft_error(-12);
// 	}
// 	return (0);
// }

// static int		check_space(t_all *s, char *line, int i)
// {
// 	if (line[i - 1] == '0' || line[i + 1] == '0')
// 		ft_error(-2);
// 	if (i <= s->map.line_cur)
// 	{
// 		if (MAP[Y + 1][i] == '0')
// 			ft_error(-12);
// 		if (MAP[Y + 1][i] == '2')
// 			ft_error(-12);
// 		if (MAP[Y + 1][i] == '3')
// 			ft_error(-12);
// 	}
// 	return (0);
// }

// int				check_line_6(t_all *s, char *line)
// {
// 	int			i;

// 	i = 0;
// 	if (s->map.line_next > s->map.line_cur)
// 	{
// 		i = s->map.line_cur;
// 		while (MAP[Y + 1][i])
// 		{
// 			if (MAP[Y + 1][i] == '0')
// 				ft_error(-12);
// 			if (MAP[Y + 1][i] == '2' || MAP[Y + 1][i] == '3')
// 				ft_error(-12);
// 			if (ft_strchr("WESN", MAP[Y + 1][i]) != NULL)
// 				ft_error(-12);
// 			i++;
// 		}
// 	}
// 	return (0);
// }

// int				check_line_5(t_all *s, char *line)
// {
// 	int			i;

// 	i = 0;
// 	if (line[i] == '\0')
// 		ft_error(-11);
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == ' ')
// 			check_space(s, MAP[Y], i);
// 		if (line[i] == '0')
// 			check_zero(s, MAP[Y], i);
// 		if (line[i] == '2' || line[i] == '3')
// 			check_sprite(s, MAP[Y], i);
// 		if (ft_strchr("WESN", line[i]) != NULL)
// 			check_plr(s, MAP[Y], i);
// 		i++;
// 	}
// 	if (line[i - 1] == '0' || line[i - 1] == '3' || line[i - 1] == '2')
// 		ft_error(-12);
// 	return (0);
// }
