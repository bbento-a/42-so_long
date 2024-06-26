/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:20:14 by bbento-a          #+#    #+#             */
/*   Updated: 2024/06/26 17:54:53 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

//get_next_line_bonus.c
char	*get_next_line_bonus(int fd);

//get_next_line_utils_bonus.c
size_t	ft_gnl_strlen(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_gnl_buffer_clean(char *buf);

#endif
