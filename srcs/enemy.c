/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:05:34 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/13 18:56:52 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	nb_enemy(t_param *param)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = 1;
	while (i < param->map.len - 1)
	{
		j = 1;
		while (j < param->map.width - 1)
		{
			if (param->map.map[i][j] == '0')
				++nb;
			++j;
		}
		++i;
	}
	return ((nb / 20) + (nb < 20) * (nb > 0));
}

void	init_enemy(t_param *param)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	param->enemy.nb = nb_enemy(param);
	param->enemy.loc = malloc (sizeof(t_loc) * param->enemy.nb);
	if (!param->enemy.loc)
		ft_error(param, MALLOC_ERROR);
	while (i < param->enemy.nb)
	{
		x = 0;
		y = 0;
		while (param->map.map[x][y] != '0')
		{
			x = rand() % param->map.len;
			y = rand() % param->map.width;
		}
		param->enemy.loc[i].x = x;
		param->enemy.loc[i].y = y;
		param->map.map[x][y] = 'X';
		++i;
	}
}

void	move_enemy(t_param *param)
{
	int	i;
	int	dep;
	int	x;
	int	y;

	i = 0;
	while (i < param->enemy.nb)
	{
		x = 0;
		y = 0;
		while (param->map.map[param->enemy.loc[i].x + x][param->enemy.loc[i].y + y] != '0'
		&& param->map.map[param->enemy.loc[i].x + x][param->enemy.loc[i].y + y] != 'P')
		{
			dep = rand() % 4;
			x = (dep == 0) - (dep == 1);
			y = (dep == 2) - (dep == 3);
		}
		param->map.map[param->enemy.loc[i].x][param->enemy.loc[i].y] = '0';
		param->enemy.loc[i].x += x;
		param->enemy.loc[i].y += y;
		param->map.map[param->enemy.loc[i].x][param->enemy.loc[i].y] = 'X';
		++i;
	}
}

void	check_enemy(t_param *param)
{
	int	x;
	int	y;
	int	i;

	x = param->player.x;
	y = param->player.y;
	i = 0;
	while (i < param->enemy.nb)
	{
		if (param->enemy.loc[i].x == x && param->enemy.loc[i].y == y)
			game_over(param);
		++i;
	}
}
