#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

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
# define RED_DOT	0xA1

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

/*
 *	SHORT TYPE NAME
 */

typedef unsigned int	uint;
typedef unsigned char	uchar;

/*
 *	KIND OF OPTION
 */

typedef enum			e_options
{
	FLOOR,
	CEIL,
	EAST,
	WEST,
	NORTH,
	SOUTH,
	UNKNOWN
}						t_options;

/*
 *	
 */

typedef struct s_img
{
	void	*ptr;
	uchar	*data;
	uint	lsz;
	uint	bpp;
	int		endian;
	double	aspect;
}	t_img;

/*
 *	map[height][width]
 */

typedef struct s_map
{
	char	**map;
	uint	width;
	uint	height;
	bool	is_parsed;
	bool	is_valided;
}	t_map;

/*
 *	option
 */

typedef struct s_option
{
	int		fd;
	t_img	img;
	uint	color;
	bool	parsed;
	bool	valided;
}	t_option;

typedef struct s_parse
{
	char		*file;
	int			fd;
	t_option	opt[6];
	t_map		map;
	bool		is_parsed;
	bool		is_valided;
}	t_parse;

typedef struct s_player t_player;
typedef struct s_pos t_pos;
typedef struct s_mlx t_mlx;
typedef struct s_win t_win;

#endif
