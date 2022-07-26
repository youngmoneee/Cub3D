#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

typedef unsigned int	uint;

/*
 *	map[height][width]
 */

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

/*
 *	option
 */

typedef struct s_option
{
	char	*path;
	uint	color;
	bool	parsed;
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
