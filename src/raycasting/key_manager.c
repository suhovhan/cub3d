#include "cub3d.h"

int	key_manager(int key, t_addres *address)
{
	if (key == ESC)
		close_game(address);
	if (key == RIGHT)
		rotate_right(address, -ROTATE_SPEED);
	if (key == LEFT)
		rotate_right(address, ROTATE_SPEED);
	if (key == A)
		move_left(address);
	if (key == D)
		move_right(address);
	if (key == W)
		move_up(address);
	if (key == S)
		move_down(address);
	init_win(address);
	return (0);
}
