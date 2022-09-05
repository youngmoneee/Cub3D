/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:49 by youngpar          #+#    #+#             */
/*   Updated: 2022/08/23 17:17:50 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../libft/libft.h"
#include <math.h>

int		close_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		mlx_destroy_window(mlx->pmlx, mlx->pwin);
		exit(0);
	}
	return (0);
}

void	draw_pixel(int x, int y, unsigned color, t_img *img)
{
	void	*pixel;

	pixel = img->data + (x * img->bpp / 8) + (y * img->lsz);
	*(unsigned *)pixel = color;
}

void	draw_bg(t_cub *cub)
{
	int i;
	int j;

	i = -1;
	while (++i < WIN_HEIGHT / 2)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			draw_pixel(j, i, cub->parse.opt[CEIL].color, &cub->mlx.img);
		}
	}
	while (i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			draw_pixel(j, i, cub->parse.opt[FLOOR].color, &cub->mlx.img);
		}
		i++;
	}
}

void	draw_ray(t_cub *cub, t_ray *ray)
{
	double	sx;
	double	sy;
	double	ex;
	double	ey;
	double	ofsx;
	double	ofsy;
	double	longe;

	sx = 0;
	sy = 0;
	ex = (ray->e[DX] - cub->user.x) * MMAP_SZ / N_TILE;
	ey = (ray->e[DY] - cub->user.y) * MMAP_SZ / N_TILE;
	longe = (fabs(ex) >= fabs(ey) ? fabs(ex) : fabs(ey));

	ofsx = ex / ray->d * N_TILE / MMAP_SZ;
	ofsy = ey / ray->d * N_TILE / MMAP_SZ;
	int i = -1;
	
	while (++i < ray->d * MMAP_SZ / N_TILE && fabs(sqrt((sx * sx) + (sy * sy)) - MMAP_SZ / 2) > 1) {
		draw_pixel(PAD_X + sx, PAD_Y + sy, 0, &cub->mlx.img);
		sx += ofsx;
		sy += ofsy;
	}
}

void	draw_wall(t_cub *cub, t_ray *ray, int i)
{
	int	idx;
	int h = WIN_HEIGHT / 2 / ray->d / cos((i - WIN_WIDTH / 2) * FOV / WIN_WIDTH) * WIN_WIDTH / WIN_HEIGHT;
	int top = WIN_HEIGHT / 2 - h / 2;
	int bottom = WIN_HEIGHT / 2 + h / 2;
	top = top < 0 ? 0 : top;
	bottom = bottom >= WIN_HEIGHT ? WIN_HEIGHT : bottom;

	//int	texoffsetx = ray->hit == VERT ? (int)ray->e[DY] : (int)ray->e[DX];
	double texoffx;
	t_img		*img;
	t_option	*opt;
	uint	color;


	if (ray->face == NORTH)
		texoffx = 1 - fmod(ray->e[DX], 1);
	else if (ray->face == SOUTH)
		texoffx = fmod(ray->e[DX], 1);
	else if (ray->face == WEST)
		texoffx = 1 - fmod(ray->e[DY], 1);
	else if (ray->face == EAST)
		texoffx = fmod(ray->e[DY], 1);
	//	TODO
	opt = &cub->parse.opt[ray->face];
	img = &opt->img;
	int tex_width = opt->width;
	int tex_height = opt->height;

	for (idx = top; idx < bottom; idx++)
	{
		int dy = idx + (h / 2) - WIN_HEIGHT / 2;
		int texoffsety = dy * ((double)tex_height / h);
		int texoffsetx = texoffx * tex_width;
		color = *(uint *)(img->data + (texoffsetx * img->bpp / 8) + texoffsety * img->lsz);
		//if (ray->face == NORTH) color = 0xFF0000;
		//else if (ray->face == SOUTH) color = 0xFFFF00;
		//else if (ray->face == WEST) color = 0x0000FF;
		//else if (ray->face == EAST) color = 0xFF00FF;
		draw_pixel(i, idx, color, &cub->mlx.img);
	}
}

int	render(t_cub *cub)
{
	draw_bg(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx.pmlx, \
		cub->mlx.pwin, cub->mlx.img.ptr, 0, 0);
	return (1);
}
