# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnegura <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 19:57:15 by mnegura           #+#    #+#              #
#    Updated: 2017/04/15 19:57:19 by mnegura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
MLX = -lm -Llibft -lft -lmlx -lXext -lX11
SRC = src/colors.c src/ft_first.c src/help1.c src/help2.c src/julia.c \
	src/key.c src/mandelbrot.c src/marina.c src/next_step.c src/print.c \
	src/printt.c src/theme.c

OBJ = colors.o ft_first.o help1.o help2.o julia.o \
	key.o mandelbrot.o marina.o next_step.o print.o \
	printt.o theme.o

all: $(NAME)

libft/libft.a:
	@make -C libft

minilibx/libmlx.a:
	@make -C libmlx.a

$(NAME):
	@gcc $(FLAGS) $(SRC) -c  $? $(SRC)
	@gcc $(OBJ) libft/libft.a -o $(NAME) $(MLX)

clean:
	@make -C libft/ fclean
	@make -C minilibx/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
