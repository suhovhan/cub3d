#include "cub3d.h"

void    p_mtx(char **mtx)
{
    int i = -1;
    while (mtx[++i])
        printf("[%d] [%s]\n", i, mtx[i]);
}

int main(int ac, char **av)
{
    char    **map;

    check_args(ac, av);
    map = getmap(av[1]);
    clean_tabs(map);
    p_mtx(map);
    while (1);
    return (0);
}
