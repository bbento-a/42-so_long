/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:14 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/11 14:51:38 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Takes the list containing our map to that we can allocate it in a 2d array
// (we could've also used only one str, and split it by newlines)

char	**map_check(char *map_file)
{
	t_list	*map_lst;
	t_list	*tmp;
	char	**map;
	int		i;

	map_lst = map_read(map_file);
	tmp = map_lst;
	i = ft_lstsize(tmp);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		print_error_msg("Map allocation falied while setting it up");
	i = 0;
	tmp = map_lst;
	while (tmp)
	{
		map[i++] = tmp->content;
		tmp = tmp->next;
	}
	map[i] = NULL;
	ft_lstclear(&map_lst);
	return (map);
}

// Checks if the map file name is .ber, and if it exists

int	map_namecheck(char *map_file)
{
	char	*ref;
	int		fd;

	ref = ".ber";
	if (!ft_rev_strncmp(map_file, ref, 4))
		print_error_msg("Invalid map file");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		print_error_msg("Failed to open map file");
		close(fd);
	}
	return (fd);
}

// Reads the file map line by line, adding each line in a new list

t_list	*map_read(char *map_file)
{
	t_list	*map_lst;
	char	*line;
	int		fd;

	fd = map_namecheck(map_file);
	line = get_next_line(fd);
	map_lst = 0;
	if (!line)
	{
		print_error_msg("Map file is empty");
		close(fd);
	}
	while (line)
	{
		ft_lstadd_back(&map_lst, ft_lstnew(line));
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map_lst);
}
