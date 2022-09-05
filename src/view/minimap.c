/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:42 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/05 23:02:17 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

static bool	draw_minimap(t_cub *cub, int x, int y)
{
	double	dist;

	dist = sqrt(x * x + y * y);
	if (dist > MMAP_SZ / 2)
		return (true);
	if (dist >= (MMAP_SZ / 2 - 1) && dist < (MMAP_SZ / 2))
		draw_pixel(PAD_X + x, PAD_Y + y, GRID, &cub->mlx.img);
	else if (dist <= 2)
		draw_pixel(PAD_X + x, PAD_Y + y, PLAYER, &cub->mlx.img);
	else if (!(x % (MMAP_SZ / N_TILE) && (y % (MMAP_SZ / N_TILE))))
		draw_pixel(PAD_X + x, PAD_Y + y, GRID, &cub->mlx.img);
	else
		return (false);
	return (true);
}

void	draw_mmap(t_cub *cub)
{
	int	i;
	int	j;
	int	cx;
	int	cy;

	i = -MMAP_SZ / 2 - 1;
	while (++i <= MMAP_SZ / 2)
	{
		j = -MMAP_SZ / 2 - 1;
		while (++j <= MMAP_SZ / 2)
		{
			if (draw_minimap(cub, j, i))
				continue ;
			cx = (int)(cub->user.x + (j * N_TILE / (double)MMAP_SZ));
			cy = (int)(cub->user.y + (i * N_TILE / (double)MMAP_SZ));
			if (check_boundary(cub, cx, cy))
				draw_pixel(PAD_X + j, PAD_Y + i, SPCE, &cub->mlx.img);
			else if (cub->parse.map.map[cy][cx] == '1')
				draw_pixel(PAD_X + j, PAD_Y + i, WALL, &cub->mlx.img);
			else if (cub->parse.map.map[cy][cx] == '0')
				draw_pixel(PAD_X + j, PAD_Y + i, \
				cub->parse.opt[FLOOR].color, &cub->mlx.img);
		}
	}
}
