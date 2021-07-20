# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 12:47:19 by lelderbe          #+#    #+#              #
#    Updated: 2021/07/20 19:50:30 by lelderbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_SRCS	= main.c

PARSE_DIR	= parser/
PARSE_SRCS	= parse.c
PARSE_SRCS	:= $(addprefix ${PARSE_DIR}, ${PARSE_SRCS})

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
UTILS_SRCS	= core_p1.c core_p2.c core_p3.c list.c print.c
UTILS_SRCS	:= $(addprefix ${UTILS_DIR}, ${UTILS_SRCS})

CHK_DIR		= chk/
CHK_SRCS	= main.c
CHK_SRCS	:= $(addprefix ${CHK_DIR}, ${CHK_SRCS})

GNL_DIR		= gnl/
GNL_SRCS	= get_next_line.c get_next_line_utils.c
GNL_SRCS	:= $(addprefix ${GNL_DIR}, ${GNL_SRCS})

SRCS		= ${MAIN_SRCS} ${PARSE_SRCS} ${OPER_SRCS} ${ALGO_SRCS} ${ALGOC_SRCS} ${UTILS_SRCS} ${GNL_SRCS}
CH_SRCS		= ${CHK_SRCS} ${PARSE_SRCS} ${OPER_SRCS} ${ALGO_SRCS} ${ALGOC_SRCS} ${UTILS_SRCS} ${GNL_SRCS}

HEADERS		= push_swap.h

OBJS		= ${SRCS:.c=.o}
CH_OBJS		= ${CH_SRCS:.c=.o}

NAME		= push_swap
CH_NAME		= checker

LIBFT_DIR	= libft/

LIBFT		= libft.a

INCLUDES	= -I. -I${LIBFT_DIR} -I${GNL_DIR}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o:		%.c ${HEADERS}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${LIBFT_DIR}${LIBFT} ${OBJS}
			${CC} ${OBJS} ${INCLUDES} -L${LIBFT_DIR} -lft -o ${NAME}

${CH_NAME}:	${LIBFT_DIR}${LIBFT} ${CH_OBJS}
			${CC} ${CH_OBJS} ${INCLUDES} -L${LIBFT_DIR} -lft -o ${CH_NAME}

${LIBFT_DIR}${LIBFT}:	${LIBFT_DIR}
			${MAKE} -C ${LIBFT_DIR} bonus

bonus:		${NAME} ${CH_NAME}

clean:
			${RM} ${OBJS}
			${RM} ${CH_OBJS}
			${MAKE} -C ${LIBFT_DIR} clean

fclean:		clean
			${RM} ${NAME}
			${RM} ${CH_NAME}
			${MAKE} -C ${LIBFT_DIR} fclean

re:			fclean bonus

.PHONY:		all clean fclean re
