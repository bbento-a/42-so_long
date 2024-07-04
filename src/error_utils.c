/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:00:02 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/02 17:18:50 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_error_msg(char *str)
{
    ft_putstr_fd("Error: ", STDERR_FILENO);
    ft_putstr_fd(str, STDERR_FILENO);
    ft_putchar_fd('\n', STDERR_FILENO);
    exit(EXIT_FAILURE);
}