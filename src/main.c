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
	t_parse parse;

	if (a != 2)
		exit(1);
	parsing(&parse, v[1]);
	int i = -1;
	while (++i < 6)
		printf("%d ) Parsed : %d, Valid : %d\n", i, parse.opt[i].parsed, parse.opt[i].valided);
	printf("Parsed : %d, Valid : %d\n", parse.is_parsed, parse.is_valided);
	if (parse.opt[FLOOR].parsed && parse.opt[FLOOR].valided)
		printf("floor : %X\n", parse.opt[FLOOR].color);
	if (parse.opt[CEIL].parsed && parse.opt[CEIL].valided)
		printf("ceil : %X\n", parse.opt[CEIL].color);
	i = -1;
	while (++i < parse.map.height)
	{
		int j = -1;
		while(++j < parse.map.width)
			printf("[%c]", parse.map.map[i][j]);
		printf("\n");
	}
	return 0;
}
