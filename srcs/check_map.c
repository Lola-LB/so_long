/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:24:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/12 15:41:26 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_contained(char **map)
{
	int	exit;
	int	start;
	int	collectible;
	int	i;
	int	j;

	i = 1;
	exit = 0;
	start = 0;
	collectible = 0;
	while (*(map + i + 1))
	{
		j = 1;
		while (*(*(map + i) + j + 1))
		{
			if (*(*(map + i) + j) == 'E')
				++exit;
			else if (*(*(map + i) + j) == 'P')
				++start;
			else if (*(*(map + i) + j) == 'C')
				++collectible;
			else if (*(*(map + i) + j) != '0' && *(*(map + i) + j) != '1')
				ft_exit(NULL, FORBIDDEN_CHAR);
			if (exit > 1)
				ft_exit(NULL, MULT_EXIT);
			if (start > 1)
				ft_exit(NULL, MULT_START);
			++j;
		}
		++i;
	}
	if (!exit)
		ft_exit(NULL, NO_EXIT);
	if (!start)
		ft_exit(NULL, NO_START);
	if (!collectible)
		ft_exit(NULL, NO_COLL);
	return (collectible);
}

void	closed_walls(char **map)
{
	int	i;
	int	j;
	int	width;

	width = ft_strlen(*map);
	i = 1;
	while (*(map + i + 1))
	{
		if (**(map + i) != '1' || *(*(map + i) + width - 1) != '1')
			ft_exit(NULL, NO_WALLS);
		++i;
	}
	j = 0;
	while (*(*map + j))
	{
		if (*(*map + j) != '1' || *(*(map + i) + j) != '1')
			ft_exit(NULL, NO_WALLS);
		++j;
	}
}

void	rectangular(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(*map);
	i = 1;
	while (*(map + i))
	{
		if (ft_strlen(*(map + i)) != len)
			ft_exit(NULL, NOT_RECTANGULAR);
		++i;
	}
}

char	**clean_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = 0;
			++j;
		}
		++i;
	}
	return (map);
}

int	check_map(t_param *param)
{
	param->map.map = clean_map(param->map.map);
	rectangular(param->map.map);
	closed_walls(param->map.map);
	param->coll = char_contained(param->map.map);
	valid_path(param->map);
	return (1);
}
