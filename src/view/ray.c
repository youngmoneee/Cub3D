#include "../../inc/cub3d.h"
#include <math.h>

static double  shoot(t_cub *cub, double rad, double x, double y)
{
    double  mx = -cos(rad);
    double  my = -sin(rad);
    double  diffX, diffY;
    t_pos   next;
    t_pos   now;

    now.x = cub->user.x;
    now.y = cub->user.y;
    while (!is_wall(cub, now.x, now.y))
    {
	    next.x = mx < 0 ? (int)floor(x) : (int)floor(x + 1);
	    next.y = my < 0 ? (int)floor(y) : (int)floor(y + 1);
        if (fabs((next.x - now.x) / mx) < fabs((next.y - now.y) / my))
        {
            now.y = now.y + (next.x - now.x) * my / mx;
            now.x = next.x;
        }
        else
        {
            now.x = now.x + (next.y - now.y) * mx / my;
            now.y = next.y;
        }
        draw_pixel(PAD_X + now.x * N_TILE, PAD_Y + now.y * N_TILE, 0x1f1f1f, &cub->mlx.img);
	    draw_pixel(PAD_X + now.x * N_TILE - 1, PAD_Y + now.y * N_TILE, 0x1f1f1f, &cub->mlx.img);
	    draw_pixel(PAD_X + now.x * N_TILE + 1, PAD_Y + now.y * N_TILE, 0x1f1f1f, &cub->mlx.img);
    }
    printf("%lf %lf\n", now.x, now.y);
	
	/*while (!is_wall(cub, next.x, next.y))
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
    }*/
	return 0;
}

int ray(t_cub *cub)
{
    double  nx;
    double  ny;
    int     nextX;
    int     nextY;
    /*
    for (int i = 1; i < 100; i++)
	{
		ny = i * -sin(cub->user.radian);
		nx = i * -cos(cub->user.radian);
        printf("%lf %lf\n", nx, ny);
		draw_pixel(PAD_X + nx, PAD_Y + ny, 0, &cub->mlx.img);
        //if (is_wall(cub, cub->user.x + nx, cub->user.y + ny))
		//	break ;
	}
    */
    shoot(cub, cub->user.radian, cub->user.x, cub->user.y);
    //printf("거리 : %lf\n",shoot(cub, cub->user.radian, cub->user.x, cub->user.y));
    return 1;
}