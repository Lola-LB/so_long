/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:16:23 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/14 20:38:58 by lle-bret         ###   ########.fr       */
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
# define MLX_ERROR "Minilibx error"
# define FILE_ERROR "File error"

# define NB_FILES 26
# define NUM_OFFSET 16
# define NB_PIXEL 70


# define W 126 //119 //65362 //126
# define A 123 //97 //65361 //123
# define S 125 //115 //65364 //125
# define D 124 //100 //65363 //124
# define XK_Escape 53


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include <X11/keysym.h>
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

typedef struct s_enemy {
	t_loc	*loc;
	int		nb;
}	t_enemy;

typedef struct	s_param {
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	*img;
	t_loc	player;
	t_loc	exit;
	t_enemy	enemy;
	int		move;
	int		coll;
	int		left;
	int		burp;
	int		end_game;
}	t_param;

/* ************************************************************************** */
/*                                   main.c                                   */
/* ************************************************************************** */

void	launch_game(t_param	*param);
int		end_game(t_param *param);

/* ************************************************************************** */
/*                                 map_parse.c                                */
/* ************************************************************************** */

int		map_len(char *file);
void	check_extension(char *file);
t_map	parse_map(char *file);

/* ************************************************************************** */
/*                                 map_check.c                                */
/* ************************************************************************** */

void	closed_walls(t_param *param);
void	rectangular(t_param *param);
void	clean_map(t_param *param);
int		check_map(t_param *param);

/* ************************************************************************** */
/*                                 map_char.c                                 */
/* ************************************************************************** */

void	check_char(t_param *param, int exit, int start, int collectible);
void	init_player(t_param *param, int *start, int i, int j);
void	char_contained(t_param *param, int exit, int start, int collectible);

/* ************************************************************************** */
/*                                 map_path.c                                 */
/* ************************************************************************** */

void	expand_path(char **map, int px, int py);
void	explore_map(char **map, int px, int py);
void	valid_path(t_map map);
char	**ft_mapcopy(t_map src);

/* ************************************************************************** */
/*                                   utils.c                                  */
/* ************************************************************************** */

void	ft_error(t_param *param, char *error);
void	print_map(char **map);
void	free_map(char **map);
void	init_param(t_param *param, t_map map);
void	end_screen(t_param *param, int win);

/* ************************************************************************** */
/*                                  display.c                                 */
/* ************************************************************************** */

void	init_images(t_param *param);
void	*get_img(t_param *param, int i, int j);
void	images_to_map(t_param *param);

/* ************************************************************************** */
/*                                   events.c                                 */
/* ************************************************************************** */

int		handle_key(int keysym, t_param *param);
int		handle_no_event(t_param *param);
int		handle_live(t_param *param);

/* ************************************************************************** */
/*                                    score.c                                 */
/* ************************************************************************** */

void	display_score(t_param *param);

#endif