# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 01:32:23 by gdaphine          #+#    #+#              #
#    Updated: 2021/04/24 09:18:34 by gdaphine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = src/get_next_line.c src/main.c src/ft_cub_pars.c \
		src/ft_isspace.c src/ft_cub_params.c \
		src/ft_cub_params_2.c src/ft_keys.c \
		src/ft_first_image.c src/ft_bitmap_creater.c \
		src/ft_new_position.c src/ft_lists_create.c \
		src/ft_errors.c src/ft_other_functions.c \
		src/ft_draw_screen.c src/ft_draw_screen_2.c \
		src/ft_draw_sprite.c src/ft_draw_screen_3.c \
		src/ft_new_position_2.c src/ft_sorter_sprites.c \
		src/ft_flood_fill.c src/ft_flood_fill_2.c \
		src/ft_post_main.c src/ft_other_functions_2.c \
		src/ft_helper.c
		
HEADER = -I ./src/
LIBFT = libft.a
MLXMMS = libmlx.dylib

LIBFT_DIR = ./libft/
MLXMMS_DIR = ./mlx/minilibx_mms/
DFLAGS = -g -fsanitize=address

OBJ = ${SRC:.c=.o}
LOBJ = ${LIBFT_DIR:.c=.o}

.PHONY: all, clean, fclean, re libft

all: 	libft $(NAME)

$(NAME):	$(OBJ) $(LOBJ)
		make -C ${MLXMMS_DIR}
		cp ${MLXMMS_DIR}${MLXMMS} ./
		${CC} -g -fsanitize=address -I src/ft_cub.h ${OBJ} -L./libft/ -L. -lft libmlx.dylib -framework OpenGL -framework AppKit -o ${NAME}

libft:		
		make -C ${LIBFT_DIR}
.c.o:
	${CC} ${CFLAG} ${HEADER} -c $< -o $@ -O2
debug:
	${CC} ${DFLAGS} ${SRC} libmlx.dylib libft.a -framework OpenGL -framework AppKit -o ${NAME}
clean:
	make clean -C ${MLXMMS_DIR}
	make fclean -C ${LIBFT_DIR}
	rm -f ${OBJ}

fclean:	clean
	rm -f ${MLXMMS}
	rm -f ${NAME}

re:	fclean all
