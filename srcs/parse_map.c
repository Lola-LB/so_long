/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:26:01 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/09 19:02:33 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		++map;
	}
}

int		map_len(char *file)
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
	return(len);
}

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp(".ber", file + len - 4) != 0)
		ft_exit("Error\nThe map must end with a .ber extension\n");
}

char	**parse_map(char *file)
{
	char	**map;
	char	*line;
	int		len;
	int		fd;
	int		i;

	len = map_len(file);
	check_extension(file);
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		ft_exit("Malloc error");
	line = get_next_line(fd);
	i = 0;
	while (i < len)
	{
		*(map + i) = line;
		line = get_next_line(fd);
		++i;
	}
	*(map + i) = NULL;
	return (map);
}
