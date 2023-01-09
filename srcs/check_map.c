/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:24:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/09 19:09:17 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_contained(char **map)
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
				ft_exit("Forbidden character in the map (must only contain 0 - 1 - P - C - E)");
			if (exit > 1)
				ft_exit(MULT_EXIT);
			if (start > 1)
				ft_exit(MULT_START);
			++j;
		}
		++i;
	}
	if (!exit)
		ft_exit(NO_EXIT);
	if (!start)
		ft_exit(NO_START);
	if (!collectible)
		ft_exit(NO_COLL);
}

void	expand_path(char **map, int px, int py)
{
	if (map[px][py] != '1' && map[px][py] != 'P')
	{
		map[px][py] = 'P';
		explore_map(map, px, py);
	}
	return ;
}

void	explore_map(char **map, int px, int py)
{
	if (px)
		expand_path(map, px - 1, py);
	if (py)
		expand_path(map, px, py - 1);
	if (map[px][py + 1])
		expand_path(map, px, py + 1);
	if (map[px + 1])
		expand_path(map, px + 1, py);
	return ;
}

void	valid_path(char **map)
{
	int	px;
	int	py;

	px = 0;
	while (map[px + 1] && map[px][py] != 'P')
	{
		++px;
		py = 1;
		while (map[px][py] && map[px][py] != 'P')
			++py;
	}
	explore_map(map, px, py);
	px = 1;
	while (map[px + 1])
	{
		py = 1;
		while (map[px][py + 1])
		{
			if (map[px][py] == 'C' || map[px][py] == 'E')
				ft_exit(NO_VALID_PATH);
			++py;
		}
		++px;
	}
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
			ft_exit(NO_WALLS);
		++i;
	}
	j = 0;
	while (*(*map + j))
	{
		if (*(*map + j) != '1' || *(*(map + i) + j) != '1')
			ft_exit(NO_WALLS);
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
			ft_exit(NOT_RECTANGULAR);
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

int	check_map(char **map)
{
	map = clean_map(map);
	rectangular(map);
	closed_walls(map);
	char_contained(map);
	valid_path(map);
	return (1);
}