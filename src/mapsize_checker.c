/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsize_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:16:15 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/10 18:58:58 by bbento-a         ###   ########.fr       */
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
// Checks if the players can reach the exit

int flood_fill_e(char **map, int ply_x, int ply_y)
{
    static int  count;
    
    if (map[ply_x][ply_y] == 'E')
        count++;
    map[ply_x][ply_y] = 'F';
    if (map[ply_x + 1][ply_y] != '1' && map[ply_x + 1][ply_y] != 'F')
        return (flood_fill_e(map, ply_x + 1, ply_y));
    if (map[ply_x - 1][ply_y] != '1' && map[ply_x - 1][ply_y] != 'F')
        return (flood_fill_e(map, ply_x - 1, ply_y));
    if (map[ply_x][ply_y + 1] != '1' && map[ply_x][ply_y + 1] != 'F')
        return (flood_fill_e(map, ply_x, ply_y + 1));
    if (map[ply_x][ply_y - 1] != '1' && map[ply_x][ply_y - 1] != 'F')
        return (flood_fill_e(map, ply_x, ply_y - 1));
    return (count);
}

// Checks if the player can reach all collectables in the map

int flood_fill_c(char **map, int ply_x, int ply_y)
{
    static int count;

    ft_printf("x: %d ", ply_x);
    ft_printf("y: %d\n", ply_y);
    if (map[ply_x][ply_y] == 'C')
        count++;
    map[ply_x][ply_y] = 'F';
    if (map[ply_x + 1][ply_y] != '1' && map[ply_x + 1][ply_y] != 'F' && map[ply_x + 1][ply_y] != 'E')
        return (flood_fill_c(map, ply_x + 1, ply_y));
    if (map[ply_x - 1][ply_y] != '1' && map[ply_x - 1][ply_y] != 'F' && map[ply_x - 1][ply_y] != 'E')
        return (flood_fill_c(map, ply_x - 1, ply_y));
    if (map[ply_x][ply_y + 1] != '1' && map[ply_x][ply_y + 1] != 'F' && map[ply_x][ply_y + 1] != 'E')
        return (flood_fill_c(map, ply_x, ply_y + 1));
    if (map[ply_x][ply_y - 1] != '1' && map[ply_x][ply_y - 1] != 'F' && map[ply_x][ply_y - 1] != 'E')
        return (flood_fill_c(map, ply_x, ply_y - 1));
    ft_printf("count: %d\n", count);
    return (count);
}

void    mapdata_validate(char **map)
{   
    static int  check_e;
    static int  check_c;
    char        **map_tmp;
    
    map_count_checker(map);
    map_isrectangular(map);
    map_closed(map);
    check_e = 0;
    check_c = 0;
    map_tmp = ft_mtxdup(map);
    check_e = flood_fill_e(map_tmp, sl_data()->mc.pos_x, sl_data()->mc.pos_y);
    if (check_e < 1)
        return (print_error_msg("Invalid path to exit"));
    free_matrix(map_tmp);
    map_tmp = ft_mtxdup(map);
    check_c = flood_fill_c(map_tmp, sl_data()->mc.pos_x, sl_data()->mc.pos_y);
    ft_printf("collectables: %d\n", sl_data()->collectables);
    if (check_c != sl_data()->collectables)
        return (print_error_msg("Invalid path to collectables"));
    free_matrix(map_tmp);
}
