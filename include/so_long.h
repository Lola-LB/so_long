/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:16:23 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/10 18:52:17 by lle-bret         ###   ########.fr       */
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
# define FORBIDDEN_CHAR "Map contains forbidden characters"
# define MALLOC_ERROR "Malloc error"

# define W 
# define A 
# define D 
# define S 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_loc {
	int	x;
	int	y;
}	t_loc;

typedef struct s_map {
	char	**map;
	int		width;
	int		len;
}	t_map;

typedef struct	s_param {
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	*img;
	t_loc	player;
}	t_param;

/* ************************************************************************** */
/*                                   main.c                                   */
/* ************************************************************************** */

void	launch_game(t_map map);
void	end_game(t_param param);

/* ************************************************************************** */
/*                                 parse_map.c                                */
/* ************************************************************************** */

int		map_len(char *file);
void	check_extension(char *file);
t_map	parse_map(char *file);

/* ************************************************************************** */
/*                                 check_map.c                                */
/* ************************************************************************** */

void	char_contained(char **map);
void	closed_walls(char **map);
void	rectangular(char **map);
int		check_map(t_map *map);

/* ************************************************************************** */
/*                                 find_path.c                                */
/* ************************************************************************** */

void	expand_path(char **map, int px, int py);
void	explore_map(char **map, int px, int py);
void	valid_path(t_map map);
char	**ft_mapcopy(t_map src);

/* ************************************************************************** */
/*                                   utils.c                                  */
/* ************************************************************************** */

void	ft_exit(t_param *param, char *error);
void	print_map(char **map);

/* ************************************************************************** */
/*                                 display.c                                  */
/* ************************************************************************** */

void	init_images(t_param *param);
void	*get_img(t_param *param, int i, int j);
void	images_to_map(t_param *param);

/* ************************************************************************** */
/*                                   events.c                                 */
/* ************************************************************************** */

int	handle_key(int keysym, t_param *param);
int	handle_no_event(t_param *param);

#endif