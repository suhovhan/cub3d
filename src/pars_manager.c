#include "cub3d.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return ;
	while (mtx[++i])
		free(mtx[i]);
	free(mtx);
}

char	**getmap(char *filename)
{
	int		fd;
	char	*full_line;
	char	**map;

	fd = open(filename, O_RDONLY);
	map = NULL;
	if (fd == -1)
		return (NULL);
	full_line = read_map(fd);
	map = ft_split(full_line, '\n');
	free(full_line);
	close(fd);
	return (map);
}

char	*read_map(int fd)
{
	char	*ptr;
	char	*line;
	char	*full_line;

	full_line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ptr = full_line;
		if (find_char(line) == 0)
		{
			if (full_line == NULL)
				full_line = ft_strdup(line);
			else
				full_line = ft_strjoin(ptr, line);
			free(ptr);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (full_line);
}

void	clean_tabs(char **map)
{
	int		i;
	char	*ptr;

	i = -1;
	while (map[++i])
	{
		ptr = map[i];
		map[i] = reset_tabs(ptr);
		free(ptr);
	}
}