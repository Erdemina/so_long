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

int create_xpm(t_game *game)
{
	int x;
	int y;

	y = 64;
	x = 64;
	game->xpm_coin = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm",&x,&y);
	game->xpm_exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",&x,&y);
	game->xpm_floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm",&x,&y);
	game->xpm_hero = mlx_xpm_file_to_image(game->mlx, "img/hero.xpm",&x,&y);
	game->xpm_wall = mlx_xpm_file_to_image(game->mlx,"img/wall.xpm",&x,&y);
	if(!game->xpm_coin || !game->xpm_exit || !game->xpm_floor || !game->xpm_hero || !game->xpm_wall)
		return (1);
	return (0);
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