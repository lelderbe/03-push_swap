# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 12:47:19 by lelderbe          #+#    #+#              #
#    Updated: 2021/07/20 14:20:03 by lelderbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_SRCS	= main.c parse.c

OPER_DIR	= operations/
OPER_SRCS	= swap.c push.c rotate.c reverse_rotate.c
OPER_SRCS	:= $(addprefix ${OPER_DIR}, ${OPER_SRCS})

ALGO_DIR	= algorithms/
ALGO_SRCS	= recursion.c small_sorts.c insertion.c greater.c radix.c
ALGO_SRCS	:= $(addprefix ${ALGO_DIR}, ${ALGO_SRCS})

ALGOC_DIR	= algorithms/common/
ALGOC_SRCS	= gets_p1.c gets_p2.c move.c rotate.c unsorted.c
ALGOC_SRCS	:= $(addprefix ${ALGOC_DIR}, ${ALGOC_SRCS})

UTILS_DIR	= utils/
UTILS_SRCS	= list_utils.c core_p1.c core_p2.c print.c
UTILS_SRCS	:= $(addprefix ${UTILS_DIR}, ${UTILS_SRCS})

SRCS		= ${MAIN_SRCS} ${OPER_SRCS} ${ALGO_SRCS} ${ALGOC_SRCS} ${UTILS_SRCS}

HEADERS		= push_swap.h

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

LIBFT_DIR	= libft/

LIBFT		= libft.a

INCLUDES	= -I. -I${LIBFT_DIR}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o:		%.c ${HEADERS}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${LIBFT_DIR}${LIBFT} ${OBJS}
			${CC} ${OBJS} ${INCLUDES} -L${LIBFT_DIR} -lft -o ${NAME}

#debug:		${LIBFT_DIR}${LIBFT} ${OBJS}
#			${CC} -ggdb ${OBJS} ${INCLUDES} -L${LIBFT_DIR} -lft -o ${NAME} -ltermcap -fsanitize=address -fno-omit-frame-pointer

${LIBFT_DIR}${LIBFT}:	${LIBFT_DIR}
			${MAKE} -C ${LIBFT_DIR} bonus

bonus:		${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} -C ${LIBFT_DIR} clean

fclean:		clean
			${RM} ${NAME}
			${MAKE} -C ${LIBFT_DIR} fclean
#			cd libft && ${MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re
