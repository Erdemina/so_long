/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:19:05 by eulutas           #+#    #+#             */
/*   Updated: 2025/03/30 15:19:05 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static void err_tab1(int x)
{
	switch (x)
	{
	case 1:
		ft_printf("Wrong syntax please use: ./so_long <map.ber>\n");
		break;
	case 2:
		ft_printf("That file is not a .ber\n");
		break;
	case 3:
		ft_printf("Some files are not exist\n");
		break;
	case 4:
		ft_printf("Some chars are not for the game?\n");
		break;
	case 5:
		ft_printf("Count of objects are not good for the game\n");
		break;
	case 6:
		ft_printf("Map's shape is not good\n");
		break;
	default:
		break;
	}
}
static void err_tab2(int x)
{
	switch (x)
	{
	case 7:
		ft_printf("How will the player get here?\n");
		break;

	default:
		break;
	}
}

void print_errors(int x, t_game *game)
{
	ft_printf("Error\n");
	if(x > 0 && x < 7)
		err_tab1(x);
	else
		err_tab2(x);
	free_all(game);
	exit(1);
}

void free_all(t_game *game)
{
	free_map(game);
	free(game);
}