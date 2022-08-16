#include "../../inc/cub3d.h"
#include <math.h>

static double  shoot_y(t_cub *cub, double rad, double x, double y)
{
    double mx = -cos(rad);
    double my = -sin(rad);
    double nextX, nextY, diffX, diffY;

    printf("%lf %lf\n", x, y);
	draw_pixel(PAD_X - x, PAD_Y - y, 0, &cub->mlx.img);
    //if (cub->parse.map.map[(int)ceil(y)][(int)ceil(x)] == '1')
    //    return sqrt(pow(x - cub->user.x, 2.0) + pow(y - cub->user.y, 2.0));
    if (mx < 0) nextX = (int)floor(x);
    else nextX = (int)floor(x + 1);
    if (my < 0) nextY = (int)floor(y);
    else nextY = (int)floor(y + 1);
    diffX = nextX - x;
    diffY = nextY - y;
    printf("origin : %lf %lf\n", x, y);
    for (int i = 0;i < 10; i++) {
        printf("X : %.3lf Y : %.3lf\n", x, y);
        if (mx < 0) nextX = (int)floor(x);
        else nextX = (int)floor(x + 1);
        if (my < 0) nextY = (int)floor(y);
        else nextY = (int)floor(y + 1);
        diffX = nextX - x;
        diffY = nextY - y;
        
        if (fabs(diffX) < fabs(diffY)) {
            x += diffX;
            y += diffY * my / mx;
        }
        else {
            x += diffX * mx / my;
            y += diffY;
        }
        //printf("1step x : %lf %lf\n", x + diffX, y + diffY * my / mx);
        //printf("1step y : %lf %lf\n", x + diffX * mx/my, y + diffY);
    }
    /*
    diffX = nextX - x;
    diffY = nextY - y;
    if (fabs(diffX) < fabs(diffY))
    {
        if (diffY && diffX)
            shoot_y(cub, rad, x + diffX, y + diffY/diffX);
        else
            shoot_y(cub, rad, x + diffX, y);
    }
    else
    {
        if (diffX)
            shoot_y(cub, rad, x + diffX, y + diffY/diffX);
        else
            shoot_y(cub, rad, x, y + diffY);
    }
    */
    return 0;
}

int ray(t_cub *cub)
{
    double  nx;
    double  ny;
    int     nextX;
    int     nextY;

    nx = -cos(cub->user.radian);
    ny = -sin(cub->user.radian);

    if (nx < 0) nextX = (int)floor(cub->user.x);
    else nextX = (int)floor(cub->user.x + 1);
    if (ny < 0) nextY = (int)floor(cub->user.y);
    else nextY = (int)floor(cub->user.y + 1);
    shoot_y(cub, cub->user.radian, cub->user.x, cub->user.y);
    //printf("방향 : %lf %lf\n", nx, ny);
    //printf("차이 : [X : %lf] [Y : %lf]\n", fabs(nextX - cub->user.x), fabs(nextY - cub->user.y));
    return 1;
}