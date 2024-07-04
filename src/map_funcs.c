/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:14 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/04 14:48:06 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    map_namecheck(char *map_file)
{
    char    *ref;
    
    ref = ".ber";
    if (!ft_rev_strncmp(map_file, ref, 4))
        print_error_msg("Invalid map file");
    if (open(map_file, O_RDONLY) < 0)
        print_error_msg("Failed to open map file");
    printf("Map valid\n");
    return(open(map_file, O_RDONLY));
}
void    map_read(char *map_file)
{
    int fd;

    fd = map_namecheck(map_file);
    
}
char    **map_check(int fd)
{
    char    **map;
    
    
    return (map);
}