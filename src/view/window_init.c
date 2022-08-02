#include "../../inc/structure.h"

int		init_win(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "./fractol");
	mlx->img.imgptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = mlx_get_data_addr(mlx->img.imgptr, &mlx->img.bpp, &mlx->img.lsize, &mlx->img.endian);

	if (!(mlx->mlx_ptr && mlx->win_ptr && mlx->img.imgptr && mlx->img.data))
		return (0);
	return (1);
}

int	close_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}