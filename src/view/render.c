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
	ex = ray->e[DX] - cub->user.x;
	ey = ray->e[DY] - cub->user.y;
	longe = (fabs(ex) >= fabs(ey) ? fabs(ex) : fabs(ey));
	//printf("%lf %lf\n", sqrt((ex - sx) * (ex - sx) + (ey - sy) * (ey - sy)), ray->d);
	/*
	while(sqrt((ex - sx) * (ex - sx) + (ey - sy) * (ey - sy)) < ray->d)
	{
		sx += ray->offset[DX] / N_TILE;
		sy += ray->offset[DY] / N_TILE;
		draw_pixel(PAD_X + sx * (MMAP_SZ / N_TILE), PAD_Y + sy * (MMAP_SZ / N_TILE), 0, &cub->mlx.img);
	}
	*/
	ofsx = ex / longe;
	ofsy = ey / longe;
	while (sqrt((ex - sx) * (ex - sx) + (ey - sy) * (ey - sy))) {
		sx += ofsx / N_TILE;
		sy += ofsy / N_TILE;
		draw_pixel(PAD_X + sx * (MMAP_SZ / N_TILE / 2), PAD_Y + sy * (MMAP_SZ / N_TILE / 2), 0, &cub->mlx.img);
	}
}

int	render(t_cub *cub)
{
	draw_bg(cub);
	draw_mmap(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx.pmlx, \
		cub->mlx.pwin, cub->mlx.img.ptr, 0, 0);
	return (1);
}
