/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:51:52 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/23 13:52:10 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*mesi;
	void	*cup;
	void	*ball;
	void	*gren;
	void	*wall;
	int		width;
	int		height;
}			t_image;

typedef struct s_map
{
	t_image	img;
	char	*first_map;
	char	**map;
	char	**copy_map;
	int		l_y;
	int		l_x;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		line_count;
	int		column_count;
	int		char_count;
	int		coin_count;
	int		exit_count;
	int		c_coin;
	int		score;
	void	*mlx;
	void	*win;
}			t_map;

int			line_count(char **map_split, t_map *map);
void		wall_check(char **map_split, t_map *map);
void		wall_check2(char **map_split, t_map *map);
void		player_coin_exit_check(t_map *mapes, char *map, char c);
void		space_check(t_map *map);
void		character_check(t_map *map);
void		player_accessibility_check(t_map *mapes, char **map_split, int i,
				int j);
void		player_accessibility_check2(t_map *mapes, char **map_split, int i,
				int j);
void		put_image(t_map *mapes);
void		xpm_image(t_image *img, t_map *mapes);
void		open_window(t_map *mapes, t_image *img);
void		accessibility_check(t_map *mapes, char **map_split);
int			p_walk(t_map *mapes, int x, int y);
int			walk(int keycode, t_map *mapes);
void		ft_error(t_map *map);
void		put_score(t_map *mapes);
void		map_ber_check(char *map, t_map *mapes);
void		all_chcek(t_map *mapes);
void		print_score(t_map *mapes);
void		wall_check3(int i, int j, char **map_split, t_map *map);
void		free_all(t_map *map);
int			close_window(t_map *mapes);
void		ft_error2(t_map *map);
void		open_file(char *argv);
void		open_file2(void);
void		check_null(char *line, int i, t_map *mapes);

#endif