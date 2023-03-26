/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:30:47 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/24 20:35:00 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_collector(t_cub *cub, char **mtx)
{
	char	**texture;
	int		i;

	i = -1;
	texture = (char **)malloc(sizeof(char *) * 7);
	if (!texture)
		return (-1);
	while (++i < 6)
	{
		if (!mtx[i])
			return (-1);
		texture[i] = ft_strdup(mtx[i]);
		if (!texture[i])
			return (-1);
	}
	texture[i] = 0;
	cub->texture = texture;
	return (0);
}

int	map_collector(t_cub *cub, char **mtx)
{
	int		i;
	int		height;
	char	**map;

	i = 5;
	height = -1;
	while (mtx[++height])
		;
	map = (char **)malloc(sizeof(char *) * (height - 5));
	if (!map)
		return (-1);
	height = -1;
	while (mtx[++i])
	{
		map[++height] = ft_strdup(mtx[i]);
		if (!map[height])
			return (-1);
	}
	map[++height] = 0;
	cub->map = map;
	return (0);
}

int	struct_collector(t_cub *cub, char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return (-1);
	while (mtx[++i])
		;
	if (i < 8)
		return (-1);
	if (texture_collector(cub, mtx) == -1)
		return (-1);
	if (map_collector(cub, mtx) == -1)
		return (-1);
	return (0);
}

int	color_collector(t_elements *elements, char **sp, int flag)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(sp[0]);
	g = ft_atoi(sp[1]);
	b = ft_atoi(sp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || \
	ft_strlen(sp[0]) > 4 || ft_strlen(sp[1]) > 4 || ft_strlen(sp[2]) > 4)
		return (-1);
	if (flag == 0)
	{
		elements->_c[0] = r;
		elements->_c[1] = g;
		elements->_c[2] = b;
	}
	else if (flag == 1)
	{
		elements->_f[0] = r;
		elements->_f[1] = g;
		elements->_f[2] = b;
	}
	return (0);
}

int	elements_collector(t_elements *elements, char **texture)
{
	int		i;
	int		ret;
	char	**sp;

	i = -1;
	ret = 0;
	while (++i < 6 && texture[i])
	{
		sp = ft_split(texture[i], ' ');
		if (ft_strcmp(sp[0], "NO") == 0)
			elements->_no = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "SO") == 0)
			elements->_so = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "WE") == 0)
			elements->_we = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "EA") == 0)
			elements->_ea = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "F") == 0 || ft_strcmp(sp[0], "C") == 0)
			ret = color_checker(elements, texture[i]);
		free_mtx(sp);
	}
	return (ret);
}
