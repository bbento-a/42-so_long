/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:10:18 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/09 20:15:09 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
    int     i = 0;
    
    if (ac != 2)
        print_error_msg("Wrong parameters.\nTry running ./so_long <map_file.ber>");
    sl_data()->map = map_check(av[1]);
    mapdata_validate(sl_data()->map);
    while (sl_data()->map[i])
    {
        ft_printf("%s", sl_data()->map[i]);
        i++;
    }
    free_matrix(sl_data()->map);
}

t_data  *sl_data(void)
{
    static t_data res;
    
    return (&res);
}