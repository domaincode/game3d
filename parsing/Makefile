NAME = cub3D
RM	= rm -f
CC	= gcc
FLAGS	= -Wall -Wextra -Werror

SRCS = 	parsing/main.c \
		parsing/parse_map.c \
		parsing/tools_parsing.c \
		parsing/validate_map.c \
		utils/get_next_line_utils.c \
		utils/get_next_line.c \
		utils/utils.c \
		libs/libft/ft_memset.c \
		libs/libft/ft_strcmp.c \
		libs/libft/ft_strncmp.c \
		libs/libft/ft_atoi.c \
		libs/libft/ft_isdigit.c \
		libs/libft/ft_strdup.c \
		libs/libft/ft_strlen.c

OBJ  = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
