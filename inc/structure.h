#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include "../mlxdir/mlx.h"

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
	char	*data;
	int		lsz;
	int		bpp;
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

typedef struct s_user
{
	double	x;
	double	y;
	double	radian;
	bool		is_parsed;
	bool		is_valided;
} t_user;
typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	larw;
	bool	rarw;
}	t_key;
typedef struct s_mlx
{
	void	*pmlx;
	void	*pwin;
	t_img	img;
}	t_mlx;
typedef struct s_cub
{
	t_mlx	mlx;
	t_user	user;
	t_parse	parse;
	t_key	key;
}	t_cub;

#endif