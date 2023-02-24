#include "cub3d.h"

int	create_trgb(int r, int g, int b)
{
	int t;
	
	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	initializer(t_addres *address)
{
	int	size;

	size = 100;
	address->game->mlx = mlx_init();
	address->game->win = mlx_new_window(address->game->mlx, WIDTH, HEIGHT, "IT IS MY CUB3D!");
	address->game->no = mlx_xpm_file_to_image(address->game->mlx, address->elements.NO, &size, &size);
	address->game->so = mlx_xpm_file_to_image(address->game->mlx, address->elements.SO, &size, &size);
	address->game->we = mlx_xpm_file_to_image(address->game->mlx, address->elements.WE, &size, &size);
	address->game->ea = mlx_xpm_file_to_image(address->game->mlx, address->elements.EA, &size, &size);
	address->game->f_color = create_trgb(address->elements.F[0], address->elements.F[1], address->elements.F[2]);
	address->game->c_color = create_trgb(address->elements.C[0], address->elements.C[1], address->elements.C[2]);
	if (address->game->mlx == NULL || address->game->win == NULL)
		close_game(address);
	if (address->game->no == NULL || address->game->so == NULL)
		close_game(address);
	if (address->game->we == NULL || address->game->ea == NULL)
		close_game(address);
}
