/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:38:04 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/15 16:57:26 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_attack(t_param *param)
{
	param->attack.way =  1 - 2 * param->left;
	print_map(param->map.map);
	if (param->map.map[param->player.x][param->player.y + param->attack.way] != '1')
	{
		param->attack.active = 1;
		param->attack.loc.x = param->player.x;
		param->attack.loc.y = param->player.y + param->attack.way;
	}
	printf("player attack : %d, %d\n", param->attack.loc.x, param->attack.loc.y);
}

void	display_attack(t_param *param)
{
	if (param->attack.active && !param->end_game)
		mlx_put_image_to_window(param->mlx, param->win, param->img[26].img, param->attack.loc.y * NB_PIXEL, param->attack.loc.x * NB_PIXEL);
}

void	move_attack(t_param *param)
{
	int	way;
	int	x;
	int	y;

	way = param->attack.way;
	x = param->attack.loc.x;
	y = param->attack.loc.y;
	if (param->map.map[x][y + way] == 'X')
	{
		kill_enemy(param, x, y + way);
		param->attack.active = 0;
	}
	else if (param->map.map[x][y + way] == '1')
	{
		param->attack.active = 0;
	}
	else
	{
		param->attack.loc.y += way;
		printf("move %d, %d\n", param->attack.loc.x, param->attack.loc.y);
	}
}