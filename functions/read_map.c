/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:12:38 by eulutas           #+#    #+#             */
/*   Updated: 2025/03/30 20:12:38 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static int init_height(int fd_map)
{
	int i = 0;
	char *line;

	while ((line = get_next_line(fd_map)) != NULL)
	{
		free(line);
		i++;
	}
	return (i);
}

static void add_map(int fd_map, t_game *game)
{
	int i = 0;
	char *current;

	while (i < game->mapy_line)
	{
		current = get_next_line(fd_map);
		if (!current)
			break;
		game->map[i] = current;
		i++;
	}
	game->map[i] = NULL; 
	close(fd_map);
}

static void n_control(t_game *game)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
			j++;
		if (game->map[i][j] == '\0')
		{
			tmp = game->map[i];
			game->map[i] = ft_strjoin(tmp, "\r\n");
			free(tmp);
		}
		i++;
	}
	j = 0;
	while (game->map[0][j])
		j++;
	game->mapx_line = j - 2;
}

void free_map(t_game *game)
{
	if (!game->map) 
		return;
	int i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
void read_map(t_game *game)
{
	int fd_map;
	fd_map = open(game->f_name, O_RDONLY);
	game->mapy_line = init_height(fd_map);
	close(fd_map);
	game->map = malloc((game->mapy_line + 1) * sizeof(char *));
	fd_map = open(game->f_name, O_RDONLY);
	add_map(fd_map, game);
	n_control(game);
}
