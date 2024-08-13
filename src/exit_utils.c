/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:00:02 by bbento-a          #+#    #+#             */
/*   Updated: 2024/08/13 20:42:02 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Here we have all functions that inform the user of what happened during or
// after the execution of the code, this may include errors while reading map
// files, was the window closed, or if the player finsihed the game (steps are
// printed in the console in function new_move(), in mlx_hooks.c)
// Memory from the map is also freed here.

void	print_error_msg(char *str)
{
	if (sl_data()->map)
		free_matrix(sl_data()->map);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	exit_game(void)
{
	ft_putstr_fd("Game exited.\n", STDERR_FILENO);
	image_destroy();
	mlx_destroy_window(sl_data()->mlx.mlx, sl_data()->mlx.window);
	mlx_destroy_display(sl_data()->mlx.mlx);
	free(sl_data()->mlx.mlx);
	free_matrix(sl_data()->map);
	exit(EXIT_SUCCESS);
}

int	finish_game(void)
{
	ft_putstr_fd("Game finished!\n", STDERR_FILENO);
	image_destroy();
	mlx_destroy_window(sl_data()->mlx.mlx, sl_data()->mlx.window);
	mlx_destroy_display(sl_data()->mlx.mlx);
	free(sl_data()->mlx.mlx);
	free_matrix(sl_data()->map);
	exit(EXIT_SUCCESS);
}

void	free_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}
