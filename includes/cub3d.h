#ifndef CUB3D_H
# define CUB3D_H

#include <string.h>
#include <math.h>
#include <mlx.h>
#include "structs.h"
#include "../libft/libft.h"
#include "../src/getnextline/get_next_line.h"

//	main.c
void    p_mtx(char **mtx);
void    p_data(t_data data);

//	checker.c
int		check_extension(char *s1, char *s2, size_t n);
int		check_args(int ac, char **av);
int 	check_texture_symbols(char *str);
int		check_texture_args(char **texture);
int		check_texture(char **texture);
int		color_checker(t_elements *elements, char *str);
int 	checker(t_cub cub);

//	collector.c
int		texture_collector(t_cub *cub, char **mtx);
int		map_collector(t_cub *cub, char **mtx);
int 	struct_collector(t_cub *cub, char **mtx);
int		color_collector(t_elements *elements, char **sp, int flag);
int		elements_collector(t_elements *elements, char **texture);
void	getter_cub(t_data *data, t_cub cub);
void	getter_elements(t_data *data, t_elements elements);
t_data	data_collector(t_cub cub);

//	free_and_exit.c
void	free_mtx(char **mtx);
void	free_cub(t_cub cub);
void	free_elements(t_elements elements);

//	pars_manager.c
char	**getmap(char *filename);
char	*read_map(int fd);
void	clean_tabs(char **map);
char	*open_tabs(char *str, int count);
char	*reset_tabs(char *str);

//	utils.c
char	*join_mtx(char **mtx);
int		find_char(char *str);
int		find_map_symbol(char *str);
int		tab_count(char	*str);

//	draw+window.c
void	initializer(t_data *data, t_elements elements);
void	draw_window(t_data *data);
int 	flat(t_data *data);

# endif