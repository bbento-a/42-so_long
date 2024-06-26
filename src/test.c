/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:04:15 by bbento-a          #+#    #+#             */
/*   Updated: 2024/06/26 17:22:00 by bbento-a         ###   ########.fr       */
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

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void    ft_put_pixel(t_data *data, int x, int y, int color)
// {
//     char *dest;

//     dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dest = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	*img;

// 	mlx = mlx_init();
// 	img->img = mlx_new_image(mlx, 1920, 1080);
//     img->addr = mlx_get_data_addr(img->img, img->bits_per_pixel, &img->line_length, &img->endian);
// }