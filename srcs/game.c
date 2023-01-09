/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/09 19:27:23 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (vars)
		printf("%d\n", keycode);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	if (vars)
		printf("%d, %d\n", x, y);
	return (0);
}

void	launch_game(t_map map)
{
	t_vars	vars;
	void	*mlx;
	void	*win;
	// t_data	img;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "So Long");
	vars.mlx = mlx;
	vars.win = win;
	// img.img = mlx_xpm_file_to_image(mlx, "files/wall.xpm", &img.width, &img.height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	// //mlx_key_hook(win, key_hook, &vars);
	// mlx_hook(win, 6, (1L<<6), mouse_move, &vars);
	
	// //mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
	// mlx_loop(mlx);
}