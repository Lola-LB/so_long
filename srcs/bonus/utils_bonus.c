/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/14 19:22:58 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		++i;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

void	ft_error(t_param *param, char *error)
{
	printf("Error\n%s\n", error);
	end_game(param);
}

void	init_param(t_param *param, t_map map)
{
	param->map = map;
	param->mlx = NULL;
	param->win = NULL;
	check_map(param);
	init_enemy(param);
	param->left = 0;
	param->burp = 0;
	param->move = 0;
	param->end_game = 0;
}

void	end_screen(t_param *param, int win)
{
	param->end_game = 1;
	if (win)
		mlx_put_image_to_window(param->mlx, param->win, param->img[15].img, 0, 0);
	else
		mlx_put_image_to_window(param->mlx, param->win, param->img[14].img, 0, 0);
}
