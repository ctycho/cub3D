/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:51:07 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							skip_space(char *line, int *i)
{
	if (line[*i] == '\t')
		ft_error(-10);
	while (line[*i] == ' ')
	{
		(*i)++;
	}
	return (1);
}

int							ft_intlen(int line)
{
	int						count;

	count = 0;
	while (line)
	{
		line = line / 10;
		count++;
	}
	return (count);
}

int							ft_atoi_cub(char *line, int *i)
{
	int			res;
	int			tmp;

	res = 0;
	skip_space(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		tmp = res;
		if (ft_intlen(tmp) < 5)
			res = res * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (res);
}

int							ft_namecheck(char *line, char *ext)
{
	int						i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if ((i > 4 && line[i - 1] == ext[2] && line[i - 2] == ext[1])
		&& (line[i - 3] == ext[0] && line[i - 4] == '.'))
		return (1);
	return (0);
}

void						ft_error(int err)
{
	(err == -1) ? write(2, "Error :\nCouldn't open file (FD)\n", 32) : 0;
	(err == -2) ? write(2, "Error :\nCouldn't parse file (GNL)\n", 34) : 0;
	(err == -3) ? write(2, "Error :\nInvalid resolution\n", 27) : 0;
	(err == -4) ? write(2, "Error :\nFloor/ceiling specified twice\n", 38) : 0;
	(err == -5) ? write(2, "Error :\nInvalid floor/ceiling line\n", 35) : 0;
	(err == -6) ? write(2, "Error :\nTexture path specified twice\n", 37) : 0;
	(err == -7) ? write(2, "Error :\nInvalid texture line\n", 29) : 0;
	(err == -8) ? write(2, "Error :\nMalloc fail (texture path)\n", 35) : 0;
	(err == -9) ? write(2, "Error :\nMalloc fail (map table)\n", 32) : 0;
	(err == -10) ? write(2, "Error :\nInvalid line in file\n", 29) : 0;
	(err == -11) ? write(2, "Error :\nInvalid map\n", 20) : 0;
	(err == -12) ? write(2, "Error :\nMap isn't surrounded by walls\n", 38) : 0;
	(err == -13) ? write(2, "Error :\nNo starting position\n", 29) : 0;
	(err == -14) ? write(2, "Error :\nMultiple starting positions\n", 36) : 0;
	(err == -15) ? write(2, "Error :\ninside\n", 15) : 0;
	(err == -16) ? write(2, "Error :\naround\n", 15) : 0;
	(err == -17) ? write(2, "Error :\nlength\n", 15) : 0;
	(err == -18) ? write(2, "Error :\nrabish\n", 15) : 0;
	exit(0);
}
