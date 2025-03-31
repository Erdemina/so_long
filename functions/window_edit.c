/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:21:05 by eulutas           #+#    #+#             */
/*   Updated: 2025/03/31 13:21:05 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static void put_image_extra(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_wind, img, 64 * x, 64 * y);
}

static void map_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->ct_coin == 0)
	{
		ft_printf("Move Count: %d\n", ++game->ct_move);
		free_all(game);
	}
	else if (game->map[y][x] != '1')
	{
		ft_printf("Move Count: %d\n", ++game->ct_move);
		if (game->map[y][x] == 'C')
			game->ct_coin--;

		if (game->py == game->ey && game->px == game->ex)
			game->map[game->py][game->px] = 'E';
		else
			game->map[game->py][game->px] = '0';
		game->map[y][x] = 'P';
		game->py = y;
		game->px = x;
	}
}
int move_player(int key, t_game *game)
{
	int x = game->px;
	int y = game->py;

	if (key == 119) // W
		y--;
	else if (key == 115) // S
		y++;
	else if (key == 100) // D
		x++;
	else if (key == 97) // A
		x--;
	else if (key == 65307)
		free_all(game);
	else
		return (0);
	map_move(game, x, y);
	put_image(game);
	return (0);
}
void put_image(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'E')
				put_image_extra(game, game->xpm_exit, j, i);
			if (game->map[i][j] == 'C')
				put_image_extra(game, game->xpm_coin, j, i);
			if (game->map[i][j] == 'P')
				put_image_extra(game, game->xpm_hero, j, i);
			if (game->map[i][j] == '0')
				put_image_extra(game, game->xpm_floor, j, i);
			if (game->map[i][j] == '1')
				put_image_extra(game, game->xpm_wall, j, i);
			j++;
		}
		i++;
	}
}