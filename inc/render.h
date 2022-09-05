/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:33:38 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/05 23:39:06 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../mlxdir/mlx.h"
# include "structure.h"

int		close_mlx(t_mlx *mlx);
int		render(t_cub *cub);
void	draw_pixel(int x, int y, unsigned color, t_img *img);
void	draw_bg(t_cub *cub);
void	draw_wall(t_cub *cub, t_ray *ray, int i);
void	draw_ray(t_cub *cub, t_ray *ray);
void	draw_mmap(t_cub *cub);

double	dist_btwen(double x1, double x2, double y1, double y2);
bool	is_down(double angle);
bool	is_up(double angle);
bool	is_left(double angle);
bool	is_right(double angle);
void	horizon_check(t_cub *cub, t_ray *ray);
void	vertical_check(t_cub *cub, t_ray *ray);
int		raycast(t_cub *cub);
#endif
