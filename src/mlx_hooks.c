/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:48:29 by bbento-a          #+#    #+#             */
/*   Updated: 2024/08/13 21:06:25 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks whether or not the player can go through

bool	game_collisions(int key)
{
	int	x;
	int	y;

	x = sl_data()->mc.pos_x;
	y = sl_data()->mc.pos_y;
	if (key == W)
		y -= 1;
	else if (key == A)
		x -= 1;
	else if (key == S)
		y += 1;
	else if (key == D)
		x += 1;
	if (sl_data()->map[y][x] == '1')
		return (false);
	if (sl_data()->map[y][x] == 'E' && sl_data()->collectables != 0)
		return (false);
	return (true);
}
// If the character takes a collectable, this will check if it is, and it
// will remove from the map so if the character walks in the same tile,
// it won't count again

void	move_incollec(void)
{
	int	x;
	int	y;

	x = sl_data()->mc.pos_x;
	y = sl_data()->mc.pos_y;
	if (sl_data()->map[y][x] == 'C')
	{
		sl_data()->collectables--;
		sl_data()->map[y][x] = '0';
	}
}
// This function will update all information about the map and the character
// each time the player presses a movement key (WASD)

void	new_move(int key)
{
	image_update(sl_data()->mc.pos_x, sl_data()->mc.pos_y, 0);
	if (key == W)
		sl_data()->mc.pos_y--;
	else if (key == A)
		sl_data()->mc.pos_x--;
	else if (key == S)
		sl_data()->mc.pos_y++;
	else if (key == D)
		sl_data()->mc.pos_x++;
	if (sl_data()->mc.pos_x == sl_data()->exit.x
		&& sl_data()->mc.pos_y == sl_data()->exit.y)
		finish_game();
	image_update(sl_data()->mc.pos_x, sl_data()->mc.pos_y, key);
	move_incollec();
	sl_data()->steps.n += 1;
	ft_printf("Steps: %d\n", sl_data()->steps.n);
	ITW(sl_data()->mlx.mlx, sl_data()->mlx.window, sl_data()->spr.wall.img,
		0 * SS, 0 * SS);
	ITW(sl_data()->mlx.mlx, sl_data()->mlx.window, sl_data()->spr.wall.img,
		1 * SS, 0 * SS);
	steps_display(sl_data()->steps.n);
}
// Calls collision verification, and only if it's false, it will call the
// movement function according to the key that was pressed by the player

int	player_moves(int key)
{
	if (key == W && game_collisions(W))
		new_move(W);
	else if (key == A && game_collisions(A))
		new_move(A);
	else if (key == S && game_collisions(S))
		new_move(S);
	else if (key == D && game_collisions(D))
		new_move(D);
	else if (key == ESC)
		exit_game();
	return (0);
}
