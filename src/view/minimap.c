/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:42 by youngpar          #+#    #+#             */
/*   Updated: 2022/08/23 17:17:43 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if ((x % (MMAP_SZ / N_TILE) == 0) || (y % (MMAP_SZ / N_TILE) == 0))
		draw_pixel(PAD_X + x, PAD_Y + y, GRID, &cub->mlx.img);
	else
		return (false);
	return (true);
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
			cx = (int)floorl(cub->user.x + (j * N_TILE / (double)MMAP_SZ));
			cy = (int)floorl(cub->user.y + (i * N_TILE / (double)MMAP_SZ));
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
}
