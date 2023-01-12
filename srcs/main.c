/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:41:26 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/12 15:43:49 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_param		param;
	t_map		map;

	if (ac < 2)
		ft_exit(NULL, "Must provide a map to launch the game");
	map = parse_map(*(av + 1));
	if (!map.map || !*map.map)
		ft_exit(NULL, "Parsing of the map failed");
	param.map = map;
	check_map(&param);
	init_player(&param);
	param.left = 0;
	param.move = 0;
	launch_game(param);
	return (0);
}

void	init_player(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i + 1 < param->map.len && param->map.map[i][j] != 'P')
	{
		++i;
		j = 1;
		while (j + 1 < param->map.width && param->map.map[i][j] != 'P')
			++j;
	}
	param->player.x = i;
	param->player.y = j;
}

void	launch_game(t_param	param)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, param.map.width * 50,
			param.map.len * 50, "Welcome to So Long !");
	param.mlx = mlx;
	param.win = win;
	init_images(&param);
	images_to_map(&param);
	//mlx_loop_hook(win, &handle_no_event, &param);
	mlx_key_hook(win, &handle_key, &param);
	mlx_loop(mlx);
	end_game(param);
}

void	end_game(t_param param)
{
	mlx_destroy_window(param.mlx, param.win);
	//free(param.win);
	//mlx_destroy_display(param.mlx);
	//free(param.mlx);
	exit(0);
}
