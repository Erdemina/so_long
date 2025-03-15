/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:13:21 by eulutas           #+#    #+#             */
/*   Updated: 2024/10/26 18:22:06 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long	i;
	char	*ds;
	char	*sr;

	i = len - 1;
	ds = (char *)dst;
	sr = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (ds < sr)
		return (ft_memcpy(ds, sr, len));
	while (i >= 0)
	{
		ds[i] = sr[i];
		i -= 1;
	}
	return (ds);
}
