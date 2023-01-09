/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:16:23 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/09 19:25:34 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MULT_EXIT "Map contains multiple exits"
# define NO_EXIT "Map does not contain any exit"
# define MULT_START "Map contains multiple starting positions"
# define NO_START "Map does not contain any starting position"
# define NO_COLL "Map does not contain any collectible"
# define NO_WALLS "Map is not surrounded by walls"
# define NOT_RECTANGULAR "Map is not rectangular"
# define NO_VALID_PATH "There is no valid path in the map"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

typedef struct s_map {
	char	**map;
	int		width;
	int		len;
	t_pos	player;
	t_pos	exit;
	t_pos	*col;
}	t_map;

// Main

// Parse Map
int		map_len(char *file);
void	check_extension(char *file);
char	**parse_map(char *file);


// Check Map
void	char_contained(char **map);
void	expand_path(char **map, int px, int py);
void	explore_map(char **map, int px, int py);
void	valid_path(char **map);
void	closed_walls(char **map);
void	rectangular(char **map);
int		check_map(char **map);

// Utils
void	ft_exit(char *error);

// Game
void	launch_game(t_map map);

#endif