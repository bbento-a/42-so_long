/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:12:09 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/08 13:12:29 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//
//  LIBRARIES AND HEADERS
//

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

//
//  STRUCTS
//

typedef struct s_data
{
    char        **map;
    // t_mapcont   content;    
}   t_data;

// typedef struct s_mapcont
// {
//     int collectables;
//     int player;
//     int exit;
// }   t_mapcont;

//
//  FUNCTIONS
//

// sl_main.c

t_data  *data(void);

// map_funcs.c

int     map_namecheck(char *map_file);
t_list  *map_read(char *map_file);
char    **map_check(char *map_file);

// mapdata_checker.c

void    map_count_player(char **map);
void    map_count_collectables(char **map);
void    map_count_exit(char **map);
void    map_count_checker(char **map);

// error_utils.c

void    print_error_msg(char *str, char **map);

// ft_functions.c

bool	ft_rev_strncmp(const char *s1, const char *s2, size_t n);

#endif