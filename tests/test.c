/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:04:15 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/02 17:26:41 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Window Creation (ctrl C in terminal to exit)

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Test window");
//     mlx_loop(mlx);
// }

// Trying opening a .xpm file (test)

// int close_window(void)
// {
//     exit(0);
// }

// int main(void)
// {
//     void    *mlx;
//     void    *window;
//     void    *img;
//     int     img_wd;
//     int     img_hg;
//     int    *img_data;

//     mlx = mlx_init();
//     window = mlx_new_window(mlx, 800, 600, "Frame test");
//     img = mlx_xpm_file_to_image(mlx, "src/textures/Wall.xpm", &img_wd, &img_hg);
    
//     mlx_put_image_to_window(mlx, window, img, 0, 0);
//     mlx_hook(window, 17, 0, close_window, NULL);
//     mlx_loop(mlx);
//     return (0);
// }