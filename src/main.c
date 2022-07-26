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

int main(int a, char **v) {
	t_parse parse;

	if (a != 2)
		exit(1);
	parse.map.width = parse.map.height = 0;
	parse.fd = open(v[1], O_RDONLY, 0777);
	mkmap(&parse, 0, 0);

	for (int i = 0; parse.map.map[i]; i++) {
		for (int j = 0; parse.map.map[i][j]; j++)
			printf("[%c]", parse.map.map[i][j]);
		printf("\n");
	}
	printf("x : %d y : %d\n", parse.map.width, parse.map.height);
	return 0;
}
