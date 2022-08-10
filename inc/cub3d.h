#ifndef CUB3D_H
# define CUB3D_H

#include "structure.h"
#include "parse.h"
#include "render.h"

/*
 * Init
 */

void	init(t_parse *parse, char *fname);
bool	init_win(t_mlx *mlx);

#endif
