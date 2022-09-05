/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:16:45 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/05 22:22:16 by ykm1256          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../mlxdir/mlx.h"
#include "../../inc/util.h"

bool	is_wall(t_cub *cub, int nx, int ny)
{
	if ((nx < 0) || (nx >= cub->parse.map.width)
		|| (ny < 0) || (ny >= cub->parse.map.height))
		return (true);
	return (cub->parse.map.map[(int)ny][(int)nx] == '1');
}

static	void	cal_n(double *nx, double *ny, t_cub *cub)
{
	double	mx;
	double	my;

	mx = cos(cub->user.radian) * (ROTANGLE) * SPEED;
	my = sin(cub->user.radian) * (ROTANGLE) * SPEED;
	if (cub->key.w)
	{
		*ny += my;
		*nx += mx;
	}
	if (cub->key.s)
	{
		*ny -= my;
		*nx -= mx;
	}
	if (cub->key.a)
	{
		*ny -= mx;
		*nx += my;
	}
	if (cub->key.d)
	{
		*ny += mx;
		*nx -= my;
	}
}

void	move(t_cub *cub)
{
	double	nx;
	double	ny;

	nx = cub->user.x;
	ny = cub->user.y;
	cal_n(&nx, &ny, cub);
	if (!is_wall(cub, nx, ny))
	{
		cub->user.x = nx;
		cub->user.y = ny;
	}
	else if (!is_wall(cub, nx, cub->user.y))
		cub->user.x = nx;
	else if (!is_wall(cub, cub->user.x, ny))
		cub->user.y = ny;
}

void	rotate(t_cub *cub)
{
	if (cub->key.larw)
		cub->user.radian -= ROTSPEED;
	if (cub->key.rarw)
		cub->user.radian += ROTSPEED;
	cub->user.radian = normalize(cub->user.radian);
}
