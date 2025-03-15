/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:11:39 by eulutas           #+#    #+#             */
/*   Updated: 2024/12/29 19:11:40 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_checker(va_list *p, char c, int *result)
{
	if (c == 'c')
		ft_putchar(va_arg(*p, int), result);
	if (c == 's')
		ft_putstr(va_arg(*p, char *), result);
	if (c == '%')
		ft_putchar('%', result);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*p, int), result);
	if (c == 'x')
		ft_putlhex(va_arg(*p, unsigned int), result);
	if (c == 'X')
		ft_putuhex(va_arg(*p, unsigned int), result);
	if (c == 'p')
	{
		ft_putptr(va_arg(*p, unsigned long long), result);
	}
	if (c == 'u')
		ft_putunsigned(va_arg(*p, unsigned int), result);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	int		i;
	va_list	p;

	i = 0;
	result = 0;
	va_start(p, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			ft_checker(&p, s[++i], &result);
		else if (s[i] != '%')
			ft_putchar(s[i], &result);
		i++;
	}
	va_end(p);
	return (result);
}
