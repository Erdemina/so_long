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