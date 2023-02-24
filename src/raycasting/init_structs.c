#include "cub3d.h"

void	init_struct_game(t_addres *address)
{
	address->game = malloc(sizeof(t_game));
	address->game->c_color = 0;
	address->game->f_color = 0;
	address->game->index = 0;
	address->game->mlx = 0;
	address->game->win = 0;
	address->game->no = 0;
	address->game->so = 0;
	address->game->ea = 0;
	address->game->we = 0;
	address->game->x = 0;
	address->game->y = 0;
}

void	init_struct_index(t_addres *address)
{
	address->index = malloc(sizeof(t_index));
	address->index->index_no = 0;
	address->index->index_so = 0;
	address->index->index_ea = 0;
	address->index->index_we = 0;
	address->index->index_c = 0;
	address->index->index_f = 0;
}

void	init_struct_raycasting(t_addres *address)
{
	address->rcasting = malloc(sizeof(t_raycasting));
	address->rcasting->perpwalldist = 0;
	address->rcasting->deltadistx = 0;
	address->rcasting->lineheight = 0;
	address->rcasting->deltadisty = 0;
	address->rcasting->sidedistx = 0;
	address->rcasting->sidedisty = 0;
	address->rcasting->drawstart = 0;
	address->rcasting->drawend = 0;
	address->rcasting->camerax = 0;
	address->rcasting->raydirx = 0;
	address->rcasting->raydiry = 0;
	address->rcasting->planex = 0;
	address->rcasting->planey = 0;
	address->rcasting->stepx = 0;
	address->rcasting->stepy = 0;
	address->rcasting->dirx = 0;
	address->rcasting->diry = 0;
	address->rcasting->posx = 0;
	address->rcasting->posy = 0;
	address->rcasting->side = 0;
	address->rcasting->mapx = 0;
	address->rcasting->mapy = 0;
	address->rcasting->hit = 0;
}

void	init_structs(t_addres *address)
{
	address->img = malloc(sizeof(t_img) * 5);
	init_struct_raycasting(address);
	init_struct_index(address);
	init_struct_game(address);
}
