/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:51:56 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/23 13:51:36 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map(char *map, t_map *mapes)
{
	int		i;
	char	*line;
	char	*map_array;
	int		fd;

	line = NULL;
	map_array = "";
	fd = open(map, O_RDONLY);
	i = 0;
	while (line != NULL || i == 0)
	{
		line = get_next_line(fd);
		check_null(line, i, mapes);
		if (line != NULL)
		{
			if (i != 0)
				free(map_array);
			map_array = ft_strjoin(map_array, line);
		}
		free(line);
		i++;
	}
	return (map_array);
}

void	check_null(char *line, int i, t_map *mapes)
{
	if (!line && i == 0)
	{
		ft_printf("error");
		free(mapes);
		exit(0);
	}
}

void	print_score(t_map *mapes)
{
	ft_printf("Score: %d\n", mapes->score);
}

void	put_score(t_map *mapes)
{
	char	*score;

	score = ft_itoa(mapes->score);
	mlx_string_put(mapes->mlx, mapes->win, 20, 20, 0x00FFFFFF, score);
	free(score);
}

int	main(int argc, char **argv)
{
	t_map	*mapes;
	int		i;

	if (argc != 2)
		exit(0);
	open_file(argv[1]);
	open_file2();
	mapes = malloc(sizeof(t_map));
	mapes->score = 0;
	map_ber_check(argv[1], mapes);
	mapes->first_map = get_map(argv[1], mapes);
	all_chcek(mapes);
	mapes->map = ft_split(mapes->first_map, '\n');
	mapes->copy_map = ft_split(mapes->first_map, '\n');
	i = line_count(mapes->map, mapes);
	mapes->column_count = 0;
	while (mapes->map[mapes->column_count])
		mapes->column_count++;
	if (i)
		ft_error(mapes);
	wall_check(mapes->map, mapes);
	accessibility_check(mapes, mapes->copy_map);
	open_window(mapes, &mapes->img);
}
