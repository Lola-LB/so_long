/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:49 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/12 16:49:17 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_player(t_param *param, t_loc old, int x, int y)
{
	if (param->map.map[x][y] != '1')
	{
		if (param->map.map[x][y] == 'C')
			param->coll--;
		else if (param->map.map[x][y] == 'E' && param->coll == 0)
			end_game(param);
		param->map.map[x][y] = 'P';
		param->map.map[old.x][old.y] = '0';
		param->player.x = x;
		param->player.y = y;
		param->move++;
		ft_printf("%d\n", param->move);
	}
}

void	move_player(int keysym, t_param *param)
{
	if (keysym == W && param->player.x)
		swap_player(param, param->player, param->player.x - 1, param->player.y);
	else if (keysym == A && param->player.y)
	{
		param->left = 1;
		swap_player(param, param->player, param->player.x, param->player.y - 1);
	}
	else if (keysym == S && param->player.x != param->map.len)
		swap_player(param, param->player, param->player.x + 1, param->player.y);
	else if (keysym == D && param->player.y != param->map.width)
	{
		param->left = 0;
		swap_player(param, param->player, param->player.x, param->player.y + 1);
	}
}

int	handle_key(int keysym, t_param *param)
{
	if (keysym == XK_Escape)
		end_game(param);
	else if (keysym == W || keysym == A || keysym == S || keysym == D)
	{
		move_player(keysym, param);
		images_to_map(param);
	}
	return (0);
}

int	handle_no_event(t_param *param)
{
	(void) param;
	return (0);
}
