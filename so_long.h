#ifndef SO_LONG_H
#define SO_LONG_H

#include "./minilibx/mlx.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_char
{
	int l_x;
	int l_y;
	int point;
	void *chr_front;
	void *chr_back;
	void *chr_left;
	void *chr_right;
	void *chr_cur;
} t_char;

typedef struct s_map
{
	char **mappin;
	int w;
	int h;
	int cb;
	int gate_x;
	int gate_y;
	int p_cnt;
	int end_cnt;
	int coin_cnt;
} t_map;

typedef struct s_win
{
	t_map *map;
	t_char *chr;
	void *win;
	void *mlx;
	void *img_bg;
	void *block_bg;
	void *c_bg;
	void *end_bg;
	int height;
	int width;
} t_win;



#endif