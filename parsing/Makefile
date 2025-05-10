NAME = cub3D
CC = cc
DFLAGS = -Wall -Werror -Wextra -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -Lminilibx-linux -lmlx -lX11 -lXext -lm
LIBFT_DIR = external_outils/libft
LIBFT = $(LIBFT_DIR)/libft.a

P_SRCS = main.c \
		parsing/parsing/cardinal_directions2.c \
		parsing/parsing/cardinal_directions.c \
		parsing/parsing/player_position.c \
		parsing/parsing/map_dimension.c \
		parsing/parsing/map_parsing.c \
		parsing/parsing/read_map.c \
		parsing/parsing/parsing.c \
		parsing/parsing/rgb_parse.c \
		parsing/parsing/tools.c \
		parsing/parsing/tools2.c \
		${wildcard execution/exec/*.c execution/basic/*.c execution/utils/*.c}\

O_SRCS = external_outils/get_next_line/get_next_line.c \
		 external_outils/get_next_line/get_next_line_utils.c

SRCS = $(P_SRCS) $(O_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC)  $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

push:
	git add .
	git commit -m "cube"
	git push