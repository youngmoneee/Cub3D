/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:33:09 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/20 14:46:54 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../inc/util.h"
#include "../../inc/cub3d.h"
#include <stdio.h>

static bool	end_check(t_parse *parse)
{
	char	buf;

	while (read(parse->fd, &buf, 1) > 0)
	{
		if (buf && !ft_isspace(buf))
			return (false);
	}
	return (true);
}

bool	all_parsed(t_parse *parse)
{
	t_uint	i;
	bool	ret;

	i = -1;
	ret = true;
	while (++i)
		ret &= parse->opt[i].parsed;
	return (ret);
}

bool	all_valid(t_parse *parse)
{
	t_uint	i;
	bool	ret;

	i = -1;
	ret = true;
	while (++i)
		ret &= parse->opt[i].parsed;
	return (ret);
}

void	parsing(t_parse *parse)
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
		while (*line && ft_isspace(*line))
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
	parse->is_valided = end_check(parse);
	close(parse->fd);
}
