#ifndef STRUCT_H
# define STRUCT_H


#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define WIN_WIDTH 920
#define WIN_HEIGHT 800
#define	SIZE 64

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

typedef struct	s_data
{
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	int		pos_x;
	int		pos_y;
	void	*mlx;
	void	*win;
	char	**map;
	int		f_color;
	int		c_color;
	int		x;
	int		y;
}				t_data;

typedef struct	s_raycaster
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldtime;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
}				t_raycaster;

# endif