#ifndef STRUCT_H
# define STRUCT_H

#define WIN_WIDTH 1000
#define WIN_HEIGHT 800

typedef struct	s_cub
{
	char	**map;
	char	**texture;
}				t_cub;

typedef struct	s_elements
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
}				t_elements;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
	int		x;
	int		y;
}				t_data;

# endif