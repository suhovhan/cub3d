/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:32:48 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/24 20:35:08 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_addres *addres, char ***map)
{
	if (!map || !*map)
		exit(1);
	clean_tabs(*map);
	if (struct_collector(&(addres->cub), *map) == -1)
	{
		free_cub(addres->cub);
		exit(1);
	}
	free_mtx(*map);
	if (checker(addres->cub) == -1)
	{
		free_cub(addres->cub);
		exit(1);
	}
	if (elements_collector(&(addres->elements), addres->cub.texture) == -1)
	{
		free_cub(addres->cub);
		free_elements(addres->elements);
		ft_putstr_fd("Invalid elements\n", 2);
		exit(1);
	}
}

t_data	data_collector(t_cub cub)
{
	t_data	data;

	data.map = NULL;
	data.x = -1;
	data.y = -1;
	getter_cub(&data, cub);
	return (data);
	while (data.map[++(data.y)])
	{
		data.x = -1;
		while (data.map[++data.x])
		{
			if (data.map[data.x][data.y] == 'E' || \
			data.map[data.x][data.y] == 'N' \
			|| data.map[data.x][data.y] == 'S' || \
			data.map[data.x][data.y] == 'W')
			{
				data.pos_x = data.x;
				data.pos_y = data.y;
				break ;
			}
		}
	}
	data.x = -1;
	data.y = -1;
}

void	getter_cub(t_data *data, t_cub cub)
{
	int		i;
	char	**map;

	i = -1;
	while (cub.map[++i])
		;
	map = (char **)malloc(sizeof(char *) * (i + 2));
	if (!map)
		return ;
	i = -1;
	while (cub.map[++i])
		map[i] = ft_strdup(cub.map[i]);
	map[i] = 0;
	data->map = map;
}
