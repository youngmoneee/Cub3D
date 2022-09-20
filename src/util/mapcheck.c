/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 05:00:35 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/20 14:45:26 by kyoon            ###   ########.fr       */
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

static int	dfs(int i, int j, t_map map, int ***chk)
{
	int	**offset;
	int	dj;
	int	di;
	int	idx;

	idx = 0;
	offset = init_offset();
	while (idx < 4)
	{
		di = i + offset[idx][0];
		dj = j + offset[idx][1];
		if (0 <= di && di < map.height && 0 <= dj && dj < map.width
			&& map.map[di][dj] != '1' && !((*chk)[di][dj]))
		{
			if (map.map[di][dj] == ' ' || di == 0 || dj == 0
					|| di == map.height - 1 || dj == map.width - 1)
				return (free_offset(offset));
			(*chk)[di][dj] = 1;
			if (!dfs(di, dj, map, chk))
				return (free_offset(offset));
		}
		idx++;
	}
	free_offset(offset);
	return (1);
}

int	mapcheck(t_map map)
{
	int		**chk;
	int		i;
	int		j;
	int		ret;
	int		offset[4][2];

	if (!map.map)
		return (0);
	i = 0;
	ret = 1;
	chk = calloc(sizeof(int *), map.height + 1);
	while (i < map.height)
		chk[i++] = calloc(sizeof(int), map.width);
	i = 0;
	while (ret && i < map.height)
	{
		j = 0;
		while (ret && j < map.width)
		{
			if (!chk[i][j] && (map.map)[i][j] == '0')
				ret = dfs(i, j, map, &chk);
			j++;
		}
		i++;
	}
	free_chk(chk, map);
	return (ret);
}
