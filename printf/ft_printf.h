/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:11:46 by eulutas           #+#    #+#             */
/*   Updated: 2024/12/29 19:12:29 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_checker(va_list *p, char c, int *result);
void	ft_putnbr(int n, int *result);
void	ft_putstr(char *s, int *result);
void	ft_putchar(char c, int *result);
void	ft_putlhex(unsigned int n, int *result);
void	ft_putuhex(unsigned int n, int *result);
void	ft_putptr(unsigned long n, int *result);
void	ft_puthexptr(unsigned long n, int *result);
void	ft_putunsigned(unsigned int n, int *result);
int		ft_printf(const char *s, ...);

#endif
