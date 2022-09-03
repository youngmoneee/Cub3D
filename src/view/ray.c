#include "../../inc/cub3d.h"
#include "../../inc/util.h"
#include <math.h>

static double   dist_btwen(double x1, double x2, double y1, double y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static bool is_down(double angle)
{
    return (angle > 0 && angle < M_PI);
}
static bool is_up(double angle)
{
    return (!is_down(angle));
}
static bool is_left(double angle)
{
    return (angle > 0.5 * M_PI && angle < 1.5 * M_PI);
}
static bool is_right(double angle)
{
    return (!is_left(angle));
}

static void    horizon_check(t_cub *cub, t_ray *ray)
{
    double  x;
    double  y;

    ray->start[HORZ][DY] = floor(cub->user.y) + is_down(ray->angle);
    ray->start[HORZ][DX] = cub->user.x + (ray->start[HORZ][DY] - cub->user.y) / tan(ray->angle);
    
    ray->step[HORZ][DY] = is_up(ray->angle) ? -1 : 1;
    ray->step[HORZ][DX] = 1 / tan(ray->angle);

    ray->step[HORZ][DX] *= (is_left(ray->angle) && ray->step[HORZ][DX] > 0) ? -1 : 1;
    ray->step[HORZ][DX] *= (is_right(ray->angle) && ray->step[HORZ][DX] < 0) ? -1 : 1;
    ray->end[HORZ][DX] = ray->start[HORZ][DX];
    ray->end[HORZ][DY] = ray->start[HORZ][DY];
    while (!is_wall(cub, ray->end[HORZ][DX], ray->end[HORZ][DY]))
    {
        x = ray->end[HORZ][DX];
        y = ray->end[HORZ][DY] + (is_up(ray->angle) ? -1 : 0);
        if (is_wall(cub, x, y))
            break ;
        ray->end[HORZ][DX] += ray->step[HORZ][DX];
        ray->end[HORZ][DY] += ray->step[HORZ][DY];
    }
    ray->dist[HORZ] = dist_btwen(cub->user.x, ray->end[HORZ][DX], cub->user.y, ray->end[HORZ][DY]);
}

static void     vertical_check(t_cub *cub, t_ray *ray)
{
    double  x;
    double  y;

    ray->start[VERT][DX] = floor(cub->user.x) + is_right(ray->angle);
    ray->start[VERT][DY] = cub->user.y + (ray->start[VERT][DX] - cub->user.x) * tan(ray->angle);
    
    ray->step[VERT][DX] = is_left(ray->angle) ? -1 : 1;
    ray->step[VERT][DY] = 1 * tan(ray->angle);

    ray->step[VERT][DY] *= (is_up(ray->angle) && ray->step[VERT][DY] > 0) ? -1 : 1;
    ray->step[VERT][DY] *= (is_down(ray->angle) && ray->step[VERT][DY] < 0) ? -1 : 1;
    
    ray->end[VERT][DX] = ray->start[VERT][DX];
    ray->end[VERT][DY] = ray->start[VERT][DY];
    while (!is_wall(cub, ray->end[VERT][DX], ray->end[VERT][DY]))
    {
        x = ray->end[VERT][DX] + (is_left(ray->angle) ? -1 : 0);
        y = ray->end[VERT][DY];
        if (is_wall(cub, x, y))
            break ;
        ray->end[VERT][DX] += ray->step[VERT][DX];
        ray->end[VERT][DY] += ray->step[VERT][DY];
    }
    ray->dist[VERT] = dist_btwen(cub->user.x, ray->end[VERT][DX], cub->user.y, ray->end[VERT][DY]);
}

static void  shoot(t_cub *cub, t_ray *ray, int col)
{
    //  check horizon
    horizon_check(cub, ray);

    //  check vertical
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
}

int raycast(t_cub *cub)
{
    int     i;
    t_ray   ray[WIN_WIDTH];

    i = -1;
    ft_memset(&ray, 0, sizeof(t_ray) * WIN_WIDTH);
    while (++i < WIN_WIDTH)
    {
        ray[i].angle = cub->user.radian + (i - WIN_WIDTH / 2) * FOV / WIN_WIDTH;//atan((i - WIN_WIDTH / 2) / DIST_CAM);
        ray[i].angle = normalize(ray[i].angle);
        shoot(cub, &ray[i], i);
        if (i % 20 == 0)
        {
            draw_ray(cub, &ray[i]);
        }
        //draw_wall(cub, &ray[i]);
    }
    return 1;
}