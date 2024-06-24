# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 15:37:59 by bbento-a          #+#    #+#              #
#    Updated: 2024/06/24 12:42:33 by bbento-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

# Name of the executable(s)

NAME		= so_long

# Directories

LIBFT		= ./libft/libft.a
INC			= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# Source Files

SOLONG_SRCS = $(SRC_DIR)

# Conversion of files (Linking and applying pattern substituition to all source files)

SRC			= $(SOLONG_SRCS)
OBJ			= $(patsubst $(SRC_DIR).c,$(OBJ_DIR).o, $(SRCS))

# RULES

$(LIBFT)
			make -C ./libft

all: $(NAME)

$(NAME)		$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $()