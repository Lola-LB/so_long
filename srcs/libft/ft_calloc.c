/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:19:48 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/09 16:39:19 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(int size)
{
	char	*buf;
	int		i;

	buf = malloc(size);
	if (!buf)
		return (buf);
	i = 0;
	while (i < size)
		*(buf + i++) = 0;
	return (buf);
}
