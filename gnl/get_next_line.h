/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:50:42 by eulutas           #+#    #+#             */
/*   Updated: 2025/01/19 17:34:11 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strchr(char *str, int c);
int		ft_strlen(char *s);
char	*ft_join(char *s1, char *s2);
char	*get_line_from_buffer(char *buffer);
char	*get_next_line(int fd);
char	*clean_buffer(char *buffer);

#endif
