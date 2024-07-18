/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:53:21 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/18 16:49:40 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Reads tile by tile of the map, and loads each corresponding sprite in the game window

void    window_load()
{
    int x;
    int y;

    y = 0;
    while (sl_data()->map[y])
    {
        x = 0;
        while (sl_data()->map[y][x])
        {
            sprite_load(x, y);
            x++;
        }
        y++;
    }
}

// This is the function that initiates all mlx stuff

void    mlx_window_start()
{
    sl_data()->mlx.mlx = mlx_init();
    sl_data()->mapsize.x--;
    sl_data()->mlx.window = mlx_new_window(sl_data()->mlx.mlx,
        sl_data()->mapsize.x * SS, sl_data()->mapsize.y * SS, "so_long");
    image_load();
    window_load();
    // mlx_key_hook(sl_data()->mlx.mlx, hooks, NULL);
    mlx_hook(sl_data()->mlx.mlx, 17, 0, exit_game, NULL);
    mlx_loop(sl_data()->mlx.mlx);
}