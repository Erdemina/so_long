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

void print_errors(int x)
{
	switch (x)
	{
	case 1:
		ft_printf("Error\n");
		ft_printf("Wrong syntax please use: ./so_long <map.ber>\n");
		break;
	
	default:
		break;
	}
	exit(1);
}