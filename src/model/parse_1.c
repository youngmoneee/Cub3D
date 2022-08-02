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

#include "../../inc/structure.h"
#include "../../inc/parse.h"
#include "../../libft/libft.h"
#include "../../inc/util.h"

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
	parse->is_parsed = false;
}

static bool	end_check(t_parse *parse)
{
	char	buf;
	int		ret;

	while ((ret = read(parse->fd, &buf, 1)) > 0)
	{
		if (buf && !ft_isspace(buf))
			return (false) ;
	}
	return (true);
}

bool	all_parsed(t_parse *parse)
{
	uint	i;
	bool	ret;

	i = -1;
	ret = true;
	while (++i)
		ret &= parse->opt[i].parsed;
	return (ret);
}

bool	all_valid(t_parse *parse)
{
	uint	i;
	bool	ret;

	i = -1;
	ret = true;
	while (++i)
		ret &= parse->opt[i].parsed;
	return (ret);
}

void	parsing(t_parse *parse, char *fname)
{
	char	*line;
	char	*freer;

	parse_init(parse, fname);
	while (!parse->is_parsed)
	{
		line = gnl(parse->fd, 0);
		freer = line;
		while (*line && ft_isspace(*line))
			line++;
		if (*line == 'C' || *line == 'F')
			set_color(line, parse->opt);
		else if (*line == 'E' || *line == 'W' || *line == 'N' || *line == 'S')
			set_path(line, parse->opt);
		else if (*line == '1' || *line == '0')
		{
			set_map(freer, parse);
			parse->map.is_parsed = true;
		}
		free(freer);
	}
	parse->is_valided = end_check(parse);
	close(parse->fd);
}