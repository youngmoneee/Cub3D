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

void	draw_pixel(int x, int y, unsigned color, t_img *img)
{
	void	*pixel;

	pixel = img->data + (x * img->bpp / 8) + (y * img->lsz);
	*(unsigned *)pixel = color;
}

void	draw_bg(t_cub *cub)
{
	int i;
	int j;

	i = -1;
	while (++i < WIN_HEIGHT / 2)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			draw_pixel(j, i, cub->parse.opt[CEIL].color, &cub->mlx.img);
		}
	}
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			draw_pixel(j, i, cub->parse.opt[FLOOR].color, &cub->mlx.img);
		}
	}
}

void	draw_mmap(t_cub *cub)
{
	int i;
	int j;
	double cx;
	double cy;

	i = -MMAP_H / 2 - 1;
	while (++i <= MMAP_H / 2)
	{
		j = -MMAP_W / 2 - 1;
		while (++j <= MMAP_W / 2)
		{
			cx = cub->user.x + (double)4 / j;
			cy = cub->user.y + (double)3 / i;
			printf("double => x : %lf y : %lf\n", cx, cy);
			printf("i n t  => x : %d y : %d\n", (int)cx, (int)cy);

			if ((j == -MMAP_W / 2) || (j == MMAP_W / 2) || (i == -MMAP_H / 2) || (i == MMAP_H / 2))
				draw_pixel(PAD_X + j, PAD_Y + i, FRAME, &cub->mlx.img);
			else if ((j % (MMAP_W / 10) == 0) || (i % (MMAP_H / 10) == 0))
				draw_pixel(PAD_X + j, PAD_Y + i, GRID, &cub->mlx.img);
			else if (cx < 0 || cy < 0
					 || cx >= cub->parse.map.width || cy >= cub->parse.map.height)
				continue ;
			else if (cub->parse.map.map[(int)cy][(int)cx] == '1')
				draw_pixel(PAD_X + j, PAD_Y + i, 0xFFFF00, &cub->mlx.img);
			else if (cub->parse.map.map[(int)cy][(int)cx] == '0')
				draw_pixel(PAD_X + j, PAD_Y + i, 0x00FFFF, &cub->mlx.img);

		}
	}
	draw_pixel(PAD_X, PAD_Y, 0xF00FF0, &cub->mlx.img);
}
/*
void	draw_minimap(t_cub *cub)
{

}
*/
int	render(t_cub *cub)
{
	draw_bg(cub);
	draw_mmap(cub);
	mlx_put_image_to_window(cub->mlx.pmlx, cub->mlx.pwin, cub->mlx.img.ptr, 0, 0);
	mlx_hook(cub->mlx.pwin, RED_DOT, 0, *close_mlx, &cub->mlx);
	mlx_loop(cub->mlx.pmlx);
	return (1);
}
