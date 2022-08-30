#include "../../inc/cub3d.h"
#include "../../inc/util.h"
#include <math.h>

static double   dist_btwen(double x1, double x2, double y1, double y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static void    horizon_check(t_cub *cub, t_ray *ray)
{
    ray->dest[DY] = floor(cub->user.y) + !((ray->direction >> 1) & 0b1);
    ray->dest[DX] = cub->user.x + (ray->dest[DY] - cub->user.y) / tan(ray->angle);
    ray->step[DY] = ((ray->direction >> 1) & 0b1) ? -1 : 1;
    ray->step[DX] = 1 / tan(ray->angle);
    ray->step[DX] *= ((ray->direction & 0b1) && ray->step[DX] > 0) ? -1 : 1;
    ray->step[DX] *= (!(ray->direction & 0b1) && ray->step[DX] < 0) ? -1 : 1;
    ray->hit_x[HORZ] = ray->dest[DX];
    ray->hit_y[HORZ] = ray->dest[DY];
    while (!is_wall(cub, ray->hit_x[HORZ], ray->hit_y[HORZ]))
    {
        double cx = ray->hit_x[HORZ];
        double cy = ray->hit_y[HORZ] - ((ray->direction >> 1) & 0b1);
        draw_pixel(PAD_X + ray->hit_x[HORZ], PAD_Y + ray->hit_y[HORZ], 0xFF0000, &cub->mlx.img);
        ray->hit_x[HORZ] += ray->step[DX];
        ray->hit_x[HORZ] += ray->step[DY];
    }
    ray->dist[HORZ] = dist_btwen(cub->user.x, ray->hit_x[HORZ], cub->user.y, ray->hit_y[HORZ]);
}

static void     vertical_check(t_cub *cub, t_ray *ray)
{
    ray->dest[DX] = floor(cub->user.x) + !(ray->direction & 0b1);
    ray->dest[DY] = cub->user.y + (ray->dest[DX] - cub->user.x) * tan(ray->angle);
    ray->step[DX] = (ray->direction & 0b1) ? -1 : 1;
    ray->step[DY] = 1 * tan(ray->angle);
    ray->step[DY] *= ((ray->direction >> 1) & 0b1) && ray->step[DY] > 0 ? -1 : 1;
    ray->step[DY] *= (!(ray->direction & 0b1) && ray->step[DY] < 0) ? -1 : 1;
    ray->hit_x[VERT] = ray->dest[DX];
    ray->hit_y[VERT] = ray->dest[DY];
    while (!is_wall(cub, ray->hit_x[VERT], ray->hit_y[VERT]))
    {
        double cx = ray->hit_x[VERT];
        double cy = ray->hit_y[VERT] - ((ray->direction >> 1) & 0b1);
        draw_pixel(PAD_X + ray->hit_x[VERT], PAD_Y + ray->hit_y[VERT], 0xFF0000, &cub->mlx.img);
        ray->hit_x[VERT] += ray->step[DX];
        ray->hit_x[VERT] += ray->step[DY];
    }
    ray->dist[VERT] = dist_btwen(cub->user.x, ray->hit_x[VERT], cub->user.y, ray->hit_y[VERT]);
}

static void  shoot(t_cub *cub, t_ray *ray, int col)
{
 
    //  next horizon


    //  next vertical
    
}

int raycast(t_cub *cub)
{
    int     i;
    t_ray   ray[WIN_WIDTH];

    i = -1;
    ft_memset(&ray, 0, sizeof(t_ray) * WIN_WIDTH);
    while (++i < WIN_WIDTH)
    {
        ray[i].angle = cub->user.radian + atan((i - WIN_WIDTH/2) / DIST_CAM);
        ray[i].angle = normalize(ray[i].angle);
        //  up direction : 0b1x down 0b0x
        ray[i].direction |= (ray->angle > 0 && ray->angle < M_PI ? 0b10 : 0b00);
        //  left direction : 0bx1 right 0bx0
        ray[i].direction |= (ray->angle > M_PI * 0.5 && ray->angle < M_PI * 1.5 ? 0b01 : 0b00);
        shoot(cub, &ray[i], i);
    }
    return 1;
}