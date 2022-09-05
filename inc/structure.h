/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:34:12 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/05 21:57:06 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "../mlxdir/mlx.h"

/*
 *	SHORT TYPE NAME
 */

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

/*
 *	KIND OF OPTION
 */

typedef enum e_options
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
	int		width;
	int		height;
}	t_option;

typedef struct s_parse
{
	char		*file;
	int			fd;
	t_option	opt[6];
	t_map		map;
	bool		is_parsed;
	bool		is_valided;
	void		*mlx;
}	t_parse;

typedef struct s_user
{
	double		x;
	double		y;
	double		radian;
	bool		is_parsed;
	bool		is_valided;
}	t_user;
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
typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;
typedef struct s_ray
{
	double	angle;
	double	start[2][2];
	double	step[2][2];
	double	end[2][2];
	double	dist[2];
	double	s[2];
	double	e[2];
	double	d;
	double	offset[2];
	int		face;
	bool	hit;
}	t_ray;
#endif
