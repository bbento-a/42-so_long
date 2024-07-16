/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:00:45 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/16 15:23:16 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_rev_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;

	if (n == 0)
		return (false);
    while (s1[i])
    {
        i++;
    }
	while (n > 0)
    {
        if (s2[n] != s1[i])
            return (false);
        n--;
		i--;
    }
	return (true);
}

char    **ft_mtxdup(char **mtx)
{
    char    **res;
    int     i;
    
    i = 0;
    while (mtx[i])
        i++;
    res = malloc((sizeof(char *)) * (i + 1));
    res[i] = NULL;
    i = -1;
    while (mtx[++i])
        res[i] = ft_strdup(mtx[i]);
    return (res);
}

void    ft_printmap()
{
    int i;
    
    i = 0;
    while (sl_data()->map[i])
    {
        ft_printf("%s", sl_data()->map[i]);
        i++;
    }
    free_matrix(sl_data()->map);
}