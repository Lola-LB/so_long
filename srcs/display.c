/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/10 19:07:49 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_param *param)
{
	t_img		*images;
	static char	*files[7] = {"files/axe.xpm", "files/beer.xpm", "files/floor.xpm",
		"files/ladder.xpm", "files/missaire.xpm", "files/tos.xpm", "files/wall.xpm"};
	int			i;

	images = malloc(sizeof(t_img) * 7);
	if (!images)
		ft_exit(param, MALLOC_ERROR);
	i = 0;
	while (i < 7)
	{
		images[i].img = mlx_xpm_file_to_image(param->mlx, files[i],
				&images[i].width, &images[i].height);
		if (!images[i].img)
			ft_exit(param, MALLOC_ERROR);
		++i;
	}
	param->img = images;
}

void	*get_img(t_param *param, int i, int j)
{
	if (param->map.map[i][j] == '1')
		return (param->img[6].img);
	else if (param->map.map[i][j] == 'P')
		return (param->img[5].img);
	else if (param->map.map[i][j] == 'C')
		return (param->img[1].img);
	else if (param->map.map[i][j] == 'E')
		return (param->img[3].img);
	else
		return (NULL);
}

void	images_to_map(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (i < param->map.len)
	{
		j = 0;
		while (j < param->map.width)
		{
			mlx_put_image_to_window(param->mlx,
				param->win, get_img(param, i, j), i, j);
			++j;
		}
		++i;
	}
}
