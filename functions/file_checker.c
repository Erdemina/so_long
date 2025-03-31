/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:43:13 by eulutas           #+#    #+#             */
/*   Updated: 2025/03/30 19:43:13 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int ber_check(char *arg, t_game *game)
{
	int i;
	char *ber;

	ber = ".ber";
	i = 0;

	while (arg[i] != '.' && arg[i])
		i++;
	arg = &arg[i];
	i = 0;
	while (arg[i] && ber[i])
	{
		if (arg[i] != ber[i])
			print_errors(2,game);
		i++;
	}
	if (arg[i] != ber[i])
		print_errors(2,game);
	return (1);
}

static int exist_check(char *path,t_game *game)
{
	int 	fd_file;

	fd_file = open(path,O_RDONLY);
	if (fd_file <= 0)
	{
		close(fd_file);
		print_errors(3,game);
	}
	close(fd_file);
	return (1);
	
}

void file_check(char *arg, t_game *game)
{
	game->f_name = arg;
	ber_check(game -> f_name,game);
	exist_check(game -> f_name,game);
	exist_check("img/coin.xpm",game);
	exist_check("img/exit.xpm",game);
	exist_check("img/floor.xpm",game);
	exist_check("img/hero.xpm",game);
	exist_check("img/wall.xpm",game);
}