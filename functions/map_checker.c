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
static void update_char(t_game *game ,char c)
{
	if(c == '1' || c == '0')
		return ;
	else if(c == 'C')
		game->ct_coin += 1;
	else if(c == 'E')
		game->ct_exit += 1;
	else if(c == 'P')
		game->ct_player += 1;
	if(game->ct_player > 1 || game->ct_exit > 1)
		print_errors(5);
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
				print_errors(4);
			update_char(game,game->map[i][j]);
			
			j++;
		}
		
		i++;
	}
	if(game->ct_player < 1 || game->ct_exit < 1 || game->ct_coin < 1)
	{
		print_errors(5);
	}
}
void map_check(t_game *game)
{
	check_chars(game);
}