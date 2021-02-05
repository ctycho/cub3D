/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:46:37 by ctycho            #+#    #+#             */
/*   Updated: 2021/02/04 19:51:54 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			ft_scale(t_all *s, t_tex *scale, char *line, int *i)
{
	scale->flag_1 = 0;
	(*i)++;
	if (!(s->win.x = ft_atoi_cub(line, i)))
		ft_error(-3);
	if (!(s->win.y = ft_atoi_cub(line, i)))
		ft_error(-3);
	if (s->win.x > 2560)
		s->win.x = 2560;
	if (s->win.y > 1400)
		s->win.y = 1400;
	while (line[*i] != '\0')
	{
		if (line[*i] != ' ')
			ft_error(-3);
		(*i)++;
	}
	s->flag.count++;
	return (0);
}

static int			ft_texture(t_all *s, t_tex *tex, char *line, int *i)
{
	int				m;
	int				fd;

	tex->flag_1 = 0;
	(*i) += 2;
	skip_space(line, i);
	m = (*i);
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(tex->doc = (char *)malloc(sizeof(char) * ((*i) - m + 1))))
		ft_error(-8);
	(*i) = m;
	m = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
	{
		tex->doc[m++] = line[(*i)++];
	}
	tex->doc[m] = '\0';
	ft_texture_1(line, i);
	if (ft_namecheck(tex->doc, "xpm") == 0)
		ft_error(-7);
	if ((fd = open(tex->doc, O_RDONLY)) == -1)
		ft_error(-1);
	s->flag.count++;
	return (0);
}

static void			check_line_2(t_all *s, char *line, int res, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ' && \
		s->comp.north.flag_1)
		res = ft_texture(s, &s->comp.north, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ' && \
		s->comp.south.flag_1)
		res = ft_texture(s, &s->comp.south, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ' && \
		s->comp.west.flag_1)
		res = ft_texture(s, &s->comp.west, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ' && \
		s->comp.east.flag_1)
		res = ft_texture(s, &s->comp.east, line, &i);
	else if (s->flag.count == 9 && skip_space(line, &i) && line[i] == '1')
		count_lines(s, line);
	else if (line[i] == '\0' && s->flag.skip == 1)
		res = 0;
	else if (line[i] == '\0' && s->flag.skip == 0)
		count_lines(s, line);
	else
		ft_error(-10);
}

static void			check_line_1(t_all *s, char *line)
{
	int				i;
	int				res;

	i = 0;
	res = 1;
	if (line[i] == 'R' && line[i + 1] == ' ' && \
		s->comp.resol.flag_1)
		res = ft_scale(s, &s->comp.resol, line, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ' && \
		s->comp.sprite.flag_1)
		res = ft_texture(s, &s->comp.sprite, line, &i);
	else if (line[i] == 'L' && line[i + 1] == ' ' && \
		s->comp.sprite1.flag_1)
		res = ft_texture(s, &s->comp.sprite1, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ' && \
		s->comp.col_c.flag_1)
		res = ft_color(s, &s->comp.col_c, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ' && \
		s->comp.col_f.flag_1)
		res = ft_color(s, &s->comp.col_f, line, &i);
	else if (res == 1)
		check_line_2(s, line, res, i);
}

int					**ft_read_map(t_all *s, char *argv)
{
	int				fd;
	char			*line;
	int				ret;

	ret = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error(-1);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		check_line_1(s, line);
		free(line);
	}
	close(fd);
	if (!(s->point.buf = (double *)malloc(sizeof(double) * s->win.x)))
		ft_error(-9);
	ft_map(s);
	return (0);
}
