/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:53:21 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/12 15:11:39 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Reads tile by tile of the map, and loads each corresponding sprite in the game window

void    window_load()
{
    int i;
    int j;

    i = -1;
    image_load();
    while (sl_data()->map[++i])
    {
        j = -1;
        while (sl_data()->map[i][++j])
            sprite_load(i, j);
    }
}

// This is the function that initiates all mlx stuff

void    mlx_window_start()
{
    sl_data()->mlx.mlx = mlx_init();
    sl_data()->mlx.window = mlx_new_window(sl_data()->mlx.mlx,
        sl_data()->mapsize.x * SS, sl_data()->mapsize.y * SS, "so_long");
    window_load();
    mlx_key_hook(sl_data()->mlx.mlx, hooks, NULL);
    mlx_hook(sl_data()->mlx.mlx, 17, 0, exit_game, NULL);
    mlx_loop(sl_data()->mlx.mlx);
}