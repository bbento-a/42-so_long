/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:48:29 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/22 10:53:31 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool    game_collisions(int key)
{
    int x;
    int y;
    
    x = sl_data()->mc.pos_x;
    y = sl_data()->mc.pos_y;
    if (key == W && sl_data()->map[y - 1][x] != '1'
        && sl_data()->map[y - 1][x] != 'E')
        return (true);
    if (key == A && sl_data()->map[y][x - 1] != '1'
        && sl_data()->map[y][x - 1] != 'E')
        return (true);
    if (key == S && sl_data()->map[y + 1][x] != '1'
        && sl_data()->map[y + 1][x] != 'E')
        return (true);
    if (key == D && sl_data()->map[y][x + 1] != '1'
        && sl_data()->map[y][x + 1] != 'E')
        return (true);
    return (false);
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
    sl_data()->steps.n += 1;
    ft_printf("Steps: %d\n", sl_data()->steps.n);
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