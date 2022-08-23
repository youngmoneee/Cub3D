#include "../../inc/cub3d.h"
#include <math.h>

static double  shoot(t_cub *cub, double rad, double x, double y)
{
    double mx = -cos(rad);
    double my = -sin(rad);
    double nextX, nextY, diffX, diffY;

	nextX = mx < 0 ? (int)floor(x) : (int)floor(x + 1);
	nextY = my < 0 ? (int)floor(y) : (int)floor(y + 1);
	draw_pixel(PAD_X + nextX, PAD_Y + nextY * N_TILE, 0x1f1f1f, &cub->mlx.img);
	draw_pixel(PAD_X + nextX - 1, PAD_Y + nextY * N_TILE, 0x1f1f1f, &cub->mlx.img);
	draw_pixel(PAD_X + nextX + 1, PAD_Y + nextY * N_TILE, 0x1f1f1f, &cub->mlx.img);
	if (is_wall(cub, nextX, nextY))
		return sqrt(pow(nextX - cub->user.x, 2.0) + pow(nextY - cub->user.y, 2.0));
    diffX = nextX - x;
    diffY = nextY - y;
	printf("dx : %lf dy : %lf\n", diffX, diffY);
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
	return (shoot(cub, rad, nextX, nextY));
}

int ray(t_cub *cub)
{
    double  nx;
    double  ny;
    int     nextX;
    int     nextY;

	/*
    nx = -cos(cub->user.radian);
    ny = -sin(cub->user.radian);

    if (nx < 0) nextX = (int)floor(cub->user.x);
    else nextX = (int)floor(cub->user.x + 1);
    if (ny < 0) nextY = (int)floor(cub->user.y);
    else nextY = (int)floor(cub->user.y + 1);
    */
    printf("거리 : %lf\n",shoot(cub, cub->user.radian, cub->user.x, cub->user.y));
    //printf("방향 : %lf %lf\n", nx, ny);
    //printf("차이 : [X : %lf] [Y : %lf]\n", fabs(nextX - cub->user.x), fabs(nextY - cub->user.y));
    return 1;
}