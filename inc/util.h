#ifndef UTIL_H
#define UTIL_H

#include "../libft/libft.h"
#include "structure.h"

double	normalize(double angle);
char	*gnl(int fd, int idx);
void	exit_msg(const char *msg);

int	mapcheck(t_map map);
#endif
