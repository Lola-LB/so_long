/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:05:56 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/13 19:01:47 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(t_param *param, int exit, int start, int collectible)
{
	if (exit > 1)
		ft_error(param, MULT_EXIT);
	if (start > 1)
		ft_error(param, MULT_START);
	if (!exit)
		ft_error(param, NO_EXIT);
	if (!start)
		ft_error(param, NO_START);
	if (!collectible)
		ft_error(param, NO_COLL);
}

void	init_player(t_param *param, int *start, int i, int j)
{
	param->player.x = i;
	param->player.y = j;
	++*start;
}

void	char_contained(t_param *param, int exit, int start, int collectible)
{
	int	i;
	int	j;

	i = 1;
	while (param->map.map[i + 1])
	{
		j = 1;
		while (param->map.map[i][j + 1])
		{
			exit += (param->map.map[i][j] == 'E');
			collectible += (param->map.map[i][j] == 'C');
			if (param->map.map[i][j] == 'P')
				init_player(param, &start, i, j);
			else if (!ft_strchr("01EC", param->map.map[i][j]))
				ft_error(param, FORBIDDEN_CHAR);
			++j;
		}
		++i;
	}
	param->coll = collectible;
	check_char(param, exit, start, collectible);
}