#ifndef CUB3D_H
# define CUB3D_H

#include "structure.h"
#include "parse.h"
#include "render.h"
#include "handler.h"

# define _USE_MATH_DEFINES

/*
 *	KEY CODE
 */

# define X_KEY_PRESS	2
# define X_KEY_REALEASE 3
# define X_KEY_EXIT     17
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_MOTION	6

# define KEY_UP		0x7e
# define KEY_DOWN	0x7d
# define KEY_LEFT	0x7b
# define KEY_RIGHT	0x7c
# define KEY_SPACE	0x31
# define KEY_W      0xd
# define KEY_A      0x0
# define KEY_S      0x1
# define KEY_D      0x2

# define KEY_ESC	0x35
# define RED_DOT	0x11

# define ASP_S		M_PI * 0.5
# define ASP_N		M_PI * 1.5
# define ASP_W		M_PI * 1
# define ASP_E		M_PI * 0

# define DY         0
# define DX         1
# define HORZ       0
# define VERT       1

//	1024 * 768
# define WIN_WIDTH	1024
# define WIN_HEIGHT	768


//	Minimap
# define MMAP_SZ	240
# define PAD_X		(MMAP_SZ / 2) + 30
# define PAD_Y		(MMAP_SZ / 2) + 20
# define N_TILE     8

# define BG_COLOR	0xAAAAAA
# define FRAME		0xFFFFFF
# define GRID		0xFF0000
# define PLAYER     0x000000
# define SPCE       0xFFFFFF
# define WALL       0xFFFF00

/*
 *  Player
 */
# define SPEED      0.8
# define ROTANGLE   ((M_PI) / 180)
# define ROTSPEED	(ROTANGLE) * 1
# define FOV        (60 * ROTANGLE)
# define DIST_CAM   ((WIN_WIDTH / 2) / tan(FOV / 2))

/*
 * Init
 */

void	init(t_cub *cub, char *fname);
bool	init_win(t_mlx *mlx);


/*
 *  Valid
 */

bool	check_boundary(t_cub *cub, int cx, int cy);
bool	is_wall(t_cub *cub, int nx, int ny);
#endif
