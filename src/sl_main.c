/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:10:18 by bbento-a          #+#    #+#             */
/*   Updated: 2024/08/13 20:17:38 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// The main function of the program

int	main(int ac, char **av)
{
	if (ac != 2)
		print_error_msg("Wrong parameters.\nTry ./so_long <map_file.ber>");
	sl_data()->map = map_check(av[1]);
	mapdata_validate(sl_data()->map);
	mlx_window_start();
}
// This function is where I store all information related to the project.
// Basically, by calling this function, we can edit each variable inside of
// the structure "res" since we're returning its address, and since it is
// static, it will keep its value.

t_data	*sl_data(void)
{
	static t_data	res;

	return (&res);
}
