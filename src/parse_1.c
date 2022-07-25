/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:33:09 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/28 21:45:36 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../inc/structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

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
	char	*north;
	t_map	map;
}	t_parse;
	
int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	mkmap(t_parse *parse, int x, int y)
{
	char	buf;
	int		is_read;
	t_map	*map;

	map = &parse->map;
	is_read = read(parse->fd, &buf, 1);
	map->width = max(map->width, x);
	map->height = max(map->height, y + 1);
	if (is_read == FALSE)
	{
		map->map = (char **)malloc(sizeof(char *) * (y + 1));
		if (map->map)
			map->map[y] = 0;
		return ;
	}
	if (buf == '\n')
	{
		mkmap(parse, 0, y + 1);
		map->map[y] = (char *)malloc(sizeof(char) * (map->width));
		while (x < map->width - 1)
			map->map[y][x++] = ' ';
		map->map[y][x] = 0;
	}
	else
	{
		mkmap(parse, x + 1, y);
		map->map[y][x] = buf;
	}
}

int main() {
	t_parse parse;
	parse.map.width = 0;
	parse.map.height = 0;
	parse.fd = open("./test", O_RDONLY, 0777);
	mkmap(&parse, 0, 0);
	for (int i = 0; i < parse.map.height; i++) {
		printf("%s\n", parse.map.map[i]);
	}
	return 0;
}
