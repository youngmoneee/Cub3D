#ifndef PARSE_H
# define PARSE_H

#include "structure.h"

bool	all_parsed(t_parse *parse);
bool	all_valid(t_parse *parse);
void	set_color(char *line, t_option *opt);
void	set_path(char *line, t_option *opt, void *mlx);
void	parsing(t_parse *parse);
void	set_user(t_map *map, t_user *user);
void	mkmap(t_parse *parse, int y);
void	set_map(char *entire_line, t_parse *parse);
#endif
