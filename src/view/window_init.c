#include "../../inc/structure.h"
#include "../../inc/cub3d.h"

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
