/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 05:00:35 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/20 20:02:52 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../libft/libft.h"

static void	free_chk(int **chk, t_map map)
{
	int	i;

	i = 0;
	if (chk)
	{
		while (i < map.height)
			free(chk[i++]);
		free(chk);
	}
}

int	mapcheck(t_map map)
{
	int		**chk;
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = 1;
	chk = calloc(sizeof(int *), map.height + 1);
	while (i < map.height)
		chk[i++] = calloc(sizeof(int), map.width);
	i = -1;
	while (ret && ++i < map.height)
	{
		j = -1;
		while (ret && ++j < map.width)
		{
			if ((map.map)[i][j] != '0' && (map.map)[i][j] != '1'
					&& (map.map)[i][j] != ' ')
				ret = 0;
			else if (!chk[i][j] && (map.map)[i][j] == '0')
				ret = dfs(i, j, map, &chk);
		}
	}
	free_chk(chk, map);
	return (ret);
}
