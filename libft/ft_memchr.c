/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:43:33 by eulutas           #+#    #+#             */
/*   Updated: 2024/10/26 18:18:54 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t size)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)ptr;
	while (i < size)
	{
		if (a[i] == (unsigned char)ch)
		{
			return ((char *)ptr + i);
		}
		i++;
	}
	return (NULL);
}
