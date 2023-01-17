/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:16:23 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/14 19:45:39 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H_BONUS
# define SO_LONG_H_BONUS

# include "so_long.h"

# define ENEMY_SPEED 1000000

/* ************************************************************************** */
/*                                    enemy.c                                 */
/* ************************************************************************** */

int		nb_enemy(t_param *param);
void	init_enemy(t_param *param);
void	move_enemy(t_param *param);
void	check_enemy(t_param *param);

#endif