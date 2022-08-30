#ifndef RENDER_H
# define RENDER_H

#include "../mlxdir/mlx.h"
#include "structure.h"

int close_mlx(t_mlx *mlx);
int	render(t_cub *cub);
void	draw_pixel(int x, int y, unsigned color, t_img *img);
void	draw_bg(t_cub *cub);
void	draw_mmap(t_cub *cub);
int     raycast(t_cub *cub);
#endif