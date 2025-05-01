NAME = cub3D
RM	= rm -f
CC	= gcc
#FLAGS	= -Wall -Wextra -Werror
FLAGS =  -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRCS = 	main.c \
		parsing/parsing/parse_map.c \
		parsing/parsing/tools_parsing.c \
		parsing/parsing/validate_map.c \
		parsing/utils/get_next_line_utils.c \
		parsing/utils/get_next_line.c \
		parsing/utils/utils.c \
		parsing/libs/libft/ft_memset.c \
		parsing/libs/libft/ft_strcmp.c \
		parsing/libs/libft/ft_strncmp.c \
		parsing/libs/libft/ft_atoi.c \
		parsing/libs/libft/ft_isdigit.c \
		parsing/libs/libft/ft_strdup.c \
		parsing/libs/libft/ft_strlen.c \
		${wildcard execution/*.c execution/basic/*.c execution/utils/*.c}\



OBJ  = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $<  $(FLAGS) -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
