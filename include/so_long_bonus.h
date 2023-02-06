/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:16:23 by lle-bret          #+#    #+#             */
/*   Updated: 2023/02/06 19:15:06 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

# define ENEMY_SPEED 10000
# define KEY_ATTACK 32 //49
# define ATTACK_SPEED 1000
# define RESTART_GAME 49

/* ************************************************************************** */
/*                                    enemy.c                                 */
/* ************************************************************************** */

int		nb_enemy(t_param *param);
void	init_enemy(t_param *param);
void	move_enemy(t_param *param);
void	check_enemy(t_param *param);

/* ************************************************************************** */
/*                                    attack.c                                */
/* ************************************************************************** */

void	player_attack(t_param *param);
void	display_attack(t_param *param);
void	move_attack(t_param *param);
void	kill_enemy(t_param *param, int x, int y);

#endif