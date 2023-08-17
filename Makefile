# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/08/17 15:46:33 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

SRC = ${SRC_DIR}/fractol.c
SRCS = ${SRC_DIR}/parser.c \
		${SRC_DIR}/renderer.c ${SRC_DIR}/renderer_utils.c ${SRC_DIR}/renderer_funcs.c \
		${SRC_DIR}/window.c ${SRC_DIR}/control.c ${SRC_DIR}/control_utils.c \
		${SRC_DIR}/exit.c
H = ${SRC_DIR}/fractol.h
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft
LIBFT_A = libft/libft.a
MAKE_LIBFT = make -C libft

LIBMLX = libmlx
LIBMLX_A = libmlx/libmlx.a
MAKE_LIBMLX = make -C libmlx

LIBEXT = -Lmlx -lmlx -lX11 -lXext -lm

MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Wextra -Werror -pipe -g3
OBJ_FLAGS = ${CFLAGS} -I$(LIBFT) -I$(LIBMLX) -I$(SRC_DIR)
CC = gcc

all:					${NAME}

${NAME}:				mkdir ${LIBFT} ${LIBMLX} ${OBJ} ${OBJS} $(H)
		${CC} ${CFLAGS} ${OBJ} ${OBJS} ${LIBEXT} -L${LIBMLX} -o $@ $(LIBFT_A) $(LIBMLX_A)

lib_ft:
		$(MAKE_LIBFT)

${LIBFT}:				lib_ft

lib_mlx:
		$(MAKE_LIBMLX)

${LIBMLX}:				lib_mlx

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(LIBFT_A) $(LIBMLX_A) $(H)
		$(CC) $(OBJ_FLAGS) -o $@ -c $<

mem:					$(NAME)
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fractol mandelbrot 100 100

check:
		norminette ${SRC_DIR} ${LIBFT} ${TEST_DIR}

static:					fclean
		csbuild -c make

mkdir:
		@mkdir -p $(OBJ_DIR)

clean:
		$(MAKE_LIBFT) $@
		$(MAKE_LIBMLX) $@
		rm -r ${OBJ_DIR}
		find . -name "*.gch" -delete

fclean:					clean
		$(MAKE_LIBFT) $@
		find . -name "${NAME}" -delete
		find . -name "unit-test" -delete

re:						fclean all

.PHONY:	all clean fclean re
