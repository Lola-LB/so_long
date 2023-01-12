/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/12 16:56:34 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	param->left = 0;
	param->move = 0;
}
