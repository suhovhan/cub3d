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

void	free_cub(t_cub *cub)
{
	free_mtx(cub->texture);
	free_mtx(cub->map);
}

void	free_elements(t_elements *elements)
{
	free(elements->NO);
	free(elements->SO);
	free(elements->WE);
	free(elements->EA);
}
