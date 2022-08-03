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

int main(int a, char **v) {
	//t_parse parse;
	//t_mlx	mlx;
	t_cub	cub;

	if (a != 2)
		exit(1);
	parsing(&cub.parse, v[1]);
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
	// VIEW
	if (!mlx_init(&cub.mlx))
		exit_msg("Window Init Failed.");
	render(&cub.parse, &cub.mlx);
	//mlx_hook(&mlx.pwin, RED_DOT, 0, close_mlx, &mlx);
	mlx_loop(cub.mlx.pmlx);
	return 0;
}
