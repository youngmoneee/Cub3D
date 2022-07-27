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
	printf("floor parsed : %d floor valided : %d\n", parse.opt[FLOOR].parsed, parse.opt[FLOOR].valided);
	if (parse.opt[FLOOR].parsed && parse.opt[FLOOR].valided)
		printf("floor : %X\n", parse.opt[FLOOR].color);
	printf("ceil parsed : %d ceil valided : %d\n", parse.opt[CEIL].parsed, parse.opt[CEIL].valided);
	if (parse.opt[CEIL].parsed && parse.opt[CEIL].valided)
		printf("ceil : %X\n", parse.opt[CEIL].color);

	// news
	for (int i = EAST; i < UNKNOWN; i++)
		printf("fd => %d\n", parse.opt[i].fd);
	char *qwe;
	printf("WE parsed : %d WE valid : %d\n", parse.opt[WEST].parsed, parse.opt[WEST].valided);
	if (parse.opt[WEST].parsed && parse.opt[WEST].valided)
		printf("we : %s\n", qwe = gnl(parse.opt[WEST].fd, 0));
	free(qwe);
	printf("SO parsed : %d SO valid : %d\n", parse.opt[SOUTH].parsed, parse.opt[SOUTH].valided);
	if (parse.opt[SOUTH].parsed && parse.opt[SOUTH].valided)
		printf("so : %s\n", qwe = gnl(parse.opt[SOUTH].fd, 0));
	free(qwe);
	printf("NO parsed : %d NO valid : %d\n", parse.opt[NORTH].parsed, parse.opt[NORTH].valided);
	if (parse.opt[NORTH].parsed && parse.opt[NORTH].valided)
		printf("no : %s\n", qwe = gnl(parse.opt[NORTH].fd, 0));
	free(qwe);
	printf("EA parsed : %d EA valid : %d\n", parse.opt[EAST].parsed, parse.opt[EAST].valided);
	if (parse.opt[EAST].parsed && parse.opt[EAST].valided)
		printf("ea : %s\n", qwe = gnl(parse.opt[EAST].fd, 0));
	free(qwe);
	return 0;
}
