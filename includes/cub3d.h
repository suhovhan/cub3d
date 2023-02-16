#ifndef CUB3D_H
# define CUB3D_H

#include <string.h>
#include <math.h>
#include "structs.h"
#include "../libft/libft.h"
#include "../getnextline/get_next_line.h"

void    p_mtx(char **mtx);

int		check_extension(char *s1, char *s2, size_t n);
int		check_args(int ac, char **av);
char	*read_map(int fd);
char	**getmap(char *filename);
char	*open_tabs(char *str, int count);
char	*reset_tabs(char *str);
char	*join_mtx(char **mtx);
void	free_mtx(char **mtx);
void	clean_tabs(char **map);
int		find_char(char *str);

# endif