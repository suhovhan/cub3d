/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:47:33 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/24 20:48:05 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char		**map;
	t_addres	addres;

	addres.cub.map = NULL;
	addres.cub.texture = NULL;
	addres.elements._no = NULL;
	addres.elements._so = NULL;
	addres.elements._we = NULL;
	addres.elements._ea = NULL;
	check_args(ac, av);
	map = getmap(av[1]);
	parser(&addres, &map);
	init_structs(&addres);
	addres.data = data_collector(addres.cub);
	initializer(&addres);
	init_win(&addres);
	mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
	mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
	mlx_loop(addres.game->mlx);
	return (0);
}
