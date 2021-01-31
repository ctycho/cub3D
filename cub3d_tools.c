/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:35:17 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 20:48:02 by ctycho           ###   ########.fr       */
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

int							ft_atoi_cub(char *line, int *i)
{
	unsigned long			res;

	res = 0;
	skip_space(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
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
	(err == -1) ? write(2, "Error : Couldn't open file (FD)\n", 32) : 0;
	(err == -2) ? write(2, "Error : Couldn't parse file (GNL)\n", 34) : 0;
	(err == -3) ? write(2, "Error : Invalid resolution\n", 27) : 0;
	(err == -4) ? write(2, "Error : Floor/ceiling specified twice\n", 38) : 0;
	(err == -5) ? write(2, "Error : Invalid floor/ceiling line\n", 35) : 0;
	(err == -6) ? write(2, "Error : Texture path specified twice\n", 37) : 0;
	(err == -7) ? write(2, "Error : Invalid texture line\n", 29) : 0;
	(err == -8) ? write(2, "Error : Malloc fail (texture path)\n", 35) : 0;
	(err == -9) ? write(2, "Error : Malloc fail (map table)\n", 32) : 0;
	(err == -10) ? write(2, "Error : Invalid line in file\n", 29) : 0;
	(err == -11) ? write(2, "Error : Invalid map\n", 20) : 0;
	(err == -12) ? write(2, "Error : Map isn't surrounded by walls\n", 38) : 0;
	(err == -13) ? write(2, "Error : No starting position\n", 29) : 0;
	(err == -14) ? write(2, "Error : Multiple starting positions\n", 36) : 0;
	(err == -15) ? write(2, "Error : inside\n", 15) : 0;
	(err == -16) ? write(2, "Error : around\n", 15) : 0;
	(err == -17) ? write(2, "Error : length\n", 15) : 0;
	exit(0);
}
