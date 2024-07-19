/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:32:31 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/19 12:39:18 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    image_destroy()
{
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.mc_front.img);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.mc_left.img);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.mc_back.img);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.mc_right.img);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.wall.img);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.exit.img);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.floor.img);
    mlx_destroy_image(sl_data()->mlx.mlx, sl_data()->spr.collectable.img);
}
void    image_update(int x, int y, int key)
{
    if (key == 0)
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
        sl_data()->spr.floor.img, x * SS, y * SS);
    else if (key == W)
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
        sl_data()->spr.mc_back.img, x * SS, y * SS);
    else if (key == A)
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
        sl_data()->spr.mc_left.img, x * SS, y * SS);
    else if (key == S)
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
        sl_data()->spr.mc_front.img, x * SS, y * SS);
    else if (key == D)
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
        sl_data()->spr.mc_right.img, x * SS, y * SS);
}


void  image_load()
{
    int ss;

    sl_data()->spr.mc_front.img = XPMTI(sl_data()->mlx.mlx, MC_FRONT, &ss, &ss);
    sl_data()->spr.mc_left.img = XPMTI(sl_data()->mlx.mlx, MC_LEFT, &ss, &ss);
    sl_data()->spr.mc_back.img = XPMTI(sl_data()->mlx.mlx, MC_BACK, &ss, &ss);
    sl_data()->spr.mc_right.img = XPMTI(sl_data()->mlx.mlx, MC_RIGHT, &ss, &ss);
    sl_data()->spr.wall.img = XPMTI(sl_data()->mlx.mlx, WALL, &ss, &ss);
    sl_data()->spr.exit.img = XPMTI(sl_data()->mlx.mlx, EXIT, &ss, &ss);
    sl_data()->spr.floor.img = XPMTI(sl_data()->mlx.mlx, FLOOR, &ss, &ss);
    sl_data()->spr.collectable.img = XPMTI(sl_data()->mlx.mlx, COLLECTABLE, &ss,
    &ss);
}

void    sprite_load(int x, int y)
{
    if (sl_data()->map[y][x] == '1')
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window, sl_data()->spr.wall.img,
            x * SS, y * SS);
    else if (sl_data()->map[y][x] == '0')
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
            sl_data()->spr.floor.img, x * SS, y * SS);
    else if (sl_data()->map[y][x] == 'C')
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
            sl_data()->spr.collectable.img, x * SS, y * SS);
    else if (sl_data()->map[y][x] == 'E')
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window, sl_data()->spr.exit.img,
            x * SS, y * SS);
    else if (sl_data()->map[y][x] == 'P')
        ITW(sl_data()->mlx.mlx, sl_data()->mlx.window,
            sl_data()->spr.mc_front.img, x * SS, y * SS);
}
