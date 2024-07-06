/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:14 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/06 15:00:31 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if the map file name is .ber, and if it exists

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
// Reads the file map line by line, adding each line in a new list

t_list    *map_read(char *map_file)
{
    int     fd;
    char    *line;
    t_list  *map_lst;

    fd = map_namecheck(map_file);
    line = get_next_line(fd);
    if (!line)
        print_error_msg("Map file is empty");
    while (line)
    {
        ft_lstadd_back(&map_lst, ft_lstnew(line));
        line = get_next_line(fd);
    }
    if (line)
        free(line);
    close(fd);
    return (map_lst);
}
// Takes the list containing our map to that we can allocate it in a 2d array
// (we could've also used only one str, and split it by newlines)

char    **map_check(char *map_file)
{
    int     i;
    char    **map;
    t_list  *map_lst;
    
    map_lst = map_read(map_file);
    i = ft_lstsize(map_lst);
    map = malloc(sizeof(char *) * (i + 1));
    if (!map)
        print_error_msg("Map allocation falied while setting it up");
    i = 0;
    while (map_lst)
    {
        map[i++] = map_lst->content;
        map_lst = map_lst->next;
    }
    map[i] = NULL;
    ft_lstclear(&map_lst);
    return (map);
}