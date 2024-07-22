/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:12:09 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/22 16:07:15 by bbento-a         ###   ########.fr       */
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

// Sprite Paths
# define MC_FRONT "src/textures/front.xpm"
# define MC_LEFT "src/textures/left.xpm"
# define MC_BACK "src/textures/back.xpm"
# define MC_RIGHT "src/textures/right.xpm"

# define WALL "src/textures/wall.xpm"
# define EXIT "src/textures/exit.xpm"
# define FLOOR "src/textures/floor.xpm"
# define COLLECTABLE "src/textures/collectable.xpm"

// Sprite Size
# define SS 64

// Key codes
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define ITW mlx_put_image_to_window
# define XPMTI mlx_xpm_file_to_image

//
//  STRUCTS
//

typedef struct s_im
{
    void    *img;
}   t_im;

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

typedef struct s_mlx_data
{
    void    *mlx;
    void    *window;
}   t_mlx_data;

typedef struct s_sprites
{
    t_im   mc_front;
    t_im   mc_left;
    t_im   mc_back;
    t_im   mc_right;
    t_im   wall;
    t_im   exit;
    t_im   floor;
    t_im   collectable;
}   t_sprites;

typedef struct s_steps
{
    int n;
}   t_steps;

typedef struct s_exit
{
    int x;
    int y;
}   t_exit;

// Main struct

typedef struct s_data
{
    char        **map;
    int         collectables;
    int         got_c;
    
    t_mapsize   mapsize;
    t_steps     steps;
    t_exit      exit;
    t_sprites   spr;
    t_mlx_data  mlx;
    t_player    mc;
}   t_data;


//
//  FUNCTIONS
//

// sl_main.c

t_data  *sl_data(void);

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
int     flood_fill_e(char **map, int ply_x, int ply_y);
int     flood_fill_c(char **map, int ply_x, int ply_y);
void    mapdata_validate(char **map);

// mlx_window.c
void    steps_display(int steps);
void    window_load();
void    mlx_window_start();

// mlx_images.c
void    image_destroy();
void    image_update(int x, int y, int key);
void    image_load();
void    sprite_load(int x, int y);

// mlx_hooks.c
bool    game_collisions(int key);
void    new_move(int key);
int     player_moves(int key);

// exit_utils.c

void    print_error_msg(char *str);
int     exit_game(void);
int     finish_game(void);
void    free_matrix(char **mtx);

// ft_functions.c

bool	ft_rev_strncmp(const char *s1, const char *s2, size_t n);
char    **ft_mtxdup(char **mtx);
void    ft_printmap();

#endif