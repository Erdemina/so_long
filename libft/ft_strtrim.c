/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:40:18 by eulutas           #+#    #+#             */
/*   Updated: 2024/10/27 15:40:18 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;

	if (!s1 || !set)
	{
		return (0);
	}
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	j = ft_strlen(s1);
	while (j && ft_strchr(set, s1[j]))
	{
		j--;
	}
	return (ft_substr(s1, 0, j + 1));
}
