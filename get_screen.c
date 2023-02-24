/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:52:13 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/19 17:18:03 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_walk(t_map *mapes, int x, int y)
{
	if (mapes->map[y / 64][x / 64] == 'E')
	{
		if (mapes->coin_count == 0)
		{
			mapes->score++;
			print_score(mapes);
			close_window(mapes);
		}
		else
			return (1);
	}
	if (mapes->map[y / 64][x / 64] != 'E' && mapes->map[y / 64][x / 64] != '1')
	{
		mapes->score++;
		if (mapes->map[y / 64][x / 64] == 'C')
			mapes->coin_count--;
		mapes->map[mapes->y / 64][mapes->x / 64] = '0';
		mapes->map[y / 64][x / 64] = 'P';
		print_score(mapes);
	}
	return (0);
}

void	walk2(int keycode, t_map *mapes)
{
	if (keycode == 13 && mapes->map[(mapes->y - 64) / 64][mapes->x / 64] != '1')
	{
		if (p_walk(mapes, mapes->x, mapes->y - 64) == 0)
			mapes->y -= 64;
	}
	if (keycode == 1 && mapes->map[(mapes->y + 64) / 64][mapes->x / 64] != '1')
	{
		if (p_walk(mapes, mapes->x, mapes->y + 64) == 0)
			mapes->y += 64;
	}
}

int	walk(int keycode, t_map *mapes)
{
	mlx_clear_window(mapes->mlx, mapes->win);
	if (keycode == 2 && (mapes->map[mapes->y / 64][(mapes->x + 64)
			/ 64] != '1'))
	{
		if (p_walk(mapes, mapes->x + 64, mapes->y) == 0)
			mapes->x += 64;
	}
	if (keycode == 0 && mapes->map[mapes->y / 64][(mapes->x - 64) / 64] != '1')
	{
		if (p_walk(mapes, mapes->x - 64, mapes->y) == 0)
			mapes->x -= 64;
	}
	walk2(keycode, mapes);
	if (keycode == 53)
		close_window(mapes);
	put_image(mapes);
	return (keycode);
}

int	close_window(t_map *mapes)
{
	free_all(mapes);
	exit(0);
	return (0);
}

void	open_window(t_map *mapes, t_image *img)
{
	mapes->x = mapes->x * 64;
	mapes->y = mapes->y * 64;
	mapes->l_y = mapes->column_count * 64;
	mapes->l_x = mapes->line_count * 64;
	mapes->mlx = NULL;
	mapes->mlx = mlx_init();
	mapes->win = NULL;
	mapes->win = mlx_new_window(mapes->mlx, mapes->l_x, mapes->l_y, "so_long");
	xpm_image(img, mapes);
	put_image(mapes);
	mlx_hook(mapes->win, 2, (1L << 0), walk, mapes);
	mlx_hook(mapes->win, 17, 0, close_window, mapes);
	mlx_loop(mapes->mlx);
}
