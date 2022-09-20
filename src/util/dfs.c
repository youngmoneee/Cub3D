/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 05:00:35 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/20 19:50:44 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../libft/libft.h"

static int	**init_offset(void)
{
	int	**offset;
	int	i;

	offset = ft_calloc(sizeof(int *), 4);
	i = 0;
	while (i < 4)
		offset[i++] = ft_calloc(sizeof(int), 2);
	offset[0][0] = 0;
	offset[0][1] = 1;
	offset[1][0] = 1;
	offset[1][1] = 0;
	offset[2][0] = 0;
	offset[2][1] = -1;
	offset[3][0] = -1;
	offset[3][1] = 0;
	return (offset);
}

static int	free_offset(int **offset)
{
	int	i;

	i = 0;
	if (offset)
	{
		while (i < 4)
			free(offset[i++]);
		free(offset);
	}
	return (0);
}

static int	chk_land(int i, int j, t_map map)
{
	if ((map.map)[i][j] != ' ' && (map.map)[i][j] != '1'
			&& (map.map)[i][j] != '0')
		return (0);
	if (map.map[i][j] == ' ' || i == 0 || j == 0
			|| i == map.height - 1 || j == map.width - 1)
		return (0);
	return (1);
}

int	dfs(int i, int j, t_map map, int ***chk)
{
	int	**offset;
	int	dj;
	int	di;
	int	idx;

	offset = init_offset();
	idx = -1;
	while (++idx < 4)
	{
		di = i + offset[idx][0];
		dj = j + offset[idx][1];
		if (0 <= di && di < map.height && 0 <= dj && dj < map.width
			&& map.map[di][dj] != '1' && !((*chk)[di][dj]))
		{
			if (!chk_land(di, dj, map))
				return (free_offset(offset));
			(*chk)[di][dj] = 1;
			if (!dfs(di, dj, map, chk))
				return (free_offset(offset));
		}
	}
	free_offset(offset);
	return (1);
}
