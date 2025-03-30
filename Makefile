NAME = so_long

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
MLX = ./minilibx/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./minilibx -lmlx -lX11 -lXext -lm

RM = rm -rf

OBJ_DIR = obj/

SRCS = so_long.c \
	getnextline/get_next_line.c \
	getnextline/get_next_line_utils.c \
	functions/error_handle.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./minilibx -I./libft -I./printf -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(PRINTF):
	@$(MAKE) -C ./printf

$(MLX):
	@$(MAKE) -C ./minilibx

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./printf clean
	@$(MAKE) -C ./minilibx clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@$(MAKE) -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re
