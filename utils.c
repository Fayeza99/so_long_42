/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:28:21 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 13:40:38 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ints(t_point *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free (game->coin_check[i]);
		i++;
	}
	free(game->coin_check);
}

void	free_game(t_point *game)
{
	mlx_delete_image(game->mlx, game->img_p);
	mlx_delete_image(game->mlx, game->img_coin);
	mlx_delete_image(game->mlx, game->img_exit);
	mlx_delete_image(game->mlx, game->img_wall);
	mlx_delete_image(game->mlx, game->img_space);
	mlx_delete_texture(game->texture_p);
	mlx_delete_texture(game->texture_coin);
	mlx_delete_texture(game->texture_wall);
	mlx_delete_texture(game->texture_space);
	mlx_delete_texture(game->texture_exit);
	free_ints(game);
	mlx_terminate(game->mlx);
	ft_free (game->map);
	ft_free (game->valid_map);
}

void	coin_exit(t_point *game)
{
	int	i;

	if (game->map[game->img_p->instances[0].y
			/ 64][game->img_p->instances[0].x / 64] == 'C')
	{
		i = game->coin_check[game->img_p->instances[0].y
			/ 64][game->img_p->instances[0].x / 64];
		if (i >= 0 && game->img_coin->instances[i].enabled)
		{
			game->img_coin->instances[i].enabled = false;
			game->coin_collected++;
		}
	}
	else if (game->map[game->img_p->instances[0].y
			/ 64][game->img_p->instances[0].x / 64] == 'E')
	{
		if (game->coin_collected > 0
			&& game->coin_collected == coin_number(game))
			exit(0);
	}
}
