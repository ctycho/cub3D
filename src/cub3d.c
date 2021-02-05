/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:12:33 by ctycho            #+#    #+#             */
/*   Updated: 2021/02/04 20:15:32 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				ft_get_addr(t_all *s)
{
	s->comp.north.ptr = mlx_xpm_file_to_image(s->mlx.ptr, s->comp.north.doc, \
		&s->comp.north.width, &s->comp.north.height);
	s->comp.north.addr = mlx_get_data_addr(s->comp.north.ptr, &s->comp.north\
		.bpp, &s->comp.north.line_length, &s->comp.north.endian);
	s->comp.west.ptr = mlx_xpm_file_to_image(s->mlx.ptr, s->comp.west.doc, \
		&s->comp.west.width, &s->comp.west.height);
	s->comp.west.addr = mlx_get_data_addr(s->comp.west.ptr, &s->comp.west\
		.bpp, &s->comp.west.line_length, &s->comp.west.endian);
	s->comp.south.ptr = mlx_xpm_file_to_image(s->mlx.ptr, s->comp.south.doc, \
		&s->comp.south.width, &s->comp.south.height);
	s->comp.south.addr = mlx_get_data_addr(s->comp.south.ptr, &s->comp.south\
		.bpp, &s->comp.south.line_length, &s->comp.south.endian);
	s->comp.east.ptr = mlx_xpm_file_to_image(s->mlx.ptr, s->comp.east.doc, \
		&s->comp.east.width, &s->comp.east.height);
	s->comp.east.addr = mlx_get_data_addr(s->comp.east.ptr, &s->comp.east\
		.bpp, &s->comp.east.line_length, &s->comp.east.endian);
	s->comp.sprite.ptr = mlx_xpm_file_to_image(s->mlx.ptr, s->comp.sprite.doc, \
		&s->comp.sprite.width, &s->comp.sprite.height);
	s->comp.sprite.addr = mlx_get_data_addr(s->comp.sprite.ptr, &s->comp.sprite\
		.bpp, &s->comp.sprite.line_length, &s->comp.sprite.endian);
	s->comp.sprite1.ptr = mlx_xpm_file_to_image(s->mlx.ptr, s->comp.sprite1.\
		doc, &s->comp.sprite1.width, &s->comp.sprite1.height);
	s->comp.sprite1.addr = mlx_get_data_addr(s->comp.sprite1.ptr, &s->comp.\
		sprite1.bpp, &s->comp.sprite1.line_length, \
		&s->comp.sprite1.endian);
}

static void				ft_cub(t_all s, char *cub)
{
	s.mlx.ptr = mlx_init();
	ft_read_map(&s, cub);
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "Cub3D");
	s.img.ptr = mlx_new_image(s.mlx.ptr, s.win.x, s.win.y);
	s.img.addr = mlx_get_data_addr(s.img.ptr, &s.img.bpp, \
		&s.img.line_length, &s.img.endian);
	draw_sprite(&s);
	ft_get_addr(&s);
	mlx_key_hook(s.win.ptr, key_hook, &s);
	mlx_hook(s.win.ptr, 2, 0, key_press, &s);
	mlx_hook(s.win.ptr, 3, 0, key_release, &s);
	mlx_hook(s.win.ptr, 17, 0, key_exit, &s);
	mlx_loop_hook(s.mlx.ptr, all_events, &s);
	mlx_loop(s.mlx.ptr);
}

static void				ft_declare(t_all s, char *cub, int bmp)
{
	s.player.x = 0;
	s.player.y = 0;
	s.flag.count = 0;
	s.flag.count_p = 0;
	s.flag.skip = 1;
	s.flag.count_line = 0;
	s.point.count = 0;
	s.flag.up = 0;
	s.flag.down = 0;
	s.flag.left = 0;
	s.flag.right = 0;
	s.flag.turn_l = 0;
	s.flag.turn_up = 0;
	s.flag.turn_down = 0;
	s.flag.turn_r = 0;
	s.flag.err = 0;
	s.dir.old_dir_x = 0;
	s.dir.old_plane_x = 0;
	s.hit.wall = 0;
	if (bmp == 1)
		s.flag.save = 1;
	if (bmp == 0)
		s.flag.save = 0;
	ft_cub(s, cub);
}

static void				ft_init(char *cub, int bmp)
{
	t_all				s;

	s.mlx.ptr = NULL;
	s.win.ptr = NULL;
	s.img.ptr = NULL;
	s.win.x = 0;
	s.win.y = 0;
	s.comp.north.flag_1 = 1;
	s.comp.south.flag_1 = 1;
	s.comp.west.flag_1 = 1;
	s.comp.east.flag_1 = 1;
	s.comp.sprite.flag_1 = 1;
	s.comp.sprite1.flag_1 = 1;
	s.comp.col_f.flag_1 = 1;
	s.comp.col_c.flag_1 = 1;
	s.comp.resol.flag_1 = 1;
	s.map.world = NULL;
	s.map.x = -1;
	s.map.y = 0;
	s.map.line_cur = 0;
	s.map.line_next = 0;
	s.head = NULL;
	ft_declare(s, cub, bmp);
}

int						main(int argc, char **argv)
{
	if (argc == 3 && ft_namecheck(argv[1], "cub") && \
		check_save("--save", argv[2]))
		ft_init(argv[1], 1);
	else if (argc == 2 && ft_namecheck(argv[1], "cub"))
		ft_init(argv[1], 0);
	else
		write(2, "Error:\nInvalid arguements", 25);
	return (0);
}
