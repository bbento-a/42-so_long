/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsize_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:16:15 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/09 15:18:29 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if the map is rectangular

void map_isrectangular(char **map)
{
    struct s_data *m_d;
    int i;
    int j;
    int x;

    i = -1;
    while (map[++i])
    {
        j = 0;
        while (map[i][j])
            j++;
        if (i == 0)
            x = j;
        if (x != j)
            return (print_error_msg("Map must be rectangular", map));
    }
    m_d = get_data();
    m_d->mapsize->x = x;
    m_d->mapsize->y = i;
}

// Checks if the map is closed/surrounded by walls

// void map_closed(char **map, t_data data)
// {

// }

// // Checks if all elements are reachable to the player

// void flood_fill(char **map, t_data data, char element)
// {

// }

void    mapdata_validate(char **map)
{
    
    map_count_checker(map);
    map_isrectangular(map);
}