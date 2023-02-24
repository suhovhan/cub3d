#include "cub3d.h"

void	print_close(t_addres *address, char *str)
{
	write(1, str, ft_strlen(str));
	free_all(address);
}

int	close_game(t_addres *address)
{
	print_close(address, "Game closed successfully\n");
	exit(0);
}

void	print_error(t_addres *address, char *err, int flag)
{
	write(2, "Error!\n", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	if (flag == 1)
		free_all(address);
	exit(EXIT_FAILURE);
}
