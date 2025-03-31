/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:30:56 by eulutas           #+#    #+#             */
/*   Updated: 2025/03/30 16:30:56 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static void update_char(t_game *game ,char c,int y,int x)
{
	if(c == '1' || c == '0')
		return ;
	else if(c == 'C')
		game->ct_coin += 1;
	else if(c == 'E')
		game->ct_exit += 1;
	else if(c == 'P')
	{
		game->ct_player += 1;
		game->py = y;
		game->px = x;
	}
	if(game->ct_player > 1 || game->ct_exit > 1)
		print_errors(5,game);
}
static char **player_movable(char **map,int y,int x)
{
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
	{
		map[y][x + 1] = 'P';
		player_movable(map, y, x + 1);
	}
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
	{
		map[y][x - 1] = 'P';
		player_movable(map, y, x - 1);
	}
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
	{
		map[y + 1][x] = 'P';
		player_movable(map, y + 1, x);
	}
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y-1][x] == 'E')
	{
		map[y - 1][x] = 'P';
		player_movable(map, y - 1, x);
	}

	return map;
}

static void check_reach(char **map,t_game *game)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				print_errors(7,game);
			j++;
		}
		i++;
	}
	
}


static void check_shape(t_game *game)
{
	int i;
	int y;
	int x;

	x = game->mapx_line-1;
	y = game->mapy_line-1;
	i = 0;
	while (game->map[0][i] != '\r' && game->map[y][i] != '\r')
	{
		if(game->map[0][i] != '1' || game->map[y][i] != '1')
			print_errors(6,game);
		i++;
	}
	if (game->map[0][i] != game->map[y][i])
		print_errors(6,game);
	i = 0;
	while (i < y)
	{
		if (game->map[i][0] != '1' || game->map[i][x] != '1')
			print_errors(6,game);
		i++;
	}
}
static void check_chars(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P' 
				&& game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != '\r')
					print_errors(4, game);
			update_char(game,game->map[i][j],i,j);
			
			j++;
		}
		
		i++;
	}
	if(game->ct_player < 1 || game->ct_exit < 1 || game->ct_coin < 1)
		print_errors(5,game);
}
void map_check(t_game *game)
{
	check_shape(game);
	check_chars(game);
	check_reach(player_movable(game->map,game->py,game->px),game);
	free_map(game);
	read_map(game);
}