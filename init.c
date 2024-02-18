/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:44:35 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 14:43:12 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned	int	coin_number(t_point *game)
{
	unsigned int	i;

	i = 0;
	game->x = 0;
	while (game->map[game->x])
	{
		game->y = 0;
		while (game->map[game->x][game->y])
		{
			if (game->map[game->x][game->y] == 'C')
				i++;
			game->y++;
		}
		game->x++;
	}
	return (i);
}

void	collectables(t_point *game)
{
	game->x = 0;
	game->coin_collected = 0;
	game->step = 0;
	game->coin_check = malloc(sizeof(int32_t *) * (game->map_height + 1));
	while (game->x < game->map_height)
	{
		game->coin_check[game->x] = \
			malloc (sizeof(int32_t) * (game->map_width));
		game->y = 0;
		while (game->y < game->map_width)
		{
			game->coin_check[game->x][game->y] = -1;
			game->y++;
		}
		game->x++;
	}
	game->coin_check[game->x] = NULL;
}

void	load_images(t_point *game)
{
	game->mlx = mlx_init(game->map_width * 64,
			game->map_height * 64, "SO_LONG", false);
	game->texture_p = mlx_load_png("images/player.png");
	game->img_p = mlx_texture_to_image(game->mlx, game->texture_p);
	game->texture_wall = mlx_load_png("images/wall.png");
	game->img_wall = mlx_texture_to_image(game->mlx, game->texture_wall);
	game->texture_space = mlx_load_png("images/space.png");
	game->img_space = mlx_texture_to_image(game->mlx, game->texture_space);
	game->texture_coin = mlx_load_png("images/candy.png");
	game->img_coin = mlx_texture_to_image(game->mlx, game->texture_coin);
	game->texture_exit = mlx_load_png("images/exit.png");
	game->img_exit = mlx_texture_to_image(game->mlx, game->texture_exit);
}

void	map_initialize_1(t_point *game)
{
	game->map_height = 0;
	while (game->map[game->map_height])
	{
		game->map_width = 0;
		while (game->map[game->map_height][game->map_width])
		{
			if (game->map[game->map_height][game->map_width] == 'E')
				mlx_image_to_window(game->mlx, game->img_exit,
					game->map_width * 64, game->map_height * 64);
			else if (game->map[game->map_height][game->map_width] == 'C')
			{
				game->coin_check[game->map_height][game->map_width] = \
					mlx_image_to_window(game->mlx, game->img_coin, \
						game->map_width * 64, game->map_height * 64);
			}
			game->map_width++;
		}
		game->map_height++;
	}
}

void	map_initialize(t_point *game)
{
	load_images(game);
	collectables(game);
	game->map_height = 0;
	while (game->map[game->map_height])
	{
		game->map_width = 0;
		while (game->map[game->map_height][game->map_width])
		{
			if (game->map[game->map_height][game->map_width] == '1')
				mlx_image_to_window(game->mlx, game->img_wall,
					game->map_width * 64, game->map_height * 64);
			else
				mlx_image_to_window(game->mlx, game->img_space,
					game->map_width * 64, game->map_height * 64);
			game->map_width++;
		}
		game->map_height++;
	}
	map_initialize_1(game);
	mlx_image_to_window(game->mlx, game->img_p,
		game->player_loc_x * 64, game->player_loc_y * 64);
}
