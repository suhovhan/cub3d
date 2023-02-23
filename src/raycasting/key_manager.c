/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:26:02 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 14:43:47 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_manager(int key, t_data *data)
{
	if (key == ESC)
		close_game(data);
	if (key == RIGHT)
		rotate_right(data, -ROTATE_SPEED);
	if (key == LEFT)
		rotate_right(data, ROTATE_SPEED);
	if (key == A)
		move_left(data);
	if (key == D)
		move_right(data);
	if (key == W)
		move_up(data);
	if (key == S)
		move_down(data);
	init_win(data);
	return (0);
}
