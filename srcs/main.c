/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:41:26 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/09 19:26:28 by lle-bret         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_map	map;
	
	if (ac < 2)
		ft_exit("Error\nMust provide a map to launch the game");

	map.map = parse_map(*(av + 1));
	if (!map.map || !*map.map)
		ft_exit("Error\nParsing of the map failed");
	check_map(map.map);
	launch_game(map);

	return (0);
}
