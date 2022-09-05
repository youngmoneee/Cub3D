/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:49 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/05 23:44:10 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../libft/libft.h"
#include <math.h>

int	close_mlx(t_mlx *mlx)
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
	int	i;
	int	j;

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

static void	draw_ray_sub(t_cub *cub, t_ray *ray, double ex, double ey)
{
	double	sx;
	double	sy;
	int		i;
	double	ofsx;
	double	ofsy;

	sx = 0;
	sy = 0;
	i = -1;
	ofsx = ex / ray->d * N_TILE / MMAP_SZ;
	ofsy = ey / ray->d * N_TILE / MMAP_SZ;
	while (++i < ray->d * MMAP_SZ / N_TILE
		&& fabs(sqrt((sx * sx) + (sy * sy)) - MMAP_SZ / 2) > 1)
	{
		draw_pixel(PAD_X + sx, PAD_Y + sy, 0, &cub->mlx.img);
		sx += ofsx;
		sy += ofsy;
	}
}

void	draw_ray(t_cub *cub, t_ray *ray)
{
	double	ex;
	double	ey;

	ex = (ray->e[DX] - cub->user.x) * MMAP_SZ / N_TILE;
	ey = (ray->e[DY] - cub->user.y) * MMAP_SZ / N_TILE;
}

void	draw_wall(t_cub *cub, t_ray *ray, int i)
{
	int			idx;
	int			h;
	int			top;
	int			bottom;
	double		texoffx;
	t_img		*img;
	t_option	*opt;
	t_uint		color;

	h = WIN_HEIGHT / 2 / ray->d / cos((i - WIN_WIDTH / 2)
			* FOV / WIN_WIDTH) * WIN_WIDTH / WIN_HEIGHT;
	top = WIN_HEIGHT / 2 - h / 2;
	if (top < 0)
		top = 0;
	bottom = WIN_HEIGHT / 2 + h / 2;
	if (bottom >= WIN_HEIGHT)
		bottom = WIN_HEIGHT;
	if (ray->face == NORTH)
		texoffx = 1 - fmod(ray->e[DX], 1);
	else if (ray->face == SOUTH)
		texoffx = fmod(ray->e[DX], 1);
	else if (ray->face == WEST)
		texoffx = 1 - fmod(ray->e[DY], 1);
	else if (ray->face == EAST)
		texoffx = fmod(ray->e[DY], 1);
	opt = &cub->parse.opt[ray->face];
	img = &opt->img;
	int tex_width = opt->width;
	int tex_height = opt->height;

	for (idx = top; idx < bottom; idx++)
	{
		int dy = idx + (h / 2) - WIN_HEIGHT / 2;
		int texoffsety = dy * ((double)tex_height / h);
		int texoffsetx = texoffx * tex_width;
		color = *(t_uint *)(img->data + (texoffsetx * img->bpp / 8) + texoffsety * img->lsz);
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
