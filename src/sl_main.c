/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:10:18 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/11 15:45:17 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
    if (ac != 2)
        print_error_msg("Wrong parameters.\nTry running ./so_long <map_file.ber>");
    sl_data()->map = map_check(av[1]);
    mapdata_validate(sl_data()->map);
    mlx_window_start();
    ft_printmap();
}

t_data  *sl_data(void)
{
    static t_data res;
    
    return (&res);
}