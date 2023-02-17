#include "cub3d.h"

int	create_trgb(int r, int g, int b)
{
	int t;
	
	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 53)
		exit(0);
	printf("Hello from key_hook!\n");
	return (0);
}

void	draw_window(t_data *data)
{
	int	ceiling;
	int floor;

	ceiling = create_trgb(data->C[0], data->C[1], data->C[2]);
	floor = create_trgb(data->F[0], data->F[1], data->F[2]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "IT IS MY CUB3D!");
	while (data->y < WIN_HEIGHT / 2)
	{
		data->x = 0;
		while (data->x <= WIN_WIDTH)
		{
			mlx_pixel_put(data->mlx, data->win, data->x, data->y, ceiling);
			data->x++;
		}
		data->y++;
	}
	while (data->y >= WIN_HEIGHT / 2 && data->y <= WIN_HEIGHT)
	{
		data->x = 0;
		while (data->x <= WIN_WIDTH)
		{
			mlx_pixel_put(data->mlx, data->win, data->x, data->y, floor);
			data->x++;
		}
		data->y++;
	}
	data->x = 0;
	data->y = 0;
	mlx_key_hook(data->win, key_hook, NULL);
	mlx_loop(data->mlx);
}
