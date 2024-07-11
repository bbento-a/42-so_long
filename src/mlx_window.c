/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:53:21 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/11 15:43:16 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    mlx_window_start()
{
    sl_data()->mlx.mlx = mlx_init();
    sl_data()->mlx.window = mlx_new_window(sl_data()->mlx.mlx,
        sl_data()->mapsize.x * SS, sl_data()->mapsize.y * SS, "so_long");
    mlx_loop(sl_data()->mlx.mlx);
}