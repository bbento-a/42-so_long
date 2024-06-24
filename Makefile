# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbento-a <bbento-a@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 15:37:59 by bbento-a          #+#    #+#              #
#    Updated: 2024/06/24 17:12:34 by bbento-a         ###   ########.fr        #
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
CFLAGS		= #-Wall -Wextra -Werror -g
LMLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LMLXLINUX	= -I/usr/include -Imlx_linux
RM			= rm -f

# Source Files

SOLONG_SRCS = $(SRC_DIR)

# Conversion of files (Linking and applying pattern substituition to all source files)

SRC			= $(SOLONG_SRCS)test.c
OBJ			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRC))

#
# RULES
#


all:			$(NAME)

$(LIBFT):		
				make -C ./libft
				
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				mkdir -p $(@D)
				$(CC) $(CFLAGS) $(LMLXLINUX) -c $< -o $@

$(NAME):		$(OBJ) $(LIBFT)
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