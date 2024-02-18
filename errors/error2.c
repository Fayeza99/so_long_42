/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:50:46 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 15:34:32 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	storing_width_height(t_point *map_line)
{
	int	i;

	i = 1;
	while (map_line->map[i])
	{
		i++;
	}
	map_line->map_height = i;
	map_line->map_width = ft_newstrlen(map_line->map[0]);
}

int	check_letter(t_point *game)
{
	game->x = 0;
	while (game->map[game->x])
	{
		game->y = 0;
		while (game->map[game->x][game->y] != 0
			&& game->map[game->x][game->y] != '\n')
		{
			if (game->map[game->x][game->y] != '0'
				&& game->map[game->x][game->y] != '1'
				&& game->map[game->x][game->y] != 'E'
				&& game->map[game->x][game->y] != 'P'
				&& game->map[game->x][game->y] != 'C')
				return (1);
			game->y++;
		}
		game->x++;
	}
	return (0);
}

//p[0] is player
//p[1] is exit
//p[2] is coin
int	valid_map2(t_point *game)
{
	int	p[3];

	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	game->x = 0;
	while (game->map[game->x])
	{
		game->y = 0;
		while (game->map[game->x][game->y])
		{
			if (game->map[game->x][game->y] == 'P')
				p[0]++;
			else if (game->map[game->x][game->y] == 'E')
				p[1]++;
			else if (game->map[game->x][game->y] == 'C')
				p[2]++;
			game->y++;
		}
		game->x++;
	}
	if (p[0] != 1 || p[2] < 1 || p[1] != 1)
		return (1);
	return (0);
}

int	valid_map3(t_point *game)
{
	game->x = 0;
	storing_width_height(game);
	while (game->map[game->x])
	{
		if (game->x == 0 || game->x == game->map_height - 1)
		{
			game->y = 0;
			while (game->map[game->x][game->y]
				&& game->map[game->x][game->y] != '\n')
			{
				if (game->map[game->x][game->y] != '1')
					return (1);
				game->y++;
			}
		}
		else
		{
			if (game->map[game->x][0] != '1'
				|| game->map[game->x][game->map_width - 1] != '1')
				return (1);
		}
		game->x++;
	}
	return (0);
}
