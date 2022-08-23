/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:46 by youngpar          #+#    #+#             */
/*   Updated: 2022/08/23 17:17:46 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

static double  shoot(t_cub *cub, double rad, double x, double y)
{
    double  mx = -cos(rad);
    double  my = -sin(rad);
    double  nextX, nextY, diffX, diffY;
    t_pos   next;

	next.x = mx < 0 ? (int)floor(x) : (int)floor(x + 1);
	next.y = my < 0 ? (int)floor(y) : (int)floor(y + 1);
	draw_pixel(PAD_X + nextX, PAD_Y + nextY * N_TILE, 0x1f1f1f, &cub->mlx.img);
	draw_pixel(PAD_X + nextX - 1, PAD_Y + nextY * N_TILE, 0x1f1f1f, &cub->mlx.img);
	draw_pixel(PAD_X + nextX + 1, PAD_Y + nextY * N_TILE, 0x1f1f1f, &cub->mlx.img);
	while (!is_wall(cub, nextX, nextY))
    {
        diffX = nextX - x;
        diffY = nextY - y;
        printf("dx : %lf dy : %lf\n", cub->user.x, cub->user.y);
        if (fabs(diffX / mx) < fabs(diffY / my))
        {
            nextX = x + diffX;
            nextY = y + diffX * (my / mx);
        }
        else
        {
            nextX = x + diffY * (mx / my);
            nextY = y + diffY;
        }
    }
	return 0;
}

int ray(t_cub *cub)
{
    double  nx;
    double  ny;
    int     nextX;
    int     nextY;

        printf("dx : %lf dy : %lf\n", cub->user.x, cub->user.y);
    shoot(cub, cub->user.radian, cub->user.x, cub->user.y);
    //printf("거리 : %lf\n",shoot(cub, cub->user.radian, cub->user.x, cub->user.y));
    return 1;
}
