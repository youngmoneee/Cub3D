#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

typedef unsigned int	uint;
typedef unsigned char	uchar;
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
 *	map[height][width]
 */

typedef struct s_img
{
	void	*ptr;
	uchar	*data;
	uint	width;
	uint	height;
	double	aspect;
}	t_img;

typedef struct s_map
{
	char	**map;
	uint	width;
	uint	height;
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
}	t_parse;

typedef struct s_player t_player;
typedef struct s_pos t_pos;
typedef struct s_mlx t_mlx;
typedef struct s_win t_win;

#endif
