/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:32:31 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/12 18:03:00 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    image_destroy()
{
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.mc_front);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.mc_left);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.mc_back);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.mc_right);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.wall);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.exit);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.floor);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->sprite.collectable);
}
void  image_load()
{
    int ss;

    ss = SS;
    sl_data()->sprite.mc_front = xpmti(sl_data()->mlx.mlx, MC_FRONT, &ss, &ss);
    sl_data()->sprite.mc_left = xpmti(sl_data()->mlx.mlx, MC_LEFT, &ss, &ss);
    sl_data()->sprite.mc_back = xpmti(sl_data()->mlx.mlx, MC_BACK, &ss, &ss);
    sl_data()->sprite.mc_right = xpmti(sl_data()->mlx.mlx, MC_RIGHT, &ss, &ss);
    sl_data()->sprite.wall = xpmti(sl_data()->mlx.mlx, WALL, &ss, &ss);
    sl_data()->sprite.exit = xpmti(sl_data()->mlx.mlx, EXIT, &ss, &ss);
    sl_data()->sprite.floor = xpmti(sl_data()->mlx.mlx, FLOOR, &ss, &ss);
    sl_data()->sprite.collectable = xpmti(sl_data()->mlx.mlx, COLLECTABLE,
    &ss, &ss);
}

void    sprite_load(int y, int x)
{
    if (sl_data()->map[x][y] == '1')
        itw(sl_data()->mlx.mlx, sl_data()->mlx.window, sl_data()->sprite.wall,
            x * SS, y * SS);
    else if (sl_data()->map[x][y] == '0')
        itw(sl_data()->mlx.mlx, sl_data()->mlx.window, sl_data()->sprite.floor,
            x * SS, y * SS);
    else if (sl_data()->map[x][y] == 'C')
        itw(sl_data()->mlx.mlx, sl_data()->mlx.window,
            sl_data()->sprite.collectable, x * SS, y * SS);
    else if (sl_data()->map[x][y] == 'E')
        itw(sl_data()->mlx.mlx, sl_data()->mlx.window, sl_data()->sprite.exit,
            x * SS, y * SS);
    else if (sl_data()->map[x][y] == 'P')
        itw(sl_data()->mlx.mlx, sl_data()->mlx.window,
            sl_data()->sprite.mc_front, x * SS, y * SS);
}
