/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:32:58 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/24 20:41:14 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	find_map_symbol(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '0' && str[i] != '1' && \
		str[i] != 'S' && str[i] != 'N' && \
		str[i] != 'W' && str[i] != 'E' && str[i] != ' ')
			return (-1);
	}
	return (0);
}

int	find_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (0);
	}
	return (-1);
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
