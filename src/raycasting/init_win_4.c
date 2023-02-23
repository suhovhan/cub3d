/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:14:39 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 20:03:58 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_data_addr(t_data *data)
{
	data->img[1].img = mlx_get_data_addr(data->game->no, &data->img[1].bpp, \
	&data->img[1].size_line, &data->img[1].endian);
	data->img[2].img = mlx_get_data_addr(data->game->so, &data->img[2].bpp, \
	&data->img[2].size_line, &data->img[2].endian);
	data->img[3].img = mlx_get_data_addr(data->game->ea, &data->img[3].bpp, \
	&data->img[3].size_line, &data->img[3].endian);
	data->img[4].img = mlx_get_data_addr(data->game->we, &data->img[4].bpp, \
	&data->img[4].size_line, &data->img[4].endian);
}

int	check_nwse(t_data *data)
{
	int	n;

	n = 1;
	if (data->rcasting->side == 1 && data->rcasting->raydiry < 0)
		n = 3;
	else if (data->rcasting->side == 1 && data->rcasting->raydiry > 0)
		n = 4;
	else if (data->rcasting->side == 0 && data->rcasting->raydirx > 0)
		n = 2;
	else if (data->rcasting->side == 0 && data->rcasting->raydirx < 0)
		n = 1;
	return (n);
}
