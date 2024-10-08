/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:32:31 by bbento-a          #+#    #+#             */
/*   Updated: 2024/08/13 20:34:29 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Destroys all sprite images

void	image_destroy(void)
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
// Each time the player moves in different directions, the sprites will
// update according to the direction the player is headed to

void	image_update(int x, int y, int key)
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
// When called, the function will turn the xpm file to an image that
// can be printed on screen

t_im	*image_loader(char *path)
{
	void	*img;
	int		ss;

	img = mlx_xpm_file_to_image(sl_data()->mlx.mlx, path, &ss, &ss);
	return (img);
}
// Loads all sprite images to each corresponding variable

void	image_load(void)
{
	sl_data()->spr.mc_front.img = image_loader(MC_FRONT);
	sl_data()->spr.mc_left.img = image_loader(MC_LEFT);
	sl_data()->spr.mc_back.img = image_loader(MC_BACK);
	sl_data()->spr.mc_right.img = image_loader(MC_RIGHT);
	sl_data()->spr.wall.img = image_loader(WALL);
	sl_data()->spr.exit.img = image_loader(EXIT);
	sl_data()->spr.floor.img = image_loader(FLOOR);
	sl_data()->spr.collectable.img = image_loader(COLLECTABLE);
}
// Here is where the map is read and images are printed in our game window,
// using the mlx function mlx_put_image_to_window()

void	sprite_load(int x, int y)
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
