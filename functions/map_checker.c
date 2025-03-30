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
	while(arg[i] && ber[i])
	{
		if(arg[i] != ber[i])
			print_errors(2);
		i++;
	}
	if (arg[i] != ber[i])
		print_errors(2);
	return 1;
}
void map_check(char **arg)
{
	ber_check(arg[0]);
}