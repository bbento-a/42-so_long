/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsize_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:16:15 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/10 11:20:38 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if the map is rectangular

void map_isrectangular(char **map)
{
    int     i;
    int     j;
    int     x;

    i = -1;
    while (map[++i])
    {
        j = 0;
        while (map[i][j])
            j++;
        if (i == 0)
            x = j;
        if (x != j)
            return (print_error_msg("Map must be rectangular"));
    }
    sl_data()->mapsize.x = x;
    sl_data()->mapsize.y = i;
}

// Checks if the map is closed/surrounded by walls

void map_closed(char **map)
{
    int     i;
    int     j;
    
    i = 0;
    j = -1;
    while (map[0][++j])
        if (map[0][j] != '1' && map[0][j] != '\n')
            return (print_error_msg("Map must be surrounded by walls"));
    j = -1;
    while (map[sl_data()->mapsize.y - 1][++j])
        if (map[sl_data()->mapsize.y - 1][j] != '1'
        && map[sl_data()->mapsize.y - 1][j] != '\n')
            return (print_error_msg("Map must be surrounded by walls"));
    while (++i < sl_data()->mapsize.y - 1)
    {
        if (map[i][0] != '1')
            return (print_error_msg("Map must be surrounded by walls"));
        if (map[i][sl_data()->mapsize.x - 2] != '1')
            return (print_error_msg("Map must be surrounded by walls"));
    }
}

// Checks if the player can reach all elements in the map

// void flood_fill(char **map, char element, int ply_x, int ply_y)
// {
    
// }

void    mapdata_validate(char **map)
{   
    char **map_tmp;
    
    map_tmp = ft_mtxdup(map);
    map_count_checker(map);
    map_isrectangular(map);
    map_closed(map);
    
    // flood_fill(map, 'E', sl_data()->mc.pos_x, sl_data()->mc.pos_y);
    // flood_fill(map, 'C', sl_data()->mc.pos_x, sl_data()->mc.pos_y);
}