/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:15:02 by eulutas           #+#    #+#             */
/*   Updated: 2025/03/30 15:15:02 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void set_zeros(t_game *game)
{
	game->ct_coin = 0;
	game->ct_exit = 0;
	game->ct_player = 0;
	game->ct_move = 0;
	game->px = 0;
	game->py = 0;
	game->ex = 0;
	game->ey = 0;
}
int main(int argc, char **argv)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	set_zeros(game);
	if(argc != 2)
		print_errors(1,game);

	file_check(argv[1], game);
	read_map(game);
	map_check(game);
	game -> mlx = mlx_init();
	game -> mlx_wind = mlx_new_window(game->mlx,
				64 * game->mapx_line, 64 * game->mapy_line, "SO_LONG");
	if (!game->mlx || !game->mlx_wind || create_xpm(game))
		print_errors(8,game);
	put_image(game);
	mlx_hook(game->mlx_wind, 2, 1L, move_player, game);
	mlx_hook(game->mlx_wind, 17, 0, free_all, game);
	mlx_hook(game->mlx_wind, 22, 1L<<17, put_image, game);
	mlx_loop(game->mlx);
	return (0);
}