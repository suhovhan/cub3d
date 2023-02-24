#include "cub3d.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return ;
	while (mtx[++i])
		free(mtx[i]);
	free(mtx);
}

void	free_cub(t_cub cub)
{
	free_mtx(cub.texture);
	free_mtx(cub.map);
}

void	free_elements(t_elements elements)
{
	free(elements.NO);
	free(elements.SO);
	free(elements.WE);
	free(elements.EA);
}

void	free_game(t_game *game)
{
	free(game->mlx);
	free(game->win);
	free(game->no);
	free(game->so);
	free(game->ea);
	free(game->we);
}

void	free_all(t_addres *address)
{
	int	i;
	
	i = -1;
	free_cub(address->cub);
	free_elements(address->elements);
	free_mtx(address->data.map);
	free_game(address->game);
	while (++i < 5)
	{
		free(address->img[i].img);
		free(address->img[i].ptr);
	}
	free(address->rcasting);
	free(address->index);
	free(address->game);
	free(address->img);
}
