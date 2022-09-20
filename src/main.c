/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:25:59 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/20 19:22:57 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdio.h>
#include "../inc/util.h"

static int	update(t_cub *cub)
{
	rotate(cub);
	move(cub);
	render(cub);
	return (0);
}

int	main(int a, char **v)
{
	t_cub	cub;

	if (a != 2)
		exit(1);
	init(&cub, v[1]);
	if (!init_win(&cub.mlx))
		exit_msg("Window Init Failed.");
	cub.parse.mlx = cub.mlx.pmlx;
	parsing(&cub.parse);
	set_user(&cub.parse.map, &cub.user);
	if (!(cub.parse.map.map) || !mapcheck(cub.parse.map))
		exit_msg("Map Error!");
	write(1, "success!!\n", 10);
	render(&cub);
	mlx_hook(cub.mlx.pwin, X_KEY_PRESS, 0, key_press, &cub);
	mlx_hook(cub.mlx.pwin, X_KEY_REALEASE, 0, key_release, &cub);
	mlx_hook(cub.mlx.pwin, RED_DOT, 0, close_mlx, &cub.mlx);
	mlx_loop_hook(cub.mlx.pmlx, update, &cub);
	mlx_loop(cub.mlx.pmlx);
	return (0);
}
