/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:47:22 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/30 23:52:36 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			key_hook(int keycode)
{
	printf("Key value is %i\n", keycode);
	return (1);
}

int			key_press(int key, t_all *s)
{
	if (key == ESC)
		exit(0);
	if (key == W)
		s->flag.up = 1;
	if (key == S)
		s->flag.down = 1;
	if (key == A)
		s->flag.left = 1;
	if (key == D)
		s->flag.right = 1;
	if (key == LEFT)
		s->flag.turn_l = 1;
	if (key == RIGHT)
		s->flag.turn_r = 1;
	return (1);
}

int			key_release(int key, t_all *s)
{
	if (key == W)
		s->flag.up = 0;
	if (key == S)
		s->flag.down = 0;
	if (key == A)
		s->flag.left = 0;
	if (key == D)
		s->flag.right = 0;
	if (key == LEFT)
		s->flag.turn_l = 0;
	if (key == RIGHT)
		s->flag.turn_r = 0;
	return (1);
}

int			key_exit(t_all *s)
{
	exit(0);
}
