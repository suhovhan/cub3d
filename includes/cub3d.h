/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:34:31 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/24 19:36:08 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <math.h>
# include <mlx.h>
# include "structs.h"
# include "../libft/libft.h"
# include "../src/getnextline/get_next_line.h"

int		check_extension(char *s1, char *s2, size_t n);
int		check_args(int ac, char **av);
int		check_texture_symbols(char *str);
int		check_texture_args(char **texture);
int		check_texture(char **texture);
int		color_checker(t_elements *elements, char *str);
int		checker(t_cub cub);
void	parser(t_addres *addres, char ***map);
int		texture_collector(t_cub *cub, char **mtx);
int		map_collector(t_cub *cub, char **mtx);
int		struct_collector(t_cub *cub, char **mtx);
int		color_collector(t_elements *elements, char **sp, int flag);
int		elements_collector(t_elements *elements, char **texture);
void	getter_cub(t_data *data, t_cub cub);
void	getter_elements(t_data *data, t_elements elements);
t_data	data_collector(t_cub cub);
void	free_mtx(char **mtx);
void	free_cub(t_cub cub);
void	free_elements(t_elements elements);
char	**getmap(char *filename);
char	*read_map(int fd);
void	clean_tabs(char **map);
char	*open_tabs(char *str, int count);
char	*reset_tabs(char *str);
void	init_struct_game(t_addres *address);
void	init_struct_index(t_addres *address);
void	init_struct_raycasting(t_addres *address);
void	init_structs(t_addres *address);
char	*join_mtx(char **mtx);
int		find_char(char *str);
int		find_map_symbol(char *str);
int		tab_count(char	*str);
void	initializer(t_addres *address);
void	init_win(t_addres *address);
void	find_pos_player(t_addres *address);
void	norm_init_win_2(t_addres *address);
void	norm_init_win(t_addres *address);
void	continue_init_win(t_addres *address);
int		ft_texx(t_addres *address, int n);
int		draw_walls(t_addres *address, char *dest, char *dest_2, int texx);
void	norm_init_win_3(t_addres *address);
float	ft_abs(float num);
char	*get_correct_arg(char *ptr);
void	init_plane(t_addres *address, double i, double j);
void	init_dir(t_addres *address, double i, double j);
void	init_player_pos(t_addres *address, int i, int j);
void	ft_get_data_addr(t_addres *address);
int		check_nwse(t_addres *address);
int		key_manager(int key, t_addres *address);
void	rotate_right(t_addres *address, double rotate);
void	move_left(t_addres *address);
void	move_right(t_addres *address);
void	move_up(t_addres *address);
void	move_down(t_addres *address);
int		close_game(t_addres *address);
void	free_all(t_addres *address);

#endif
