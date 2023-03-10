#include "cub3d.h"

int	texture_collector(t_cub *cub, char **mtx)
{
	char	**texture;
	int		i;

	i = -1;
	texture = (char **)malloc(sizeof(char *) * 7);
	if (!texture)
		return (-1);
	while (++i < 6)
	{
		if (!mtx[i])
			return (-1);
		texture[i] = ft_strdup(mtx[i]);
		if (!texture[i])
			return (-1);
	}
	texture[i] = 0;
	cub->texture = texture;
	return (0);
}

int	map_collector(t_cub *cub, char **mtx)
{
	int		i;
	int		height;
	char	**map;

	i = 5;
	height = -1;
	while (mtx[++height])
		;
	map = (char **)malloc(sizeof(char *) * (height - 5));
	if (!map)
		return (-1);
	height = -1;
	while (mtx[++i])
	{
		map[++height] = ft_strdup(mtx[i]);
		if (!map[height])
			return (-1);
	}
	map[++height] = 0;
	cub->map = map;
	return (0);
}

int	struct_collector(t_cub *cub, char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return (-1);
	while (mtx[++i])
		;
	if (i < 8)
		return (-1);
	if (texture_collector(cub, mtx) == -1)
		return (-1);
	if (map_collector(cub, mtx) == -1)
		return (-1);
	return (0);
}

int	color_collector(t_elements *elements, char **sp, int flag)
{
	int	R;
	int	G;
	int	B;

	R = ft_atoi(sp[0]);
	G = ft_atoi(sp[1]);
	B = ft_atoi(sp[2]);
	if (R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255 || \
	ft_strlen(sp[0]) > 4 || ft_strlen(sp[1]) > 4 || ft_strlen(sp[2]) > 4)
		return (-1);
	if (flag == 0)
	{
		elements->C[0] = R;
		elements->C[1] = G;
		elements->C[2] = B;
	}
	else if (flag == 1)
	{
		elements->F[0] = R;
		elements->F[1] = G;
		elements->F[2] = B;
	}
	return (0);
}

int	elements_collector(t_elements *elements, char **texture)
{
	int		i;
	int		ret;
	char	**sp;

	i = -1;
	ret = 0;
	while (++i < 6 && texture[i])
	{
		sp = ft_split(texture[i], ' ');
		if (ft_strcmp(sp[0], "NO") == 0)
			elements->NO = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "SO") == 0)
			elements->SO = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "WE") == 0)
			elements->WE = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "EA") == 0)
			elements->EA = ft_strdup(sp[1]);
		if (ft_strcmp(sp[0], "F") == 0 || ft_strcmp(sp[0], "C") == 0)
			ret = color_checker(elements, texture[i]);
		free_mtx(sp);
	}
	return (ret);
}

void	getter_cub(t_data *data, t_cub cub)
{
	int		i;
	char	**map;

	i = -1;
	while (cub.map[++i])
		;
	map = (char **)malloc(sizeof(char *) * (i + 2));
	if (!map)
		return ;
	i = -1;
	while (cub.map[++i])
		map[i] = ft_strdup(cub.map[i]);
	map[i] = 0;
	data->map = map;
}

t_data	data_collector(t_cub cub)
{
	t_data	data;

	data.map = NULL;
	data.x = -1;
	data.y = -1;
	getter_cub(&data, cub);
	return (data);
	while (data.map[++(data.y)])
	{
		data.x = -1;
		while (data.map[++data.x])
			if (data.map[data.x][data.y] == 'E' || data.map[data.x][data.y] == 'N' \
			|| data.map[data.x][data.y] == 'S' || data.map[data.x][data.y] == 'W')
			{
				data.pos_x = data.x;
				data.pos_y = data.y;
				break ;
			}
	}
	data.x = -1;
	data.y = -1;
}
