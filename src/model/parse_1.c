/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:33:09 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/20 20:10:28 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../inc/util.h"
#include "../../inc/cub3d.h"
#include <stdio.h>

static bool	end_check(t_parse *parse)
{
	char	buf;
	int		idx;

	while (read(parse->fd, &buf, 1) > 0)
	{
		if (buf && !ft_isspace(buf))
			return (false);
	}
	idx = -1;
	while (++idx < 6)
		if (!(parse->opt[idx].valided && parse->opt[idx].parsed))
			return (false);
	return (true);
}

static	void	parsing_sub(t_parse *parse)
{
	char	*line;
	char	*freer;

	while (!parse->is_parsed)
	{
		line = gnl(parse->fd, 0);
		if (!*line)
		{
			free(line);
			break ;
		}
		freer = line;
		while (ft_isspace(*line))
			line++;
		if (*line && ft_strchr("FC", *line))
			set_color(line, parse->opt);
		else if (*line && ft_strchr("NEWS", *line))
			set_path(line, parse->opt, parse->mlx);
		else if (*line && ft_strchr("10", *line))
		{
			set_map(freer, parse);
			parse->map.is_parsed = true;
		}
		free(freer);
	}
}

void	parsing(t_parse *parse)
{
	parsing_sub(parse);
	parse->is_valided = end_check(parse);
	close(parse->fd);
	if (!parse->is_valided)
		exit_msg("Parse Error!");
}
