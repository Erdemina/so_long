#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./getnextline/get_next_line.h"
#include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


typedef struct s_game
{
	void	*mlx;
	void	*mlx_wind;
	void	*xpm_coin;
	void	*xpm_exit;
	void	*xpm_floor;
	void	*xpm_hero;
	void	*xpm_wall;
	char	*f_name;
	char	**map;
	int		mapx_line; 
	int		mapy_line;
	int		ct_exit;
	int		ct_player;
	int		ct_coin;
	int		ct_move;
	int		px;
	int		py;
}	t_game;

void map_check(t_game *game);
void file_check(char *arg, t_game *game);
void print_errors(int x,t_game *game);
void read_map(t_game *game);
void free_map(t_game *game);
int free_all(t_game *game);
int create_xpm(t_game *game);
void put_image(t_game *game);
#endif