/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:26:01 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/17 20:15:07 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_len(char *file)
{
	int		len;
	int		fd;
	char	buff;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, FILE_ERROR);
	if (read(fd, &buff, 1) > 0 && buff != '\n')
		++len;
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n' && read(fd, &buff, 1) > 0)
			++len;
	}
	if (close(fd) == -1)
		ft_error(NULL, SYST_ERROR);
	return (len);
}

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp(".ber", file + len - 4) != 0)
		ft_error(NULL, "Map file must end with a .ber extension");
}

void	read_lines(char **map, int fd, int len)
{
	int		i;
	char	*line;

	i = 0;
	while (i < len)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_map(map);
			ft_error(NULL, GNL_ERROR);
		}
		*(map + i) = line;
		++i;
	}
	if (i)
		line = get_next_line(fd);
	*(map + i) = NULL;
}

t_map	parse_map(char *file)
{
	t_map	map;
	int		len;
	int		fd;

	check_extension(file);
	len = map_len(file);
	printf("len %d\n", len);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, FILE_ERROR);
	map.map = malloc(sizeof(char *) * (len + 1));
	if (!map.map)
		ft_error(NULL, MALLOC_ERROR);
	read_lines(map.map, fd, len);
	if (close(fd) == -1)
	{
		free_map(map.map);
		ft_error(NULL, SYST_ERROR);
	}
	map.len = len;
	map.width = ft_strlen(map.map[0]) - 1 * (ft_strlen(map.map[0]) > 0);
	printf("%d %d\n", map.len, map.width);
	return (map);
}
