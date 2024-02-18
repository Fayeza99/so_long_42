/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:24:01 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/18 15:19:14 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
// # define WIDTH 512
// # define HEIGHT 512

typedef struct s_point
{
	mlx_t			*mlx;
	mlx_texture_t	*texture_p;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_space;
	mlx_texture_t	*texture_coin;
	mlx_texture_t	*texture_exit;
	mlx_image_t		*img_p;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_space;
	mlx_image_t		*img_coin;
	mlx_image_t		*img_exit;
	int32_t			**coin_check;
	int				step;
	unsigned int	coin_collected;
	int				x;
	int				y;
	int				player_loc_x;
	int				player_loc_y;
	char			**map;
	char			**valid_map;
	int				map_height;
	int				map_width;
}					t_point;

//errors
int					ft_newstrlen(char *s);
int					valid_file(char *s);
int					valid_file2(char *s);
int					valid_map(t_point *game);
int					valid_map2(t_point *game);
int					check_letter(t_point *game);
int					valid_map3(t_point *map_line);
void				storing_width_height(t_point *map_line);
char				**flood_fill(t_point *game, int x, int y);
void				storing_player_position(t_point	*game);
void				check_map(t_point *game);
int					check_map1(t_point *game);
void				keyhook(mlx_key_data_t keydata, void *param);
void				keyhook_d(t_point *game);
void				keyhook_s(t_point *game);
void				keyhook_w(t_point *game);
void				keyhook_a(t_point *game);
void				collectables(t_point *game);
unsigned int		coin_number(t_point *game);
void				load_images(t_point *game);
void				map_initialize(t_point *game);
void				map_initialize_1(t_point *game);
void				read_map(char *s, t_point *game);
void				ft_free(char **s);
int					get_height(char *s);
void				coin_exit(t_point *game);
void				all_error(char *s, t_point *game);
void				free_game(t_point *game);
void				free_ints(t_point *game);

#endif