#include "../../inc/structure.h"

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

int	close_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		mlx_destroy_window(mlx->pmlx, mlx->pwin);
		exit(0);
	}
	return (0);
}

int	render(t_cub *cub)
{
	init_win(&cub->mlx);
	mlx_hook(cub->mlx.pwin, RED_DOT, 0, *close_mlx, &cub->mlx);
	mlx_loop(cub->mlx.pmlx);
	return (1);
}
