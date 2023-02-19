#include "cub3d.h"

int	create_trgb(int r, int g, int b)
{
	int t;
	
	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
	{
		ft_putstr_fd("ESC! exit\n", 2);
		exit(0);
	}
	return (0);
}

void	initializer(t_data *data, t_elements elements)
{
	int	size;

	size = (int)SIZE;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "IT IS MY CUB3D!");
	data->no_texture = mlx_xpm_file_to_image(data->mlx, elements.NO, &size, &size);
	data->so_texture = mlx_xpm_file_to_image(data->mlx, elements.SO, &size, &size);
	data->we_texture = mlx_xpm_file_to_image(data->mlx, elements.WE, &size, &size);
	data->ea_texture = mlx_xpm_file_to_image(data->mlx, elements.EA, &size, &size);
	data->f_color = create_trgb(elements.F[0], elements.F[1], elements.F[2]);
	data->c_color = create_trgb(elements.C[0], elements.C[1], elements.C[2]);
	while (++(data->y) <= WIN_HEIGHT)
	{
		data->x = -1;
		while (++(data->x) <= WIN_WIDTH)
		{
			if (data->y < WIN_HEIGHT / 2)
				mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->c_color);
			else
				mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->f_color);
		}
	}
	mlx_key_hook(data->win, key_hook, NULL);
}
