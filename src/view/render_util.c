/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:49 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/20 20:17:39 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../libft/libft.h"
#include <math.h>

void	draw_ray(t_cub *cub, t_ray *ray)
{
	double	ex;
	double	ey;

	ex = (ray->e[DX] - cub->user.x) * MMAP_SZ / N_TILE;
	ey = (ray->e[DY] - cub->user.y) * MMAP_SZ / N_TILE;
}

static void	draw_wall_sub(t_cub *cub, t_ray *ray, t_draw draw)
{
	t_img		*img;
	t_option	*opt;
	t_uint		color;
	int			texoffsety;
	int			texoffsetx;

	opt = &cub->parse.opt[ray->face];
	img = &opt->img;
	while (draw.top < draw.bottom)
	{
		texoffsety = (draw.top + (draw.h / 2) - WIN_HEIGHT / 2)
			* ((double)opt->height / draw.h);
		texoffsetx = draw.texoffx * opt->width;
		color = *(t_uint *)(img->data + (texoffsetx * img->bpp / 8)
				+ texoffsety * img->lsz);
		draw_pixel(draw.i, draw.top, color, &cub->mlx.img);
		draw.top++;
	}
}

void	draw_wall(t_cub *cub, t_ray *ray, int i)
{
	t_draw		draw;

	draw.i = i;
	draw.h = WIN_HEIGHT / 2 / ray->d / cos((i - WIN_WIDTH / 2)
			* FOV / WIN_WIDTH) * WIN_WIDTH / WIN_HEIGHT;
	draw.top = WIN_HEIGHT / 2 - draw.h / 2;
	if (draw.top < 0)
		draw.top = 0;
	draw.bottom = WIN_HEIGHT / 2 + draw.h / 2;
	if (draw.bottom >= WIN_HEIGHT)
		draw.bottom = WIN_HEIGHT;
	if (ray->face == NORTH)
		draw.texoffx = 1 - fmod(ray->e[DX], 1);
	else if (ray->face == SOUTH)
		draw.texoffx = fmod(ray->e[DX], 1);
	else if (ray->face == WEST)
		draw.texoffx = 1 - fmod(ray->e[DY], 1);
	else if (ray->face == EAST)
		draw.texoffx = fmod(ray->e[DY], 1);
	draw_wall_sub(cub, ray, draw);
}
