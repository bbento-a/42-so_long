/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:12:09 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/09 16:47:02 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//
//  LIBRARIES, HEADERS AND MACROS
//

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# define SPRITE_SIZE = 64

//
//  STRUCTS
//

typedef struct s_mapsize
{
    int x;
    int y;
}   t_mapsize;

typedef struct s_player
{
    int pos_x;
    int pos_y;
}   t_player;

typedef struct s_data
{
    char                **map;
    int                 collectables;
    
    t_mapsize    *mapsize;
    t_player     *mc;   
}   t_data;


//
//  FUNCTIONS
//

// sl_main.c

t_data  *get_data(void);

// map_funcs.c

int     map_namecheck(char *map_file);
t_list  *map_read(char *map_file);
char    **map_check(char *map_file);

// mapdata_checker.c

void    map_count_player(char **map);
void    map_count_collectables(char **map);
void    map_count_exit(char **map);
void    map_count_checker(char **map);

// mapsize_checker.c

void    map_isrectangular(char **map);
void    map_closed(char **map);
void    flood_fill(char **map, char element);
void    mapdata_validate(char **map);

// error_utils.c

void    print_error_msg(char *str, char **map);

// ft_functions.c

bool	ft_rev_strncmp(const char *s1, const char *s2, size_t n);

#endif