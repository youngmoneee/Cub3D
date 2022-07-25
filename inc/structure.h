#ifndef STRUCTURE_H
# define STRUCTURE_H

#define FALSE 0
#define TRUE 1

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;
typedef struct s_parse
{
	char	*file;
	int		fd;
	char	*ceil;
	char	*floor;
	char	*east;
	char	*west;
	char	*south;
	char	*west;
	t_map	map;
}
typedef struct player;
typedef struct pos;
typedef struct mlx;
typedef struct win;

#endif
