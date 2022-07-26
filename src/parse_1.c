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

#include "../inc/structure.h"

static bool	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

bool		is_valid(char *line, t_parse *parse)
{
	char	buf;

	while (*line == ' ')
		line++;
	buf = *line++;
	while (*line == ' ')
		line++;
}

void	mkmap(t_parse *parse, int x, int y)
{
	char	buf;
	int		is_read;
	t_map	*map;

	map = &parse->map;
	is_read = read(parse->fd, &buf, 1);
	parse->map.width = max(parse->map.width, x);
	parse->map.height = max(parse->map.height, y);
	if (is_read == false)
	{
		parse->map->map = (char **)malloc(sizeof(char *) * (parse->map.height + 1));
		if (parse->map.map)
			parse->map.map[parse->map.height] = 0;
		return ;
	}
	if (buf == '\n')
	{
		mkmap(parse, 0, y + 1);
		parse->map.map[y] = (char *)malloc(sizeof(char) * (parse->map.width + 1));
		while (x < parse->map.width)
			parse->map.map[y][x++] = ' ';
		parse->map.map[y][parse->map.width] = 0;
		return ;
	}
	mkmap(parse, x + 1, y);
	parse->map.map[y][x] = buf;
}
