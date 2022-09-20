/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:33:09 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/20 20:20:15 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../libft/libft.h"
#include "../../inc/util.h"

static void	set_aspect(int i, int j, char *c, t_user *user)
{
	if (user->is_parsed)
		exit_msg("player position redefine");
	user->is_parsed = true;
	user->x = j + 0.5;
	user->y = i + 0.5;
	if (*c == 'N')
		user->radian = ASP_N;
	else if (*c == 'S')
		user->radian = ASP_S;
	else if (*c == 'W')
		user->radian = ASP_W;
	else if (*c == 'E')
		user->radian = ASP_E;
	*c = '0';
}

void	set_user(t_map *map, t_user *user)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (ft_strchr("NEWS", map->map[i][j]))
				set_aspect(i, j, &map->map[i][j], user);
		}
	}
	if (!user->is_parsed)
		exit_msg("no player");
}

bool	check_boundary(t_cub *cub, int cx, int cy)
{
	if (cx < 0 || cy < 0 || cx >= cub->parse.map.width
		|| cy >= cub->parse.map.height || cub->parse.map.map[cy][cx] == ' ')
		return (true);
	return (false);
}
