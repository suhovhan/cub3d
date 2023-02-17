#include "cub3d.h"

int check_extension(char *s1, char *s2, size_t n)
{
    int len;
    int i;

    if (!s1 || !s2 || n <= 0)
        return (-1);
    len = (int)ft_strlen((const char *)s1);
    i = 0;
    while (s1[len - n + i] && s2[i])
    {
        if (s1[len - n + i] == s2[i])
            i++;
        else
            return (-1);
    }
    return (0);
}

int check_args(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Invalid count of arguments!\n");
        return (-1);
    }
    if (check_extension(av[1], ".cub", 4) != 0)
    {
        printf("Invalid path extension!\n");
        return (-1);
    }
    return (0);
}

int check_texture_symbols(char *str)
{
    if (!str)
        return (-1);
    if (ft_strcmp(str, "NO") == 0)
        return (1);
    if (ft_strcmp(str, "WE") == 0)
        return (2);
    if (ft_strcmp(str, "SO") == 0)
        return (3);
    if (ft_strcmp(str, "EA") == 0)
        return (4);
    if (ft_strcmp(str, "F") == 0)
        return (5);
    if (ft_strcmp(str, "C") == 0)
        return (6);
    return (-1);
}

int check_texture_args(char **texture)
{
    int i;

    i = -1;
    if (!texture || !texture[0] || !texture[1])
    {
        printf("case 1\n");
        return (-1);
    }
    if ((ft_strcmp(texture[0], "NO") == 0 || ft_strcmp(texture[0], "SO") == 0 \
    || ft_strcmp(texture[0], "WE") == 0 || ft_strcmp(texture[0], "EA") == 0) \
    && texture[2])
    {
        printf("case 2\n");
        return (-1);
    }
    return (0);
}

int check_texture(char **texture)
{
    char    **sp;
    int     count;
    int     i;

    i = -1;
    count = 0;
    while (++i < 6)
    {
        if (!texture[i])
            return (-1);
        sp = ft_split(texture[i], ' ');
        if (!sp[0] || !sp[1])
        {
            free_mtx(sp);
            return (-1);
        }
        count += check_texture_symbols(sp[0]);
        count += check_texture_args(sp);
        free_mtx(sp);
    }
    if (count != 21)
        return (-1);
    return (0);
}

int check_cordination(char **map, int x, int y)
{
    if (x == 0)
        return (-1);
    if (!map[x - 1] || !map[x - 1][y] || \
    (map[x - 1][y] != '1' && map[x - 1][y] != '0' && \
    map[x - 1][y] != 'N' && map[x - 1][y] != 'S' && \
    map[x - 1][y] != 'E' && map[x - 1][y] != 'W'))
        return (-1);
    if (!map[x + 1] || !map[x + 1][y] || \
    (map[x + 1][y] != '1' && map[x + 1][y] != '0' && \
    map[x + 1][y] != 'N' && map[x + 1][y] != 'S' && \
    map[x + 1][y] != 'E' && map[x + 1][y] != 'W'))
        return (-1);
    if (!map[x] || !map[x][y - 1] || \
    (map[x][y - 1] != '1' && map[x][y - 1] != '0' && \
    map[x][y - 1] != 'N' && map[x][y - 1] != 'S' && \
    map[x][y - 1] != 'E' && map[x][y - 1] != 'W'))
        return (-1);
    if (!map[x] || !map[x][y + 1] || \
    (map[x][y + 1] != '1' && map[x][y + 1] != '0' && \
    map[x][y + 1] != 'N' && map[x][y + 1] != 'S' && \
    map[x][y + 1] != 'E' && map[x][y + 1] != 'W'))
        return (-1);
    return (0);
}

int check_map(char **map)
{
    int x;
    int y;
    int count;

    x = -1;
    y = -1;
    count = 0;
    if (!map)
        return (-1);
    while (map[++x])
    {
        if (find_char(map[x]) == -1)
            return (-1);
        if (find_map_symbol(map[x]) == -1)
            return (-1);
        while (map[x][++y])
        {
            if (map[x][y] == '0' && check_cordination(map, x, y) == -1)
                return (-1);
            if ((map[x][y] == 'N' || map[x][y] == 'S' || \
            map[x][y] == 'E' || map[x][y] == 'W'))
            {
                if (check_cordination(map, x, y) == -1)
                    return (-1);
                else
                    count++;
            }
        }
        y = -1;
    }
    if (count != 1)
        return (-1);
    return (0);
}

int	color_checker(t_elements *elements, char *str)
{
	char	**sp;
	char	*line;
    int     flag;

	sp = ft_split(str, ' ');
    flag = -1;
	if (!sp[1])
		return (-1);
    if (ft_strcmp(sp[0], "C") == 0)
        flag = 0;
    if (ft_strcmp(sp[0], "F") == 0)
        flag = 1;
	line = join_mtx(&sp[1]);
	free_mtx(sp);
	sp = ft_split(line, ',');
	free(line);
	if (!sp[0] || !sp[1] || !sp[2] || sp[3])
		return (-1);
	if (color_collector(elements, sp, flag) == -1)
        return (-1);
	free_mtx(sp);
	return (0);
}

int checker(t_cub cub)
{
    if (!(cub.texture) || !(cub.map))
    {
        ft_putstr_fd("Something went wrong!\n", 2);
        return (-1);
    }
    if (check_texture(cub.texture) == -1)
    {
        ft_putstr_fd("Invalid texture arguments!\n", 2);
        return (-1);
    }
    if (check_map(cub.map) == -1)
    {
        ft_putstr_fd("Invalid map!\n", 2);
        return (-1);
    }
    return (0);
}
