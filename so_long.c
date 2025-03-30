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

int main(int argc, char **argv)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if(argc != 2)
		print_errors(1);

	file_check(argv[1], game);
	init_map(game);
	map_check(game);

	free_all(game);
	return (0);
}