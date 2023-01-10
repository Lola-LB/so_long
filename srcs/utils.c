/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/10 19:04:23 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		++i;
	}
}

void	ft_exit(t_param *param, char *error)
{
	if (param)
	{
		mlx_destroy_display(param->mlx);
		mlx_destroy_window(param->mlx, param->win);
		//free(param->win);
		//free(param->mlx);
	}
	ft_printf("Error\n%s\n", error);
	exit(0);
}
