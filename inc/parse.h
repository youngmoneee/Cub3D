#ifndef PARSE_H
# define PARSE_H

#include "structure.h"

bool	all_parsed(t_parse *parse);
bool	all_valid(t_parse *parse);
void	set_color(char *line, t_option *opt);
void	atocolor(char *str, int pos, t_option *opt);
void	set_path(char *line, t_option *opt);
bool	parsing(t_parse *parse, char *fname);
void	mkmap(t_parse *parse, int x, int y);
#endif
