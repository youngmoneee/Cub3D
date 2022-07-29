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
	if (parse.opt[FLOOR].parsed && parse.opt[FLOOR].valided)
		printf("floor : %X\n", parse.opt[FLOOR].color);
	if (parse.opt[CEIL].parsed && parse.opt[CEIL].valided)
		printf("ceil : %X\n", parse.opt[CEIL].color);

	return 0;
}
