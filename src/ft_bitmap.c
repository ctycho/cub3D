/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/02/05 10:29:11 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			transfer(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static	void		bmp_header(t_all *s, int file_size, int fd)
{
	unsigned char btr[54];

	ft_bzero(btr, 54);
	btr[0] = (unsigned char)('B');
	btr[1] = (unsigned char)('M');
	transfer(file_size, btr + 2);
	btr[10] = (unsigned char)(54);
	btr[14] = (unsigned char)(40);
	transfer(s->win.x, btr + 18);
	transfer(s->win.y, btr + 22);
	btr[26] = (unsigned char)(1);
	btr[28] = (unsigned char)(24);
	write(fd, btr, 54);
}

static	void		get_pxl(t_all *s, int fd)
{
	int	i;
	int	j;
	int	color;

	i = s->win.y - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < s->win.x)
		{
			color = *(int*)(s->img.addr +
			(i * s->img.line_length + j * (s->img.bpp / 8)));
			write(fd, &color, 3);
		}
		i--;
	}
}

void				ft_bitmap(t_all *s)
{
	int	fd;
	int	limb;

	while (s->win.x % 4 != 0)
		s->win.x--;
	limb = 54 + (4 * s->win.y * s->win.x);
	if (!(fd = open("screen_shot.bmp", O_WRONLY | O_CREAT
	| O_TRUNC | O_APPEND, 0666)))
		ft_error(-1);
	bmp_header(s, limb, fd);
	get_pxl(s, fd);
	close(fd);
	exit(0);
}
