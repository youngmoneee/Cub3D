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
#include "../inc/parse.h"
#include "../libft/libft.h"
#include "../inc/util.h"

static void	parse_init(t_parse *parse, char *fname)
{
	uint	idx;

	if (ft_strlen(fname) <= ft_strlen(".cub")
		|| ft_strncmp(fname + ft_strlen(fname) - 4, ".cub", 5))
		exit_msg("Wrong File Format");
	parse->file = fname;
	parse->fd = open(parse->file, O_RDONLY);
	if (parse->fd < 0)
	{
		perror("Wrong File Name");
		exit(1);
	}
	idx = -1;
	while (++idx < 6)
	{
		parse->opt[idx].parsed = false;
		parse->opt[idx].valided = false;
		parse->opt[idx].color = 0xFF000000;
	}
	parse->map.width = 0;
	parse->map.height = 0;
}

bool	parsing(t_parse *parse, char *fname)
{
	char	*line;
	char	*freer;
	bool	ret;

	ret = true;
	parse_init(parse, fname);
	while ((line = gnl(parse->fd, 0)))
	{
		freer = line;
		while (*line == ' ')
			line++;
		if (*line == 'C' || *line == 'F')
			set_color(line, parse->opt);
		else if (*line == 'E' || *line == 'W' || *line == 'N' || *line == 'S')
			set_path(line, parse->opt);
		free(freer);
	}
	return (ret);
}

void	mkmap(t_parse *parse, int x, int y)
{
	char	buf;
	int		is_read;

	is_read = read(parse->fd, &buf, 1);
	parse->map.width = ft_max(parse->map.width, x);
	parse->map.height = ft_max(parse->map.height, y);
	if (is_read == false)
	{
		parse->map.map = (char **)malloc(sizeof(char *) * (parse->map.height + 1));
		if (parse->map.map)
			parse->map.map[parse->map.height] = 0;
		return ;
	}
	if (buf == '\n')
	{
		mkmap(parse, 0, y + 1);
		parse->map.map[y] = (char *)malloc(sizeof(char) * (parse->map.width + 2));
		while (x < parse->map.width)
			parse->map.map[y][x++] = ' ';
		parse->map.map[y][parse->map.width] = 0;
		return ;
	}
	mkmap(parse, x + 1, y);
	parse->map.map[y][x] = buf;
}