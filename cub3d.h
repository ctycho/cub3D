/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:59:10 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 21:56:00 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx_opengl/mlx.h"
# include "libft/include/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define MAP s->map.world
# define X s->map.x
# define Y s->map.y
# define W 13
# define S 1
# define A 0
# define D 2
# define UP 123
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define SPEED 0.05
# define WALL SPEED * 6
# define ROTSPEED 0.05

typedef struct		s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct		s_win
{
	void			*ptr;
	unsigned long	x;
	unsigned long	y;
}					t_win;

typedef struct		s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_flag
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				turn_l;
	int				turn_r;
	int				turn_up;
	int				turn_down;
	int				count;
	int				count_p;
	int				skip;
	int				count_line;
	int				f_spr;
	int				err;
	int				save;
}					t_flag;

typedef struct		s_map
{
	char			**world;
	int				x;
	int				y;
	int				spr;
	int				map_x;
	int				map_y;
	int				line_cur;
	int				line_next;
}					t_map;

typedef struct		s_player
{
	double			x;
	double			y;
}					t_player;

typedef struct		s_dir
{
	double			x;
	double			y;
	double			angle;
	double			fov;
	double			old_dir_x;
	double			plane_x;
	double			plane_y;
	double			old_plane_x;
}					t_dir;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
}					t_ray;

typedef struct		s_hit
{
	int				wall;
	int				side;
	double			x;
	double			y;
	double			d;
}					t_hit;

typedef struct		s_tex
{
	int				rgb;
	char			*doc;
	void			*ptr;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				flag_1;
	int				tex_x;
	int				tex_y;
}					t_tex;

typedef struct		s_comp
{
	t_tex			north;
	t_tex			south;
	t_tex			west;
	t_tex			east;
	t_tex			sprite;
	t_tex			sprite1;
	t_tex			col_c;
	t_tex			col_f;
	t_tex			resol;
	t_tex			texture;
}					t_comp;

typedef struct		s_point
{
	double			*buf;
	int				count;
	int				total;
	double			spr_x;
	double			spr_y;
	int				spr_h;
	int				spr_w;
	double			tform_x;
	double			tform_y;
	int				spr_screen_x;
	int				start_y;
	int				start_x;
	int				end_y;
	int				end_x;
}					t_point;

typedef struct		s_spr
{
	double			x;
	double			y;
	double			dist;
	char			type;
}					t_spr;

typedef struct		s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_flag			flag;
	t_color			color;
	t_map			map;
	t_player		player;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_point			point;
	t_spr			*spr;
	t_spr			*spr1;
	t_comp			comp;
	t_list			*head;
}					t_all;

void				my_mlx_pixel_put(t_all *s, int x, int y, int color);
int					ft_atoi_cub(char *line, int *i);
int					key_hook(int keycode);
void				draw_screen(t_all *s);
int					key_press(int key, t_all *s);
int					key_release(int key, t_all *s);
int					all_events(t_all *s);
int					**ft_read_map(t_all *s, char *argv);
void				ft_map(t_all *s);
void				ft_raycasting(t_all *s);
int					key_hook(int keycode);
int					key_press(int key, t_all *s);
int					key_release(int key, t_all *s);
int					key_exit(t_all *s);
int					all_events(t_all *s);
void				hit_wall(t_all *s);
void				draw_sprite(t_all *s);
void				ft_sprite(t_all *s);
int					create_rgb(int r, int g, int b);
void				ft_error(int err);
void				count_lines(t_all *s, char *line);
int					skip_space(char *line, int *i);
int					ft_color(t_all *s, t_tex *color, char *line, int *i);
int					ft_namecheck(char *line, char *ext);
int					check_line_5(t_all *s, char *line);
int					check_line_6(t_all *s, char *line);
int					check_plr(t_all *s, char *line, int i);
void				ft_bitmap(t_all *s);
void				ft_texture_1(char *line, int *i);
// void				ft_sprite1(t_all *s, int i);
void				draw_player(t_all *s);

#endif
