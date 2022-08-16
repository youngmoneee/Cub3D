/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:33:09 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/28 21:45:36 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../libft/libft.h"
#include "../../inc/util.h"

void	init(t_cub *cub, char *fname)
{
	uint	idx;
	t_parse	*parse;

	ft_memset(cub, 0, sizeof(t_cub));
	parse = &cub->parse;
	printf("%p\n", parse);
	if (ft_strlen(fname) <= ft_strlen(".cub")
		|| ft_strncmp(fname + ft_strlen(fname) - 4, ".cub", 5))
		exit_msg("Wrong File Format");
	parse->file = fname;
	parse->fd = open(parse->file, O_RDONLY);
	if (parse->fd < 0)
	{
		perror("Wrong File Name");
		exit(1);
	}
	//idx = -1;
	/*
	while (++idx < 6)
	{
		parse->opt[idx].parsed = false;
		parse->opt[idx].valided = false;
		parse->opt[idx].color = 0x00;
	}
	 */
	//parse->is_parsed = false;
	//cub->user.is_parsed = false;
	cub->user.is_valided = true;
	//ft_memset(&cub->key, 0, sizeof(t_key));
}

bool	init_win(t_mlx *mlx)
{
	mlx->pmlx = mlx_init();
	if (!mlx->pmlx)
		return (0);
	mlx->pwin = mlx_new_window(mlx->pmlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!mlx->pwin)
		return (0);
	mlx->img.ptr = mlx_new_image(mlx->pmlx, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img.ptr)
		return (0);
	mlx->img.data = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, &mlx->img.lsz, &mlx->img.endian);
	if (!mlx->img.data)
		return (0);
	return (1);
}