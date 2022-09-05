/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:07:50 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/05 23:02:31 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/util.h"
#include <math.h>

static void	horizon_check_sub(t_cub *cub, t_ray *ray)
{
	double	x;
	double	y;

	while (!is_wall(cub, ray->end[HORZ][DX], ray->end[HORZ][DY]))
	{
		x = ray->end[HORZ][DX];
		if (is_up(ray->angle))
			y = ray->end[HORZ][DY] + -1;
		else
			y = ray->end[HORZ][DY];
		if (is_wall(cub, x, y))
			break ;
		ray->end[HORZ][DX] += ray->step[HORZ][DX];
		ray->end[HORZ][DY] += ray->step[HORZ][DY];
	}
	ray->dist[HORZ] = dist_btwen(cub->user.x, ray->end[HORZ][DX],
			cub->user.y, ray->end[HORZ][DY]);
}

void	horizon_check(t_cub *cub, t_ray *ray)
{
	ray->start[HORZ][DY] = floor(cub->user.y) + is_down(ray->angle);
	ray->start[HORZ][DX] = cub->user.x + (ray->start[HORZ][DY] - cub->user.y)
		/ tan(ray->angle);
	if (is_up(ray->angle))
		ray->step[HORZ][DY] = -1;
	else
		ray->step[HORZ][DY] = 1;
	ray->step[HORZ][DX] = 1 / tan(ray->angle);
	if (is_left(ray->angle) && ray->step[HORZ][DX] > 0)
		ray->step[HORZ][DX] *= -1;
	else
		ray->step[HORZ][DX] *= 1;
	if (is_right(ray->angle) && ray->step[HORZ][DX] < 0)
		ray->step[HORZ][DX] *= -1;
	else
		ray->step[HORZ][DX] *= 1;
	ray->end[HORZ][DX] = ray->start[HORZ][DX];
	ray->end[HORZ][DY] = ray->start[HORZ][DY];
	horizon_check_sub(cub, ray);
}

static void	vertical_check_sub(t_cub *cub, t_ray *ray)
{
	double	x;
	double	y;

	while (!is_wall(cub, ray->end[VERT][DX], ray->end[VERT][DY]))
	{
		if (is_left(ray->angle))
			x = ray->end[VERT][DX] - 1;
		else
			x = ray->end[VERT][DX];
		y = ray->end[VERT][DY];
		if (is_wall(cub, x, y))
			break ;
		ray->end[VERT][DX] += ray->step[VERT][DX];
		ray->end[VERT][DY] += ray->step[VERT][DY];
	}
	ray->dist[VERT] = dist_btwen(cub->user.x, ray->end[VERT][DX],
			cub->user.y, ray->end[VERT][DY]);
}

void	vertical_check(t_cub *cub, t_ray *ray)
{
	ray->start[VERT][DX] = floor(cub->user.x) + is_right(ray->angle);
	ray->start[VERT][DY] = cub->user.y
		+ (ray->start[VERT][DX] - cub->user.x) * tan(ray->angle);
	if (is_left(ray->angle))
		ray->step[VERT][DX] = -1;
	else
		ray->step[VERT][DX] = 1;
	ray->step[VERT][DY] = 1 * tan(ray->angle);
	if (is_up(ray->angle) && ray->step[VERT][DY] > 0)
		ray->step[VERT][DY] *= -1;
	else
		ray->step[VERT][DY] *= 1;
	if (is_down(ray->angle) && ray->step[VERT][DY] < 0)
		ray->step[VERT][DY] *= -1;
	else
		ray->step[VERT][DY] *= 1;
	ray->end[VERT][DX] = ray->start[VERT][DX];
	ray->end[VERT][DY] = ray->start[VERT][DY];
	vertical_check_sub(cub, ray);
}
