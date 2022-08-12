#ifndef HANDLER_H
# define HANDLER_H

#include "structure.h"

int key_press(int code, t_cub *cub);
int key_release(int code, t_cub *cub);
void    move(t_cub *cub);
void	rotate(t_cub *cub);

#endif