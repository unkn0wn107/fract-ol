# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/07/09 21:56:05 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

SRC = ${SRC_DIR}/fractol.c
SRCS = ${SRC_DIR}/stack_adapter.c ${SRC_DIR}/stack_utils.c ${SRC_DIR}/stack_utils2.c \
	${SRC_DIR}/stack_swap_push.c ${SRC_DIR}/stack_rotate.c \
	${SRC_DIR}/solver.c ${SRC_DIR}/solver_algos.c \
	${SRC_DIR}/parser.c ${SRC_DIR}/error.c ${SRC_DIR}/utils.c
H = ${SRC_DIR}/fractol.h
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_TEST = ${TEST_DIR}/main.test.c ${TEST_DIR}/stack_ops.test.c
H_TEST = ${TEST_DIR}/test.h
OBJ_TEST = $(SRC_TEST:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft
LIBFT_A = libft/libft.a
MAKE_LIBFT = make -C libft

LIBMLX = libmlx
LIBMLX_A = libmlx/libmlx.a
MAKE_LIBMLX = make -C libmlx

MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Wextra -Werror -pipe
OBJ_FLAGS = ${CFLAGS} -I$(LIBFT) -I$(LIBMLX) -I$(SRC_DIR)
CC = gcc

all:					${NAME}

${NAME}:				mkdir ${LIBFT} ${LIBMLX} ${OBJ} ${OBJS} $(H)
		${CC} ${CFLAGS} ${OBJ} ${OBJS} -o $@ $(LIBFT_A) $(LIBMLX_A)

lib_ft:
		$(MAKE_LIBFT)

${LIBFT}:				lib_ft

lib_mlx:
		$(MAKE_LIBMLX)

${LIBMLX}:				lib_mlx

$(OBJ_DIR)/%.test.o:	$(TEST_DIR)/%.test.c mkdir $(LIBFT_A) $(LIBMLX_A) $(H) $(H_TEST)
		$(CC) $(OBJ_FLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c mkdir $(LIBFT_A) $(LIBMLX_A) $(H)
		$(CC) $(OBJ_FLAGS) -o $@ -c $<

unit-test:				${LIBFT} ${LIBMLX} ${OBJ_TEST} ${OBJS} $(H) $(H_TEST)
		${CC} ${CFLAGS} -g3 ${OBJ_TEST} ${OBJS} -o $@ $(LIBFT_A) $(LIBMLX_A)

test:					unit-test
		./unit-test

test-mem:				unit-test
		valgrind --leak-check=full --show-leak-kinds=all ./unit-test

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
