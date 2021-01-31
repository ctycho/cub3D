/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:25:47 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 08:01:15 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		hit_wall(t_all *s)
{
	int	hit = 0;
	while (hit == 0)
	{
		if(s->ray.side_dist_x < s->ray.side_dist_y)
		{
			s->ray.side_dist_x += s->ray.delta_dist_x;
			s->map.map_x += s->ray.step_x;
			s->hit.side = 0;
		}
		else
		{
			s->ray.side_dist_y += s->ray.delta_dist_y;
			s->map.map_y += s->ray.step_y;
			s->hit.side = 1;
		}
		if(s->map.world[s->map.map_x][s->map.map_y] == '1')
			hit = 1;
	}
}



void		find_sideDist(t_all *s)
{
	s->ray.delta_dist_x = sqrt(1 + (s->ray.y * s->ray.y) / (s->ray.x * s->ray.x));
	s->ray.delta_dist_y = sqrt(1 + (s->ray.x * s->ray.x) / (s->ray.y * s->ray.y));
	if(s->ray.x < 0)
	{
		s->ray.step_x = -1;
		s->ray.side_dist_x = (s->player.x - s->map.map_x) * s->ray.delta_dist_x;
	}
	else
	{
		s->ray.step_x = 1;
		s->ray.side_dist_x = (s->map.map_x + 1.0 - s->player.x) * s->ray.delta_dist_x;
	}
	if(s->ray.y < 0)
	{
		s->ray.step_y = -1;
		s->ray.side_dist_y = (s->player.y - s->map.map_y) * s->ray.delta_dist_y;
	}
	else
	{
		s->ray.step_y = 1;
		s->ray.side_dist_y = (s->map.map_y + 1.0 - s->player.y) * s->ray.delta_dist_y;
	}
}

void		put_position(t_all *s, int x)
{
	double cameraX;

	cameraX = 2 * x / (double)s->win.x - 1; //x-coordinate in camera space
	s->ray.x = s->dir.x + s->dir.plane_x * cameraX;
	s->ray.y = s->dir.y + s->dir.plane_y * cameraX;
	s->map.map_x = (int)s->player.x;
	s->map.map_y = (int)s->player.y;
}

void		ft_raycasting(t_all *s)
{
	int		x;
	int		y;
	unsigned int	*src;

	x = 1;
	y = 0;
	while(x < s->win.x)
	{
		put_position(s, x);
		find_sideDist(s);
		hit_wall(s);
		if(s->hit.side == 0)
			s->ray.perp_wall_dist = (s->map.map_x - s->player.x + (1 - s->ray.step_x) / 2) / s->ray.x;
		else
			s->ray.perp_wall_dist = (s->map.map_y - s->player.y + (1 - s->ray.step_y) / 2) / s->ray.y;
		int lineHeight = (int)(s->win.y / s->ray.perp_wall_dist);
		int drawStart = (s->win.y / 2) - (lineHeight / 2);
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = (lineHeight / 2) + (s->win.y / 2);
		if(drawEnd >= s->win.y)
			drawEnd = s->win.y - 1;
		int texNum = s->map.world[s->map.map_x][s->map.map_y] - 1; //1 subtracted from it so that texture 0 can be used!
		double wallX; //where exactly the wall was hit
		if(s->hit.side == 0)
			wallX = s->player.y + s->ray.perp_wall_dist * s->ray.y;
		else
			wallX = s->player.x + s->ray.perp_wall_dist * s->ray.x;
		wallX -= floor((wallX));
		int texX = (int)(wallX * (double)s->comp.north.width);
		if(s->hit.side == 0 && s->ray.x > 0)
			texX = s->comp.north.width - texX - 1;
		if(s->hit.side == 1 && s->ray.y < 0)
			texX = s->comp.north.width - texX - 1;
		double step = 1.0 * s->comp.north.height / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - s->win.y / 2 + lineHeight / 2) * step;
		int y = 0;
		while (y < s->win.y)
		{
			if(y <= drawStart)
			{
				my_mlx_pixel_put(s, x, y, s->comp.col_c.rgb); 
			}
			else if (y > drawStart && y < drawEnd)
			{
				int texY = (int)texPos;
				texPos += step;
				if (s->hit.side == 0)
				{	
					if (s->ray.step_x < 0)
					{
						if (texY >= s->comp.north.height)
							texY = s->comp.north.height - 1;
						if (texY < 0)
							texY = 0;
						if (texX >= s->comp.north.width)
							texX = s->comp.north.width - 1;
						if (texX < 0)
							texX = 0;
						src = (unsigned int *)(s->comp.north.addr + texY * s->comp.north.line_length + texX * (s->comp.north.bpp / 8));
					}
					else if (s->ray.step_x >= 0)
					{
						if (texY >= s->comp.north.height)
							texY = s->comp.north.height - 1;
						if (texY < 0)
							texY = 0;
						if (texX >= s->comp.north.width)
							texX = s->comp.north.width - 1;
						if (texX < 0)
							texX = 0;
						src = (unsigned int *)(s->comp.south.addr + texY * s->comp.south.line_length + texX * (s->comp.south.bpp / 8));
					}
				}
				else
				{
					if (s->ray.step_y < 0)
					{
						if (texY >= s->comp.north.height)
							texY = s->comp.north.height - 1;
						if (texY < 0)
							texY = 0;
						if (texX >= s->comp.north.width)
							texX = s->comp.north.width - 1;
						if (texX < 0)
							texX = 0;
						src = (unsigned int *)(s->comp.west.addr + texY * s->comp.west.line_length + texX * (s->comp.west.bpp / 8));
					}
					else
					{
						if (texY >= s->comp.north.height)
							texY = s->comp.north.height - 1;
						if (texY < 0)
							texY = 0;
						if (texX >= s->comp.north.width)
							texX = s->comp.north.width - 1;
						if (texX < 0)
							texX = 0;
						src = (unsigned int *)(s->comp.east.addr + texY * s->comp.east.line_length + texX * (s->comp.east.bpp / 8));
					}
				}
				my_mlx_pixel_put(s, x, y, *(unsigned int*)src);
			}
			else
			{
				my_mlx_pixel_put(s, x, y, s->comp.col_f.rgb); 
			}
			y++;
		}
		// mlx_mouse_get_pos(s->win.ptr, &x, &y);
		s->point.buf[x] = s->ray.perp_wall_dist;
		x++;
	}
}

