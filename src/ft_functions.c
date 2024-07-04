/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:00:45 by bbento-a          #+#    #+#             */
/*   Updated: 2024/07/04 14:45:03 by bbento-a         ###   ########.fr       */
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
        i++;
	while (s2[n] == s1[i])
    {
        n--;
		i--;
        if (n == 0)
            break;
        if (s2[n] != s1[i])
            return (false);
    }
	return (true);
}