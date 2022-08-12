#ifndef CUB3D_H
# define CUB3D_H

#include "structure.h"
#include "parse.h"
#include "render.h"

/*
 *	KEY CODE
 */

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_MOTION	6

# define KEY_UP		0x7e
# define KEY_DOWN	0x7d
# define KEY_LEFT	0x7b
# define KEY_RIGHT	0x7c
# define KEY_SPACE	0x31

# define KEY_ESC	0x35
# define RED_DOT	0x11

# define ASP_N		M_PI * 0
# define ASP_S		M_PI * 1
# define ASP_W		M_PI * 0.5
# define ASP_E		M_PI * 1.5

//	1024 * 768
# define WIN_WIDTH	1024
# define WIN_HEIGHT	768

//	Minimap
# define MMAP_W		160
# define MMAP_H		120
# define PAD_X		(MMAP_W / 2) + 40
# define PAD_Y		(MMAP_H / 2) + 30

# define BG_COLOR	0xAAAAAA
# define FRAME		0xFFFFFF
# define GRID		0xFF0000

/*
 * Init
 */

void	init(t_cub *cub, char *fname);
bool	init_win(t_mlx *mlx);

#endif
