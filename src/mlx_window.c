/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:53:21 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/22 16:23:03 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    steps_display(int steps)
{
    char *tmp;
    char *str;

    tmp = ft_itoa(steps);
    str = ft_strjoin("Steps: ", tmp);
    mlx_string_put(sl_data()->mlx.mlx, sl_data()->mlx.window, 14, 26, 5053954, str);
    free(tmp);
    free(str);
}

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
    mlx_string_put(sl_data()->mlx.mlx, sl_data()->mlx.window, 14, 26, 5053954, "Steps: 0");
    mlx_key_hook(sl_data()->mlx.window, player_moves, NULL);
    mlx_hook(sl_data()->mlx.window, 17, 0, exit_game, NULL);
    mlx_loop(sl_data()->mlx.mlx);
}