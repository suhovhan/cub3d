/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:26:51 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 16:59:25 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char	*get_correct_arg(char *ptr)
{
	int		i;
	int		j;
	char	*new_arg;

	new_arg = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ptr[i] != ' ' && ptr[i] != '\t')
		{
			new_arg[j] = ptr[i];
			j++;
		}
		i++;
	}
	new_arg[j] = '\0';
	return (new_arg);
}

void	init_plane(t_data *data, double i, double j)
{
	data->rcasting->planex = i;
	data->rcasting->planey = j;
}

void	init_dir(t_data *data, double i, double j)
{
	data->rcasting->dirx = i;
	data->rcasting->diry = j;
}

void	init_player_pos(t_data *data, int i, int j)
{
	if (data->parsing->norm_map[i][j] == 'S')
	{
		init_dir(data, 1, 0);
		init_plane(data, 0, -0.66);
	}
	else if (data->parsing->norm_map[i][j] == 'N')
	{
		init_dir(data, -1, 0);
		init_plane(data, 0, 0.66);
	}
	else if (data->parsing->norm_map[i][j] == 'E')
	{
		init_dir(data, 0, 1);
		init_plane(data, 0.66, 0);
	}
	else if (data->parsing->norm_map[i][j] == 'W')
	{
		init_dir(data, 0, -1);
		init_plane(data, -0.66, 0);
	}
}
