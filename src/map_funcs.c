/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:14 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/07 13:45:28 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Takes the list containing our map to that we can allocate it in a 2d array
// (we could've also used only one str, and split it by newlines)

char    **map_check(char *map_file)
{
    t_list  *map_lst;
    char    **map;
    int     i;
    
    map_lst = map_read(map_file);
    i = ft_lstsize(map_lst);
    map = malloc(sizeof(char *) * (i + 1));
    if (!map || map_lst)
        print_error_msg("Map allocation falied while setting it up", NULL);
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
// Checks if the map file name is .ber, and if it exists

int    map_namecheck(char *map_file)
{
    char    *ref;
    
    ref = ".ber";
    if (!ft_rev_strncmp(map_file, ref, 4))
        print_error_msg("Invalid map file", NULL);
    if (open(map_file, O_RDONLY) < 0)
        print_error_msg("Failed to open map file", NULL);
    return(open(map_file, O_RDONLY));
}
// Reads the file map line by line, adding each line in a new list

t_list    *map_read(char *map_file)
{
    t_list  *map_lst;
    char    *line;
    int     fd;

    fd = map_namecheck(map_file);
    line = get_next_line(fd);
    map_lst = 0;
    if (!line)
    {
        print_error_msg("Map file is empty", NULL);
        close(fd);
    }
    while (line)
    {
        ft_lstadd_back(&map_lst, ft_lstnew(line));
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (map_lst);
}