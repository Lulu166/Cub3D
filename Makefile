# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chsiffre <chsiffre@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 20:11:11 by lucas             #+#    #+#              #
#    Updated: 2023/09/22 15:18:09 by chsiffre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -g3

CC = cc

DIR_SRC = ./src/

DIR_OBJ = ./.obj/

DIR_INC = ./include/

MLX_DIR = ./mlx

LIST_SRC =	main.c \
			init.c \
			ray_casting.c \
			utils.c \
			fill_texture.c \
			fill_map.c \
			parse_rgb.c \
			parse_map.c \
			parse_utils.c \
			window_init.c \
			mini_map.c \
			movement.c \
			pix.c \
			error.c \

LIST_INC = cub3d.h

LIST_OBJ = ${LIST_SRC:.c=.o}

SRC = $(addprefix $(DIR_SRC), $(LIST_SRC))

OBJ = $(addprefix $(DIR_OBJ), $(LIST_OBJ))

INC = $(addprefix $(DIR_INC), $(LIST_INC))

DIR_LIBFT = libft

DIR_MLX = mlx

MLX = mlx.a

LIBFT = libft/libft.a

all : $(NAME)

$(DIR_OBJ) :
	mkdir -p $(DIR_OBJ)

$(LIBFT) : $(DIR_LIBFT)
	$(MAKE) -C $(DIR_LIBFT)

$(DIR_OBJ)%.o : $(DIR_SRC)%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC) -I $(DIR_MLX)

$(NAME) : $(DIR_OBJ) $(OBJ) $(INC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -L $(MLX_DIR) -framework OpenGL -framework AppKit -Lmlx -lmlx -lm

bonus :
	$(MAKE) -C bonus

clean:
	rm -rf $(DIR_OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean re all bonus
