/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:48:29 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/19 12:44:41 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool    game_collisions(int key)
{
    key = key;
    return (true);
}
void    new_move(int key)
{
    image_update(sl_data()->mc.pos_x, sl_data()->mc.pos_y, 0);
    if (key == W)
    {
        sl_data()->mc.pos_y--;
        image_update(sl_data()->mc.pos_x, sl_data()->mc.pos_y, W);
    }
    else if (key == A)
    {
        sl_data()->mc.pos_x--;
        image_update(sl_data()->mc.pos_x, sl_data()->mc.pos_y, A);
    }
    else if (key == S)
    {
        sl_data()->mc.pos_y++;
        image_update(sl_data()->mc.pos_x, sl_data()->mc.pos_y, S);
    }
    else if (key == D)
    {
        sl_data()->mc.pos_x++;
        image_update(sl_data()->mc.pos_x, sl_data()->mc.pos_y, D);
    }
}

int player_moves(int key)
{
    if (key == W && game_collisions(W))
        new_move(W);
    else if (key == A && game_collisions(A))
        new_move(A);
    else if (key == S && game_collisions(S))
        new_move(S);
    else if (key == D && game_collisions(D))
        new_move(D);
    return (0);
}