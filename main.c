/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:08:33 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 14:48:46 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *s)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close (fd);
	return (i);
}

void	read_map(char *s, t_point *game)
{
	int		fd;
	char	*line;
	int		i;

	i = get_height(s);
	fd = open (s, O_RDONLY);
	game->map = malloc(sizeof(char *) * (i + 1));
	if (!game->map)
		return ;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	close (fd);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	main(int argc, char **argv)
{
	t_point	game;

	if (argc != 2)
	{
		ft_putendl_fd("Error1", 2);
		return (1);
	}
	if (argc == 2)
	{
		read_map(argv[1], &game);
		if (!game.map || !game.map[0])
			exit (1);
		storing_width_height(&game);
		all_error(argv[1], &game);
		map_initialize(&game);
		mlx_key_hook(game.mlx, keyhook, &game);
		mlx_loop(game.mlx);
		free_game(&game);
	}
	return (0);
}
