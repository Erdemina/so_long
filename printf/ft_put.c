/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:11:51 by eulutas           #+#    #+#             */
/*   Updated: 2024/12/29 19:12:46 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

void	ft_putstr(char *s, int *result)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", result);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], result);
		i++;
	}
}

void	ft_putnbr(int n, int *result)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", result);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', result);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, result);
		ft_putnbr(n % 10, result);
	}
	if (n < 10)
		ft_putchar(n + 48, result);
}

void	ft_putunsigned(unsigned int n, int *result)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, result);
		ft_putnbr(n % 10, result);
	}
	if (n < 10)
		ft_putchar(n + 48, result);
}

void	ft_putlhex(unsigned int n, int *result)
{
	char	*a;

	a = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putlhex(n / 16, result);
		ft_putlhex(n % 16, result);
	}
	else
	{
		ft_putchar(a[n], result);
	}
}
