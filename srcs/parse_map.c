/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:26:01 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/10 18:42:05 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_map(char **map)
// {
// 	while (*map)
// 	{
// 		printf("%s\n", *map);
// 		++map;
// 	}
// }

int	map_len(char *file)
{
	int		len;
	int		fd;
	char	buff;

	len = 0;
	fd = open(file, O_RDONLY);
	if (read(fd, &buff, 1) > 0 && buff != '\n')
		++len;
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n' && read(fd, &buff, 1) > 0)
			++len;
	}
	close(fd);
	return (len);
}

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp(".ber", file + len - 4) != 0)
		ft_exit(NULL, "Map file must end with a .ber extension");
}

t_map	parse_map(char *file)
{
	t_map	map;
	char	*line;
	int		len;
	int		fd;
	int		i;

	len = map_len(file);
	check_extension(file);
	fd = open(file, O_RDONLY);
	map.map = malloc(sizeof(char *) * (len + 1));
	if (!map.map)
		ft_exit(NULL, MALLOC_ERROR);
	line = get_next_line(fd);
	i = 0;
	while (i < len)
	{
		*(map.map + i) = line;
		line = get_next_line(fd);
		++i;
	}
	*(map.map + i) = NULL;
	map.len = len;
	map.width = ft_strlen(map.map[0]) - 1;
	return (map);
}
