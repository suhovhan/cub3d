#include "cub3d.h"

void    p_mtx(char **mtx)
{
    int i = -1;
    while (mtx[++i])
        printf("%s\n", mtx[i]);
}

void    p_data(t_data data)
{
    printf("NO %s\n", data.NO);
    printf("SO %s\n", data.SO);
    printf("WE %s\n", data.WE);
    printf("EA %s\n", data.EA);
    printf("F R=%d G=%d B=%d\n", data.F[0], data.F[1], data.F[2]);
    printf("C R=%d G=%d B=%d\n", data.C[0], data.C[1], data.C[2]);
    p_mtx(data.map);
}

int main(int ac, char **av)
{
    char        **map;
    t_cub       cub;
    t_elements  elements;
    t_data      data;

    cub.map = NULL;
    cub.texture = NULL;
    elements.NO = NULL;
    elements.SO = NULL;
    elements.WE = NULL;
    elements.EA = NULL;
    check_args(ac, av);
    map = getmap(av[1]);
    if (!map)
        return (-1);
    clean_tabs(map);
    if (struct_collector(&cub, map) == -1)
    {
        free_cub(&cub);
        return (-1);
    }
    free_mtx(map);
    if (checker(cub) == -1)
    {
        free_cub(&cub);
        return (-1);
    }
    if (elements_collector(&elements, cub.texture) == -1)
    {
        free_cub(&cub);
        free_elements(&elements);
        ft_putstr_fd("Invalid elements\n", 2);
        return (-1);
    }
    free_mtx(cub.texture);
    data = data_collector(cub, elements);
    free_cub(&cub);
    free_elements(&elements);
    return (0);
}
