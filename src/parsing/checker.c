/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:23:38 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/24 20:28:28 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *s1, char *s2, size_t n)
{
	int	len;
	int	i;

	if (!s1 || !s2 || n <= 0)
		return (-1);
	len = (int)ft_strlen((const char *)s1);
	i = 0;
	while (s1[len - n + i] && s2[i])
	{
		if (s1[len - n + i] == s2[i])
			i++;
		else
			return (-1);
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Invalid count of arguments!\n");
		return (-1);
	}
	if (check_extension(av[1], ".cub", 4) != 0)
	{
		printf("Invalid path extension!\n");
		return (-1);
	}
	return (0);
}

int	check_texture_symbols(char *str)
{
	if (!str)
		return (-1);
	if (ft_strcmp(str, "NO") == 0)
		return (1);
	if (ft_strcmp(str, "WE") == 0)
		return (2);
	if (ft_strcmp(str, "SO") == 0)
		return (3);
	if (ft_strcmp(str, "EA") == 0)
		return (4);
	if (ft_strcmp(str, "F") == 0)
		return (5);
	if (ft_strcmp(str, "C") == 0)
		return (6);
	return (-1);
}

int	check_texture_args(char **texture)
{
	int	i;

	i = -1;
	if (!texture || !texture[0] || !texture[1])
	{
		printf("case 1\n");
		return (-1);
	}
	if ((ft_strcmp(texture[0], "NO") == 0 || ft_strcmp(texture[0], "SO") == 0 \
	|| ft_strcmp(texture[0], "WE") == 0 || ft_strcmp(texture[0], "EA") == 0) \
	&& texture[2])
	{
		printf("case 2\n");
		return (-1);
	}
	return (0);
}

int	check_texture(char **texture)
{
	char	**sp;
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (++i < 6)
	{
		if (!texture[i])
			return (-1);
		sp = ft_split(texture[i], ' ');
		if (!sp[0] || !sp[1])
		{
			free_mtx(sp);
			return (-1);
		}
		count += check_texture_symbols(sp[0]);
		count += check_texture_args(sp);
		free_mtx(sp);
	}
	if (count != 21)
		return (-1);
	return (0);
}
