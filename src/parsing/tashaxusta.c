/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tashaxusta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:28:41 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/24 20:46:22 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cordination(char **map, int x, int y)
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

int	grdon_function(char **map, int x, int *count)
{
	int	y;

	y = -1;
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
				(*count)++;
		}
	}
	return (0);
}

int	check_map(char **map)
{
	int	x;
	int	count;

	x = -1;
	count = 0;
	if (!map)
		return (-1);
	while (map[++x])
	{
		if (grdon_function(map, x, &count) == -1)
			return (-1);
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	color_checker(t_elements *elements, char *str)
{
	char	**sp;
	char	*line;
	int		flag;

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

int	checker(t_cub cub)
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
