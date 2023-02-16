#include "cub3d.h"

char	*join_mtx(char **mtx)
{
	int		i;
	char	*ptr;
	char	*line;

	i = -1;
	line = NULL;
	while (mtx[++i])
	{
		ptr = line;
		if (line == NULL)
			line = ft_strdup(mtx[i]);
		else
			line = ft_strjoin(ptr, mtx[i]);
		free(ptr);
	}
	return (line);
}

int	tab_count(char	*str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\t')
			count++;
	return (count);
}

char	*open_tabs(char *str, int count)
{
	char	*line;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	line = (char *)malloc(sizeof(char) * ((count * 3) + len + 1));
	printf("%d\n", (count * 3) + len + 1);
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
			while (j < j + 4)
				line[++j] = ' ';
		else
			line[++j] = str[i];
	}
	line[++j] = '\0';
	printf("j = %d\n", j);
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

int	find_char(char *str)
{
	int	i = -1;
	while (str[++i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (0);
	}
	return (-1);
}