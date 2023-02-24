/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:51:49 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/19 17:16:57 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->column_count)
	{
		free(map->map[i]);
		free(map->copy_map[i]);
		i++;
	}
	mlx_destroy_image(map->mlx, map->img.mesi);
	mlx_destroy_image(map->mlx, map->img.gren);
	mlx_destroy_image(map->mlx, map->img.wall);
	mlx_destroy_image(map->mlx, map->img.cup);
	free(map->map);
	free(map->first_map);
	free(map->copy_map);
	free(map);
}

int	line_count2(char **map_split)
{
	int	count;
	int	i;
	int	j;

	count = 1;
	i = 0;
	j = 0;
	while (map_split[i][j])
	{
		if (map_split[i][j] != '\0')
		{
			count++;
			j++;
		}
	}
	return (count);
}

int	line_count(char **map_split, t_map *map)
{
	int	i;
	int	j;
	int	line_count;

	i = 0;
	map->char_count = line_count2(map_split);
	i++;
	while (map_split[i])
	{
		line_count = 1;
		j = 0;
		while (map_split[i][j] != '\0')
		{
			line_count++;
			j++;
		}
		if (line_count != line_count2(map_split))
			return (1);
		i++;
	}
	map->line_count = line_count2(map_split) - 1;
	return (0);
}

void	ft_error(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->column_count)
	{
		free(map->map[i]);
		free(map->copy_map[i]);
		i++;
	}
	free(map->map);
	free(map->first_map);
	free(map->copy_map);
	free(map);
	ft_printf("error\n");
	exit(0);
}

void	ft_error2(t_map *map)
{
	free(map->first_map);
	free(map);
	ft_printf("error\n");
	exit(0);
}
