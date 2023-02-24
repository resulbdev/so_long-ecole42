/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:52:17 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/19 17:19:51 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	space_check(t_map *map)
{
	int	i;

	i = 0;
	while (map->first_map[i])
	{
		if (map->first_map[i] == '\n' && map->first_map[i + 1] == '\n')
		{
			ft_error2(map);
		}
		i++;
	}
}

void	map_ber_check(char *map, t_map *mapes)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] != 'r' || map[i - 2] != 'e' || map[i - 3] != 'b' || map[i
			- 4] != '.')
	{
		ft_printf("error\n");
		free(mapes);
		exit(0);
	}
}

void	all_chcek(t_map *mapes)
{
	space_check(mapes);
	character_check(mapes);
	player_coin_exit_check(mapes, mapes->first_map, 'P');
	player_coin_exit_check(mapes, mapes->first_map, 'C');
	player_coin_exit_check(mapes, mapes->first_map, 'E');
}

void	character_check(t_map *map)
{
	int	i;

	i = 0;
	while (map->first_map[i])
	{
		if (map->first_map[i] != '1' && map->first_map[i] != '0'
			&& map->first_map[i] != 'P' && map->first_map[i] != 'C'
			&& map->first_map[i] != 'E' && map->first_map[i] != '\n')
			ft_error2(map);
		i++;
	}
}
