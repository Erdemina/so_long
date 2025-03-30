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

static int ber_check(char *arg)
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
			print_errors(2);
		i++;
	}
	if (arg[i] != ber[i])
		print_errors(2);
	return 1;
}

void file_check(char *arg, t_game *game)
{
	game->f_name = arg;
	ber_check(game->f_name);
}