/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:58:05 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 19:25:48 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_pos_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->parsing->norm_map[i])
	{
		j = 0;
		while (data->parsing->norm_map[i][j])
		{
			if (data->parsing->norm_map[i][j] == 'N' || \
				data->parsing->norm_map[i][j] == 'S' || \
				data->parsing->norm_map[i][j] == 'E' || \
				data->parsing->norm_map[i][j] == 'W')
			{
				init_player_pos(data, i, j);
				data->rcasting->posx = i + 0.5;
				data->rcasting->posy = j + 0.5;
				data->parsing->norm_map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	norm_init_win_2(t_data *data)
{
	data->rcasting->hit = 0;
	while (data->rcasting->hit == 0)
	{
		if (data->rcasting->sidedistx < data->rcasting->sidedisty)
		{
			data->rcasting->sidedistx += data->rcasting->deltadistx;
			data->rcasting->mapx += data->rcasting->stepx;
			data->rcasting->side = 0;
		}
		else
		{
			data->rcasting->sidedisty += data->rcasting->deltadisty;
			data->rcasting->mapy += data->rcasting->stepy;
			data->rcasting->side = 1;
		}
		if (data->parsing->norm_map[data->rcasting->mapx] \
		[data->rcasting->mapy] != '0')
			data->rcasting->hit = 1;
	}
	norm_init_win_3(data);
}

void	norm_init_win(t_data *data)
{
	if (data->rcasting->raydiry < 0)
	{
		data->rcasting->stepy = -1;
		data->rcasting->sidedisty = (data->rcasting->posy - \
		data->rcasting->mapy) * data->rcasting->deltadisty;
	}
	else
	{
		data->rcasting->stepy = 1;
		data->rcasting->sidedisty = (data->rcasting->mapy + 1.0 - \
		data->rcasting->posy) * data->rcasting->deltadisty;
	}
	norm_init_win_2(data);
}

void	continue_init_win(t_data *data)
{
	if (data->rcasting->raydirx == 0)
		data->rcasting->deltadistx = 1e30;
	else
		data->rcasting->deltadistx = ft_abs(1 / data->rcasting->raydirx);
	if (data->rcasting->raydiry == 0)
		data->rcasting->deltadisty = 1e30;
	else
		data->rcasting->deltadisty = ft_abs(1 / data->rcasting->raydiry);
	if (data->rcasting->raydirx < 0)
	{
		data->rcasting->stepx = -1;
		data->rcasting->sidedistx = (data->rcasting->posx - \
		data->rcasting->mapx) * data->rcasting->deltadistx;
	}
	else
	{
		data->rcasting->stepx = 1;
		data->rcasting->sidedistx = (data->rcasting->mapx + 1.0 - \
		data->rcasting->posx) * data->rcasting->deltadistx;
	}
	norm_init_win(data);
}

void	init_win(t_data *data)
{
	int	i;

	i = 0;
	find_pos_player(data);
	data->img[0].ptr = mlx_new_image(data->game->mlx, WIDTH, HEIGHT);
	data->img[0].img = mlx_get_data_addr(data->img[0].ptr, &data->img[0].bpp, \
	&data->img[0].size_line, &data->img[0].endian);
	ft_get_data_addr(data);
	while (i < WIDTH)
	{
		data->game->index = i;
		data->rcasting->camerax = 2 * i / (double)WIDTH - 1;
		data->rcasting->raydirx = data->rcasting->dirx + \
		data->rcasting->planex * data->rcasting->camerax;
		data->rcasting->raydiry = data->rcasting->diry + \
		data->rcasting->planey * data->rcasting->camerax;
		data->rcasting->mapx = (int)data->rcasting->posx;
		data->rcasting->mapy = (int)data->rcasting->posy;
		continue_init_win(data);
		i++;
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win, \
	data->img[0].ptr, 0, 0);
}
