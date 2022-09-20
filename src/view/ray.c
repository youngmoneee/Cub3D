/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:07:50 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/20 20:18:07 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/util.h"
#include <math.h>

static int	wall_dir(t_ray *ray)
{
	if (ray->e[DX] == (int)ray->e[DX])
	{
		if (is_left(ray->angle))
			return (WEST);
		return (EAST);
	}
	if (is_up(ray->angle))
		return (SOUTH);
	return (NORTH);
}

static void	shoot(t_cub *cub, t_ray *ray)
{
	horizon_check(cub, ray);
	vertical_check(cub, ray);
	if (ray->dist[HORZ] < ray->dist[VERT])
	{
		ray->s[DX] = ray->start[HORZ][DX];
		ray->s[DY] = ray->start[HORZ][DY];
		ray->e[DX] = ray->end[HORZ][DX];
		ray->e[DY] = ray->end[HORZ][DY];
		ray->offset[DX] = ray->step[HORZ][DX];
		ray->offset[DY] = ray->step[HORZ][DY];
		ray->d = ray->dist[HORZ];
	}
	else
	{
		ray->s[DX] = ray->start[VERT][DX];
		ray->s[DY] = ray->start[VERT][DY];
		ray->e[DX] = ray->end[VERT][DX];
		ray->e[DY] = ray->end[VERT][DY];
		ray->offset[DX] = ray->step[VERT][DX];
		ray->offset[DY] = ray->step[VERT][DY];
		ray->d = ray->dist[VERT];
	}
	ray->face = wall_dir(ray);
}

int	raycast(t_cub *cub)
{
	int		i;
	t_ray	ray[WIN_WIDTH];

	i = -1;
	ft_memset(&ray, 0, sizeof(t_ray) * WIN_WIDTH);
	while (++i < WIN_WIDTH)
	{
		ray[i].angle = cub->user.radian + (i - WIN_WIDTH / 2) * FOV / WIN_WIDTH;
		ray[i].angle = normalize(ray[i].angle);
		shoot(cub, &ray[i]);
		draw_wall(cub, &ray[i], i);
	}
	draw_mmap(cub);
	i = -1;
	while (++i < WIN_WIDTH)
		if (i % 32 == 0)
			draw_ray(cub, &ray[i]);
	return (1);
}
