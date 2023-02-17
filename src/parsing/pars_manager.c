#include "cub3d.h"

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
	int		flag;

	flag = 0;
	full_line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ptr = full_line;
		if (find_char(line) == 0 || flag > 6)
		{
			flag++;
			if (ft_strcmp(line, "\n") == 0)
			{
				free(line);
				line = ft_strdup("    \n");
			}
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

char	*open_tabs(char *str, int count)
{
	char	*line;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	line = (char *)malloc(sizeof(char) * ((count * 3) + len) + 1);
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
		{
			line[++j] = ' ';
			line[++j] = ' ';
			line[++j] = ' ';
			line[++j] = ' ';
		}
		else
			line[++j] = str[i];
	}
	line[++j] = '\0';
	return (line);
}

char	*reset_tabs(char *str)
{
	char	*line;
	int		count;

	if (!str)
		return (NULL);
	count = tab_count(str);
	if (count == 0)
		return (ft_strdup(str));
	line = open_tabs(str, count);
	return (line);
}