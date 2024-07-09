/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdata_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:54:19 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/09 15:08:46 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if there's only 1 player in the map file

void    map_count_player(char **map)
{
    int     i;
    int     j;
    int     count;

    i = -1;
    count = 0;
    while (map[++i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
                count++;
            j++;
        }
    }
    if (count < 1)
        return (print_error_msg("Map needs at least 1 player", map));
    if (count > 1)
        return (print_error_msg("Map can only contain 1 player", map));
}

// Checks if there are collectables in the map file

void    map_count_collectables(char **map)
{
    int     i;
    int     j;
    bool    found_c;

    i = -1;
    found_c = false;
    while (map[++i] && !found_c)
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'C')
            {
                found_c = true;
                break;
            }
            j++;
        }
    }
    if (!found_c)
        (print_error_msg("Map must contain at least 1 collectable", map));    
}

// Checks if there's only 1 exit in the map file

void    map_count_exit(char **map)
{   
    int     i;
    int     j;
    int     count;

    i = -1;
    count = 0;
    while (map[++i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'E')
                count++;
            j++;
        }
    }
    if (count < 1)
        return (print_error_msg("Map needs at least 1 exit", map));
    if (count > 1)
        return (print_error_msg("Map can only contain 1 exit", map));
}

// Verifies if all elements (characters) in map data are correct and calls more check functions

void    map_count_checker(char **map)
{
    int i;
    int j;

    i = -1;    
    while (map[++i])
    {
        j = -1;
        while(map[i][++j])
        {
            if(!ft_strchr("01CEP\n", map[i][j]))
                return(print_error_msg("Map contains invalid characters", map));
        }
    }
    map_count_player(map);
    map_count_collectables(map);
    map_count_exit(map);
}

