/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:34:22 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 14:18:29 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook_d(t_point *game)
{
	if (game->map[game->img_p->instances[0].y
			/ 64][game->img_p->instances[0].x / 64 + 1] != '1')
	{
		game->img_p->instances[0].x += 64;
		game->step++;
		ft_printf("step %d\n", game->step);
		coin_exit(game);
	}
}

void	keyhook_s(t_point *game)
{
	if (game->map[game->img_p->instances[0].y
			/ 64 + 1][game->img_p->instances[0].x / 64] != '1')
	{
		game->img_p->instances[0].y += 64;
		game->step++;
		ft_printf("step %d\n", game->step);
		coin_exit(game);
	}
}

void	keyhook_w(t_point *game)
{
	if (game->map[game->img_p->instances[0].y
			/ 64 - 1][game->img_p->instances[0].x / 64] != '1')
	{
		game->img_p->instances[0].y -= 64;
		game->step++;
		ft_printf("step %d\n", game->step);
		coin_exit(game);
	}
}

void	keyhook_a(t_point *game)
{
	if (game->map[game->img_p->instances[0].y
			/ 64][game->img_p->instances[0].x / 64 - 1] != '1')
	{
		game->img_p->instances[0].x -= 64;
		game->step++;
		ft_printf("step %d\n", game->step);
		coin_exit(game);
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_point				*game;

	game = (t_point *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit (0);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		keyhook_d(game);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		keyhook_s(game);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		keyhook_w(game);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		keyhook_a(game);
}
