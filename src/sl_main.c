/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:10:18 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/08 13:00:47 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
    // t_data  data;
    char    **map;
    int     i = 0;
    
    if (ac != 2)
        print_error_msg("Wrong parameters.\nTry running ./so_long <map_file.ber>", NULL);
    map = map_check(av[1]);
    map_count_checker(map);
    while (map[i])
    {
        ft_printf("%s", map[i]);
        free(map[i]);
        i++;
    }
    free(map);
}
t_data  *data(void)
{
    static t_data res;
    
    return (&res);
}