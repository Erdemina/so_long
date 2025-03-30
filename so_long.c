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
	int i = 0;
	if(argc != 2)
		print_errors(1);
	while (argv[i])
	{
		ft_printf("%s",argv[i]);
		i++;
	}
	
	return (0);
}