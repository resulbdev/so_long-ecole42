/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coin_exit_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:52:05 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/18 17:28:06 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_coin_exit_check(t_map *mapes, char *map, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		if (map[i] == c)
			k++;
		i++;
	}
	if ((c == 'P' && k != 1) || (c == 'E' && k != 1))
		ft_error2(mapes);
	if (c == 'C' && k < 1)
		ft_error2(mapes);
	else if (c == 'C' && k >= 1)
		mapes->c_coin = k;
}
