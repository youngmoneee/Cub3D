#include "../../inc/cub3d.h"
#include <math.h>

static bool	draw_minimap(t_cub *cub, int x, int y)
{
	double	dist;

	dist = round(sqrt(x * x + y * y));
	if (dist >= (MMAP_SZ / 2 - 1))
	{
		if (dist <= (MMAP_SZ / 2))
			draw_pixel(PAD_X + x, PAD_Y + y, GRID, &cub->mlx.img);			
		return (true);
	}
	if (x <= 2 && y <= 2 && x >= -2 && y >= -2)
		draw_pixel(PAD_X + x, PAD_Y + y, PLAYER, &cub->mlx.img);			
	else if ((x == (-MMAP_SZ / 2)) || (x == (MMAP_SZ / 2))
		|| (y == (-MMAP_SZ / 2)) || (y == (MMAP_SZ / 2)))
		draw_pixel(PAD_X + x, PAD_Y + y, FRAME, &cub->mlx.img);
	else if ((x % (MMAP_SZ / N_TILE) == 0) || (y % (MMAP_SZ / N_TILE) == 0))
		draw_pixel(PAD_X + x, PAD_Y + y, GRID, &cub->mlx.img);
	else if (atan2(x - cub->user.x, y - cub->user.y) * M_PI == cub->user.radian)
		draw_pixel(PAD_X + x, PAD_Y + y, 0xFAFAFA, &cub->mlx.img);
	else
		return (false);
	return (true);
}

static void	draw_ray(t_cub *cub, int len)
{
	double	x;
	double	y;
	double	ox;
	double	oy;
	double	dist;

	ox = cub->user.x;
	oy = cub->user.y;
	//x = cos(cub->user.radian) * (ROTANGLE);
	//y = sin(cub->user.radian) * (ROTANGLE);
	printf("%lf\n", x/ y);
	dist = 1;
	/*
	while (dist <= len)
	{
		ox -= x;
		oy -= y;
		ox = round(ox);
		oy = round(oy);
		dist = sqrt(pow(cub->user.x - ox, 2.0) + pow(cub->user.y - oy, 2.0));
		//printf("%lf %lf %lf\n", x, y, dist);
		draw_pixel(PAD_X + ox, PAD_Y + oy, 0xFF0000, &cub->mlx.img);
	}
	 */
	for (int i = 1; i < len; i++)
	{
		x = i * sin(cub->user.radian);
		y = i * cos(cub->user.radian);
		draw_pixel(PAD_X - y, PAD_Y - x, 0, &cub->mlx.img);
	}
}

void	draw_mmap(t_cub *cub)
{
	int i;
	int j;
	int cx;
	int cy;

	i = -MMAP_SZ / 2 - 1;
	while (++i <= MMAP_SZ / 2)
	{
		j = -MMAP_SZ / 2 - 1;
		while (++j <= MMAP_SZ / 2)
		{
			cx = (int)round(cub->user.x + (j * N_TILE / (double)MMAP_SZ));
			cy = (int)round(cub->user.y + (i * N_TILE / (double)MMAP_SZ));
			if (draw_minimap(cub, j, i))
				continue ;
			else if (check_boundary(cub, cx, cy))
				draw_pixel(PAD_X + j, PAD_Y + i, SPCE, &cub->mlx.img);
			else if (cub->parse.map.map[cy][cx] == '1')
				draw_pixel(PAD_X + j, PAD_Y + i, WALL, &cub->mlx.img);
			else if (cub->parse.map.map[cy][cx] == '0')
				draw_pixel(PAD_X + j, PAD_Y + i, \
				cub->parse.opt[FLOOR].color, &cub->mlx.img);
		}
	}
	draw_ray(cub, 100);
}