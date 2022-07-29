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
	parse->is_parsed = false;
}

static bool	end_check(t_parse *parse)
{
	char	buf;
	int		ret;

	while ((ret = read(parse->fd, &buf, 1)) > 0)
	{
		if (buf && !ft_isspace(buf))
			break ;
	}
	if (ret)
		return (false);
	return (true);
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
		printf("%d\n", parse->opt[FLOOR].fd);
		free(freer);
	}
	parse->is_valided = end_check(parse);
	close(parse->fd);
}

void	mkmap(t_parse *parse, int y)
{
	char	*buf;
	int		idx;

	idx = 0;
	buf = gnl(parse->fd, 0);
	while (buf[idx] && ft_isspace(buf[idx]))
		idx++;
	printf("%d : %c\n", y, buf[idx]);
	parse->map.width = ft_max(parse->map.width, ft_strlen(buf));
	parse->map.height = ft_max(parse->map.height, y);
	if (buf[idx] == 0)
	{
		parse->map.map = (char **)malloc(sizeof(char *) * (parse->map.height + 1));
		if (parse->map.map)
			parse->map.map[parse->map.height] = 0;
		free(buf);
		return ;
	}

	mkmap(parse, y + 1);
	parse->map.map[y] = (char *)malloc(sizeof(char) * (parse->map.width + 1));
	if (!parse->map.map[y])
		exit_msg("Memory Error");
	ft_memset(parse->map.map[y], ' ', parse->map.width + 1);
	parse->map.map[y][parse->map.width] = 0;
	ft_memcpy(parse->map.map[y], buf, ft_strlen(buf));
	free(buf);
}

void	set_map(char *trigger_line, t_parse *parse)
{
	uint	idx;

	idx = -1;
	parse->map.width = ft_strlen(trigger_line);
	parse->map.height = 1;
	parse->map.is_parsed = true;
	mkmap(parse, 1);
	if (!parse->map.map)
		exit_msg("Memory Error");
	parse->map.map[0] = (char *)malloc(sizeof(char) * (parse->map.width + 1));
	ft_memset(parse->map.map[0], ' ', parse->map.width + 1);
	parse->map.map[0][parse->map.width] = 0;
	ft_memcpy(parse->map.map[0], trigger_line, ft_strlen(trigger_line));
	printf("[%s]\n", parse->map.map[0]);
	parse->is_parsed = true;
}