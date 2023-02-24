#include "cub3d.h"

void    p_mtx(char **mtx)
{
    int i = -1;
    while (mtx[++i])
        printf("%s\n", mtx[i]);
}

void	p_address(t_addres address)
{
	printf("perpwalldist = %f\n", address.rcasting->perpwalldist);
	printf("deltadistx = %f\n", address.rcasting->deltadistx);
	printf("deltadisty = %f\n", address.rcasting->deltadisty);
	printf("sidedistx = %f\n", address.rcasting->sidedistx);
	printf("sidedisty = %f\n", address.rcasting->sidedisty);
	printf("camerax = %f\n", address.rcasting->camerax);
	printf("raydirx = %f\n", address.rcasting->raydirx);
	printf("raydiry = %f\n", address.rcasting->raydiry);
	printf("planex = %f\n", address.rcasting->planex);
	printf("planey = %f\n", address.rcasting->planey);
	printf("posx = %f\n", address.rcasting->posx);
	printf("posy = %f\n", address.rcasting->posy);
	printf("dirx = %f\n", address.rcasting->dirx);
	printf("diry = %f\n", address.rcasting->diry);
	printf("lineheight = %d\n", address.rcasting->lineheight);
	printf("drawstart = %d\n", address.rcasting->drawstart);
	printf("drawend = %d\n", address.rcasting->drawend);
	printf("stepx = %d\n", address.rcasting->stepx);
	printf("stepy = %d\n", address.rcasting->stepy);
	printf("side = %d\n", address.rcasting->side);
	printf("mapx = %d\n", address.rcasting->mapx);
	printf("mapy = %d\n", address.rcasting->mapy);
	printf("hit = %d\n", address.rcasting->hit);
}

void	p_img(t_addres address, int n)
{
	printf("ptr = %p\n", address.img[n].ptr);
	printf("img = %p\n", address.img[n].img);
	printf("bpp = %d\n", address.img[n].bpp);
	printf("width = %d\n", address.img[n].width);
	printf("height = %d\n", address.img[n].height);
	printf("size_line = %d\n", address.img[n].size_line);
	printf("endian = %d\n", address.img[n].endian);
}

int main(int ac, char **av)
{
    char        **map;
	t_addres	addres;

    addres.cub.map = NULL;
    addres.cub.texture = NULL;
    addres.elements.NO = NULL;
    addres.elements.SO = NULL;
    addres.elements.WE = NULL;
    addres.elements.EA = NULL;
    check_args(ac, av);
    map = getmap(av[1]);
    if (!map)
        return (-1);
    clean_tabs(map);
    if (struct_collector(&(addres.cub), map) == -1)
    {
        free_cub(addres.cub);
        return (-1);
    }
    free_mtx(map);
    if (checker(addres.cub) == -1)
    {
        free_cub(addres.cub);
        return (-1);
    }
    if (elements_collector(&(addres.elements), addres.cub.texture) == -1)
    {
        free_cub(addres.cub);
        free_elements(addres.elements);
        ft_putstr_fd("Invalid elements\n", 2);
        return (-1);
    }
    free_mtx(addres.cub.texture);
	init_structs(&addres);
    addres.data = data_collector(addres.cub);
    initializer(&addres);
	init_win(&addres);
    mlx_loop(addres.game->mlx);
    free_cub(addres.cub);
    free_elements(addres.elements);
    return (0);
}
