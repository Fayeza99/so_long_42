/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:48:50 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 15:20:56 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_newstrlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	valid_file(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'r' || s[i - 2] != 'e'
		|| s[i - 3] != 'b' || s[i - 4] != '.')
	{
		return (1);
	}
	return (0);
}

int	valid_file2(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	close (fd);
	return (0);
}

int	valid_map(t_point *game)
{
	int	j;

	j = ft_newstrlen(game->map[0]);
	game->x = 0;
	while (game->map[game->x])
	{
		if (ft_newstrlen(game->map[game->x]) != j)
		{
			return (1);
		}
		game->x++;
	}
	return (0);
}

void	all_error(char *s, t_point *game)
{
	if (valid_file(s) != 0 || valid_file2(s) != 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	else if (valid_map(game) != 0 || valid_map3(game) != 0
		|| valid_map2(game) != 0 || check_map1(game) != 0
		|| check_letter(game) != 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}
