/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:25:59 by youngpar          #+#    #+#             */
/*   Updated: 2022/07/26 21:26:00 by youngpar         ###   ########.fr       */
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
	//printf("%lf\n", cub->user.radian / M_PI * (double)180);
	//printf("%lf\n", cub->user.radian / M_PI);
	printf("ux : %lf uy : %lf\n", cub->user.x, cub->user.y);
	return (0);
}

int main(int a, char **v) {
	t_cub	cub;

	if (a != 2)
		exit(1);
	//	INITIALIZATION
	init(&cub, v[1]);
	parsing(&cub.parse);
	set_user(&cub.parse.map, &cub.user);

	int i = -1;
	while (++i < 6)
		printf("%d ) Parsed : %d, Valid : %d\n", i, cub.parse.opt[i].parsed, cub.parse.opt[i].valided);
	printf("Parsed : %d, Valid : %d\n", cub.parse.is_parsed, cub.parse.is_valided);
	if (cub.parse.opt[FLOOR].parsed && cub.parse.opt[FLOOR].valided)
		printf("floor : %X\n", cub.parse.opt[FLOOR].color);
	if (cub.parse.opt[CEIL].parsed && cub.parse.opt[CEIL].valided)
		printf("ceil : %X\n", cub.parse.opt[CEIL].color);
	i = -1;
	while (++i < cub.parse.map.height)
	{
		int j = -1;
		while(++j < cub.parse.map.width)
			printf("[%c]", cub.parse.map.map[i][j]);
		printf("\n");
	}
	printf("Player's Position\nX : %f\nY : %f\nASP : %f\n", cub.user.x, cub.user.y, cub.user.radian);
	// VIEW
	if (!init_win(&cub.mlx))
		exit_msg("Window Init Failed.");
	render(&cub);
	mlx_hook(cub.mlx.pwin, X_KEY_PRESS, 0, key_press, &cub);
    mlx_hook(cub.mlx.pwin, X_KEY_REALEASE, 0, key_release, &cub);
	mlx_hook(cub.mlx.pwin, RED_DOT, 0, close_mlx, &cub.mlx);
	mlx_loop_hook(cub.mlx.pmlx, update, &cub);
	mlx_loop(cub.mlx.pmlx);
	return 0;
}
