/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:00:45 by bbento-a          #+#    #+#             */
/*   Updated: 2024/08/09 19:54:03 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_rev_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (j != n)
		return (false);
	if (i < n)
		return (false);
	while (n > 0)
	{
		if (s1[i - n] != s2[j - n])
			return (false);
		n--;
	}
	return (true);
}

char	**ft_mtxdup(char **mtx)
{
	char	**res;
	int		i;

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

void	ft_printmap(void)
{
	int	i;

	i = 0;
	while (sl_data()->map[i])
	{
		ft_printf("%s", sl_data()->map[i]);
		i++;
	}
	free_matrix(sl_data()->map);
}
