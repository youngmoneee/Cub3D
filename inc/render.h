#ifndef RENDER_H
# define RENDER_H

#include "../mlxdir/mlx.h"
#include "structure.h"

int init_win(t_mlx *mlx);
int close_mlx(t_mlx *mlx);
int	render(t_parse *parse, t_mlx *mlx);
#endif