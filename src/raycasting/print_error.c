/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:16:16 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 18:09:15 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_close(t_data *data, char *str)
{
	write(1, str, ft_strlen(str));
	free_all(data);
}

int	close_game(t_data *data)
{
	print_close(data, "Game closed successfully\n");
	exit(0);
}

void	print_error(t_data *data, char *err, int flag)
{
	write(2, "Error!\n", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	if (flag == 1)
		free_all(data);
	exit(EXIT_FAILURE);
}
