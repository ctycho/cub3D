/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:57:43 by ctycho            #+#    #+#             */
/*   Updated: 2021/02/04 20:15:48 by ctycho           ###   ########.fr       */
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

int					check_save(char *s, char *s1)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != s1[i])
			return (0);
		i++;
	}
	return (1);
}
