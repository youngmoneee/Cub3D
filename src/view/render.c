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
	int	idx = -1;
	int	h = WIN_HEIGHT / 2 / ray->d / cos((i - WIN_WIDTH / 2) * FOV / WIN_WIDTH);

	while (++idx < h && idx < WIN_HEIGHT / 2)
	{
		draw_pixel(i, WIN_HEIGHT / 2 + idx, 0x424242, &cub->mlx.img);
		draw_pixel(i, WIN_HEIGHT / 2 - idx, 0x424242, &cub->mlx.img);
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
