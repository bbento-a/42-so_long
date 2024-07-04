/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:12:09 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/04 14:51:51 by bbento-a         ###   ########.fr       */
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
    char **map;
}   t_data;

//
//  FUNCTIONS
//

// sl_main.c

t_data  *data(void);

// map_funcs.c

int     map_namecheck(char *map_file);
void    map_read(char *map_file);
char    **map_check(int fd);

// errorutils.c

void    print_error_msg(char *str);

// ft_functions.c

bool	ft_rev_strncmp(const char *s1, const char *s2, size_t n);

#endif