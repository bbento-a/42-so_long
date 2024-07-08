/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:00:02 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/08 13:03:41 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_error_msg(char *str, char **map)
{
    int i;

    i = -1;
    if (map)
    {
        while (map[++i])
            free(map[i]);
        free(map);
    }
    ft_putstr_fd("Error: ", STDERR_FILENO);
    ft_putstr_fd(str, STDERR_FILENO);
    ft_putchar_fd('\n', STDERR_FILENO);
    exit(EXIT_FAILURE);
}