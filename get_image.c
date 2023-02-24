/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:52:10 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/18 13:01:10 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_image(t_image *img, t_map *mapes)
{
	img->mesi = mlx_xpm_file_to_image(mapes->mlx, "./textures/messi.xpm",
			&img->width, &img->height);
	img->cup = mlx_xpm_file_to_image(mapes->mlx, "./textures/cup.xpm",
			&img->width, &img->height);
	img->ball = mlx_xpm_file_to_image(mapes->mlx, "./textures/ball.xpm",
			&img->width, &img->height);
	img->gren = mlx_xpm_file_to_image(mapes->mlx, "./textures/grass.xpm",
			&img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mapes->mlx, "./textures/wall.xpm",
			&img->width, &img->height);
}

void	put_image2(t_map *mapes, int i, int j)
{
	if (mapes->map[i][j] == '1')
		mlx_put_image_to_window(mapes->mlx, mapes->win, mapes->img.wall,
			mapes->p_x, mapes->p_y);
	if (mapes->map[i][j] == '0')
		mlx_put_image_to_window(mapes->mlx, mapes->win, mapes->img.gren,
			mapes->p_x, mapes->p_y);
	if (mapes->map[i][j] == 'C')
		mlx_put_image_to_window(mapes->mlx, mapes->win, mapes->img.ball,
			mapes->p_x, mapes->p_y);
	if (mapes->map[i][j] == 'E')
		mlx_put_image_to_window(mapes->mlx, mapes->win, mapes->img.cup,
			mapes->p_x, mapes->p_y);
	if (mapes->map[i][j] == 'P')
		mlx_put_image_to_window(mapes->mlx, mapes->win, mapes->img.mesi,
			mapes->p_x, mapes->p_y);
}

void	put_image(t_map *mapes)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mapes->p_x = 0;
	mapes->p_y = 0;
	while (i < mapes->column_count)
	{
		j = 0;
		while (j < mapes->line_count)
		{
			put_image2(mapes, i, j);
			put_score(mapes);
			j++;
			mapes->p_x += 64;
		}
		i++;
		mapes->p_x = 0;
		mapes->p_y += 64;
	}
}
