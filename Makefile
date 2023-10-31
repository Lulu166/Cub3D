# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 20:11:11 by lucas             #+#    #+#              #
#    Updated: 2023/10/31 16:35:03 by luhumber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- Variables ---- #

NAME			=	cub3D

R_BONUS			= 	no

RMF				=	rm -rf

# ---- Libraries ---- #

DIR_LIB			=	libft/

LIB				=	$(DIR_LIB)libft.a

DIR_MLX			= 	minilibx-linux/

# ---- Directories  mandatory ---- #

DIR_HEADERS		=	mandatory/headers/

HEADERS			= 	$(DIR_HEADERS)cub3D.h \
					$(DIR_LIB)libft.h
				
DIR_MANDATORY	=	mandatory/sources/

MANDATORY		=	$(DIR_MANDATORY)main.c \
					$(DIR_MANDATORY)file.c \
					$(DIR_MANDATORY)init.c \
					$(DIR_MANDATORY)utils.c \
					$(DIR_MANDATORY)utils1.c \
					$(DIR_MANDATORY)fill_texture.c \
					$(DIR_MANDATORY)fill_map.c \
					$(DIR_MANDATORY)parse_rgb.c \
					$(DIR_MANDATORY)parse_map.c \
					$(DIR_MANDATORY)parse_utils.c \
					$(DIR_MANDATORY)window_init.c \
					$(DIR_MANDATORY)mini_map.c \
					$(DIR_MANDATORY)hooks.c \
					$(DIR_MANDATORY)mouse.c \
					$(DIR_MANDATORY)movement.c \
					$(DIR_MANDATORY)pixel_put.c \
					$(DIR_MANDATORY)texture_pix.c \
					$(DIR_MANDATORY)draw3D.c \
					$(DIR_MANDATORY)check_horizontal.c \
					$(DIR_MANDATORY)check_vertical.c \
					$(DIR_MANDATORY)error.c \
					$(DIR_MANDATORY)player.c \
					$(DIR_MANDATORY)end.c \

# ---- Directories  bonus ---- #

DIR_H_BONUS		=	bonus/headers/

H_BONUS			= 	$(DIR_H_BONUS)cub3D.h \
					$(DIR_LIB)libft.h

DIR_BONUS		=	bonus/sources/

BONUS			=	$(DIR_BONUS)main.c \
					$(DIR_BONUS)file.c \
					$(DIR_BONUS)init.c \
					$(DIR_BONUS)utils.c \
					$(DIR_BONUS)utils1.c \
					$(DIR_BONUS)fill_texture.c \
					$(DIR_BONUS)fill_map.c \
					$(DIR_BONUS)parse_rgb.c \
					$(DIR_BONUS)parse_map.c \
					$(DIR_BONUS)parse_utils.c \
					$(DIR_BONUS)window_init.c \
					$(DIR_BONUS)mini_map.c \
					$(DIR_BONUS)hooks.c \
					$(DIR_BONUS)mouse.c \
					$(DIR_BONUS)movement.c \
					$(DIR_BONUS)pixel_put.c \
					$(DIR_BONUS)texture_pix.c \
					$(DIR_BONUS)draw3D.c \
					$(DIR_BONUS)check_horizontal.c \
					$(DIR_BONUS)check_vertical.c \
					$(DIR_BONUS)error.c \
					$(DIR_BONUS)player.c \
					$(DIR_BONUS)end.c \
					
DIR_OBJS	    =	.objs/

# ---- Flags ---- #

ifeq ($(R_BONUS), no)
CFLAGS		=	-Wall -Wextra -Werror -O3  -Wno-deprecated-declarations -g3 -I $(DIR_LIB) -I $(DIR_MLX) -I $(DIR_HEADERS)
else
CFLAGS		=	-Wall -Wextra -Werror -O3  -Wno-deprecated-declarations -g3 -I $(DIR_LIB) -I $(DIR_MLX) -I $(DIR_H_BONUS)
endif
# ---- MLX ---- #

MLX_FLAGS		=	-L$(DIR_MLX) -lm

MLX_FLAGS 	+= -lmlx -lX11 -lXext -L$(DIR_MLX)

# ---- Directory  objs ---- #

ifeq ($(R_BONUS), no)
OBJS		=	$(addprefix $(DIR_OBJS),$(MANDATORY:.c=.o))
else
OBJS		=	$(addprefix $(DIR_OBJS),$(BONUS:.c=.o))
endif

# ====================== RULES ====================== #

# ---- Compilation rules ---- #

all:		
			${MAKE} lib
			${MAKE} ${NAME}

${NAME}:	$(LIB) ${OBJS}
			make -C $(DIR_MLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_FLAGS) -o $(NAME)

ifeq ($(R_BONUS), no)
$(DIR_OBJS)%.o: %.c	$(HEADERS)
			@ mkdir -p ${dir $@}
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)
else
$(DIR_OBJS)%.o: %.c	$(H_BONUS)
			@ mkdir -p ${dir $@}
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_H_BONUS)
endif

# ---- Library rule ---- #

$(LIB) :
			$(MAKE) -C $(DIR_LIB)
						
bonus:
			$(MAKE) R_BONUS=yes

# ---- Clean rules ---- #

clean:
			$(MAKE) -C $(DIR_LIB) clean
			$(RMF) $(DIR_OBJS)

fclean:		clean
			$(MAKE) -C $(DIR_LIB) fclean
			$(RMF)  $(NAME)
			
re :		fclean 
			$(MAKE) all

.PHONY :	all lib clean fclean  bonus re