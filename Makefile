NAME		= so_long

CC 			= cc

CFLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRC			= main.c check_map.c check_print_map.c close_mlx.c init_map.c init_mlx.c get_next_line.c get_next_line_utils.c

HEAD		= -I sources -I includes -I ft_print -I minilibx-linux

OBJ 		= $(addprefix sources/,$(SRC:.c=.o))

all : $(NAME)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(NAME): $(OBJ)
	make -sC minilibx-linux
	make -sC ft_printf
	$(CC) $(OBJ) ft_printf/libftprintf.a $(MLXFLAGS) -o $(NAME)

clean :
	rm -rf  $(OBJ) 
	make -sC ft_printf clean
	make -sC minilibx-linux clean

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re