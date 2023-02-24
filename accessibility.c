/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:52:20 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/23 13:46:25 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	accessibility_check(t_map *mapes, char **map_split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mapes->coin_count = 0;
	while (i < mapes->column_count)
	{
		j = 0;
		while (j < mapes->line_count)
		{
			if (map_split[i][j] == 'P')
			{
				mapes->y = i;
				mapes->x = j;
			}
			j++;
		}
		i++;
	}
	player_accessibility_check(mapes, map_split, mapes->y, mapes->x);
	if (mapes->exit_count != 1 || mapes->c_coin != mapes->coin_count)
		ft_error(mapes);
}

void	player_accessibility_check2(t_map *mapes, char **map_split, int y,
		int x)
{
	if (map_split[y - 1][x] == '0' || map_split[y - 1][x] == 'C' || map_split[y
		- 1][x] == 'E')
	{
		if (map_split[y - 1][x] == 'C')
			mapes->coin_count++;
		if (map_split[y - 1][x] == 'E')
			mapes->exit_count = 1;
		map_split[y - 1][x] = 'x';
		player_accessibility_check(mapes, map_split, y - 1, x);
	}
	if (map_split[y + 1][x] == '0' || map_split[y + 1][x] == 'C' || map_split[y
		+ 1][x] == 'E')
	{
		if (map_split[y + 1][x] == 'C')
			mapes->coin_count++;
		if (map_split[y + 1][x] == 'E')
			mapes->exit_count = 1;
		map_split[y + 1][x] = 'x';
		player_accessibility_check(mapes, map_split, y + 1, x);
	}
}

void	player_accessibility_check(t_map *mapes, char **map_split, int y, int x)
{
	if (map_split[y][x - 1] == '0' || map_split[y][x - 1] == 'C'
		|| map_split[y][x - 1] == 'E')
	{
		if (map_split[y][x - 1] == 'C')
			mapes->coin_count++;
		if (map_split[y][x - 1] == 'E')
			mapes->exit_count = 1;
		map_split[y][x - 1] = 'x';
		player_accessibility_check(mapes, map_split, y, x - 1);
	}
	if (map_split[y][x + 1] == '0' || map_split[y][x + 1] == 'C'
		|| map_split[y][x + 1] == 'E')
	{
		if (map_split[y][x + 1] == 'C')
			mapes->coin_count++;
		if (map_split[y][x + 1] == 'E')
			mapes->exit_count = 1;
		map_split[y][x + 1] = 'x';
		player_accessibility_check(mapes, map_split, y, x + 1);
	}
	player_accessibility_check2(mapes, map_split, y, x);
}
