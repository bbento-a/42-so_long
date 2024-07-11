# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 15:37:59 by bbento-a          #+#    #+#              #
#    Updated: 2024/07/11 15:51:28 by bbento-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# VARIABLES
#

# Name of the executable(s)

NAME		= so_long

# Directories

LIBFT		= ./libft/libft.a
SRC_DIR		= src/
OBJ_DIR		= obj/

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
LMLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LMLXLINUX	= -I/usr/include -Imlx_linux
RM			= rm -f

# Source Files

SOLONG_SRCS =	$(SRC_DIR)

# Conversion of files (Linking and applying pattern substituition to all source files)

SRC			=	$(SOLONG_SRCS)sl_main.c\
				$(SOLONG_SRCS)error_utils.c\
				$(SOLONG_SRCS)map_funcs.c\
				$(SOLONG_SRCS)ft_functions.c\
				$(SOLONG_SRCS)mapdata_checker.c\
				$(SOLONG_SRCS)mapsize_checker.c\
				$(SOLONG_SRCS)mlx_window.c\
				$(SOLONG_SRCS)mlx_hooks.c
				
OBJ			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRC))

#
# RULES
#


all:			$(NAME)

$(LIBFT):		
				make -C ./libft
				make bonus -C ./libft
				
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				mkdir -p $(@D)
				$(CC) $(CFLAGS) $(LMLXLINUX) -c $< -o $@

$(NAME):		$(OBJ) $(LIBFT)
				cd mlx_linux && ./configure
				$(CC) $(CFLAGS) $(OBJ) $(LMLXFLAGS) $(LIBFT) -o $(NAME)


clean:			
				$(RM) -r $(OBJ_DIR)
				make clean -C ./libft
				
fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)

re:				fclean all

# Phony (It helps avoid conflicts between files named the same)
.PHONY: 		all clean fclean re