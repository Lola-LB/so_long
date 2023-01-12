/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/12 16:15:14 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_param *param)
{
	t_img		*images;
	static char	*files[NB_FILES] = {"files/axe.xpm", "files/beer.xpm",
		"files/floor.xpm", "files/lad.xpm", "files/miss.xpm", "files/tos.xpm",
		"files/wall.xpm", "files/miss_left.xpm", "files/win_screen.xpm"};
	int			i;

	images = malloc(sizeof(t_img) * NB_FILES);
	if (!images)
		ft_error(param, MALLOC_ERROR);
	i = 0;
	while (i < NB_FILES)
	{
		images[i].img = mlx_xpm_file_to_image(param->mlx, files[i],
				&images[i].width, &images[i].height);
		if (!images[i].img)
			ft_error(param, FILE_ERROR);
		++i;
	}
	param->img = images;
}

void	*get_img(t_param *param, int i, int j)
{
	if (param->map.map[i][j] == '1')
		return (param->img[6].img);
	else if (param->map.map[i][j] == 'P')
	{
		if (param->left)
			return (param->img[7].img);
		else
			return (param->img[4].img);
	}
	else if (param->map.map[i][j] == 'C')
		return (param->img[1].img);
	else if (param->map.map[i][j] == 'E' && param->coll == 0)
		return (param->img[3].img);
	else
		return (NULL);
}

void	images_to_map(t_param *param)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	mlx_put_image_to_window(param->mlx, param->win, param->img[2].img, 0, 0);
	while (i < param->map.len)
	{
		j = 0;
		while (j < param->map.width)
		{
			img = get_img(param, i, j);
			(void) img;
			if (img)
				mlx_put_image_to_window(param->mlx,
					param->win, img, j * 50, i * 50);
			++j;
		}
		++i;
	}
}
