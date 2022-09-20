/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:42:45 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/20 19:38:22 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structure.h"
# include "parse.h"
# include "render.h"
# include "handler.h"
# include "util.h"

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

# define ASP_S		1.570796
# define ASP_N		4.712388
# define ASP_W		3.141592
# define ASP_E		0

# define DY         0
# define DX         1
# define HORZ       0
# define VERT       1

//	1024 * 768
# define WIN_WIDTH	640
# define WIN_HEIGHT	480

# define BOX_SZ     WIN_HEIGHT

//	Minimap
# define MMAP_SZ	240
# define PAD_X		150
# define PAD_Y		140
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
# define ROTANGLE   0.0174532888
# define ROTSPEED	0.0174532888
# define FOV		1.0471973333

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
