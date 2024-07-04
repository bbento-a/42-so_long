/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:10:18 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/02 18:40:23 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
    if (ac != 2)
        print_error_msg("Wrong parameters.\nTry running ./so_long <map_file.ber>");
    map_read(av[1]);
}
t_data  *data(void)
{
    static t_data res;
    
    return (&res);
}