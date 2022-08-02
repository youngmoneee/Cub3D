#include "../../inc/structure.h"
#include "../../inc/parse.h"
#include "../../libft/libft.h"
#include "../../inc/util.h"

void	mkmap(t_parse *parse, int y)
{
	char	*buf;
	int		idx;

	idx = 0;
	buf = gnl(parse->fd, 0);
	while (buf[idx] && ft_isspace(buf[idx]))
		idx++;
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
	parse->is_parsed = true;
}