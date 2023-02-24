/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:51:46 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/19 17:07:42 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(char **map_split, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_split[i][j])
		j++;
	map->line_count = j;
	j = 0;
	while (map_split[i][j] != '\0')
	{
		if (map_split[i][j] != '1')
			ft_error(map);
		j++;
	}
	i = map->column_count - 1;
	j = 0;
	wall_check3(i, j, map_split, map);
	wall_check2(map_split, map);
}

void	wall_check3(int i, int j, char **map_split, t_map *map)
{
	while (map_split[i][j] != '\0')
	{
		if (map_split[i][j] != '1')
			ft_error(map);
		j++;
	}
}

void	wall_check2(char **map_split, t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = map->char_count - 2;
	while (map_split[i])
	{
		if (map_split[i][0] != '1' || map_split[i][j] != '1')
			ft_error(map);
		i++;
	}
}

void	open_file2(void)
{
	int	fd4;
	int	fd5;
	int	fd6;

	fd4 = open("textures/grass.xpm", O_RDONLY);
	fd5 = open("textures/messi.xpm", O_RDONLY);
	fd6 = open("textures/wall.xpm", O_RDONLY);
	if (fd4 < 0 || fd5 < 0 || fd6 < 0)
	{
		ft_printf("error\n");
		close(fd4);
		close(fd5);
		close(fd6);
		exit(0);
	}
	close(fd4);
	close(fd5);
	close(fd6);
}

void	open_file(char *argv)
{
	int	fd;
	int	fd2;
	int	fd3;

	fd = open(argv, O_RDONLY);
	fd2 = open("textures/ball.xpm", O_RDONLY);
	fd3 = open("textures/cup.xpm", O_RDONLY);
	if (fd < 0 || fd2 < 0 || fd3 < 0)
	{
		ft_printf("error\n");
		close(fd);
		close(fd2);
		close(fd3);
		exit(0);
	}
	close(fd);
	close(fd2);
	close(fd3);
}
