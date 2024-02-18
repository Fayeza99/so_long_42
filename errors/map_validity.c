/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:45 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 11:56:15 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	storing_player_position(t_point	*game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->x])
		{
			if (game->map[game->y][game->x] == 'P')
			{
				game->player_loc_y = game->y;
				game->player_loc_x = game->x;
			}
			game->x++;
		}
		game->y++;
	}
}

char	**flood_fill(t_point *game, int x, int y)
{
	if (y < 0 || x < 0 || x >= game->map_width || y >= game->map_height
		|| game->valid_map[y][x] == 'X' || game->valid_map[y][x] == '1')
	{
		return (game->valid_map);
	}
	game->valid_map[y][x] = 'X';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
	return (game->valid_map);
}

void	check_map(t_point *game)
{
	int	k;

	storing_player_position(game);
	game->valid_map = malloc (sizeof(char *) * (game->map_height + 1));
	if (!game->valid_map)
		return ;
	k = 0;
	while (game->map[k])
	{
		game->valid_map[k] = ft_strdup(game->map[k]);
		k++;
	}
	game->valid_map[k] = NULL;
	game->valid_map = flood_fill(game, game->player_loc_y, game->player_loc_x);
}

int	check_map1(t_point *game)
{
	int	i;
	int	j;

	check_map(game);
	i = 0;
	while (game->valid_map[i])
	{
		j = 0;
		while (game->valid_map[i][j])
		{
			if (game->valid_map[i][j] == 'P')
				return (1);
			else if (game->valid_map[i][j] == 'E')
				return (1);
			else if (game->valid_map[i][j] == 'C')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
