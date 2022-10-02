# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 07:32:29 by cleibeng          #+#    #+#              #
#    Updated: 2022/10/01 07:01:56 by cleibeng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRCS_SERV = srcs/server.c\
			srcs/utils_server.c
SRCS_CLIENT = srcs/client.c\
			  srcs/utils_client.c

OBJS_SERV = ${SRCS_SERV:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

DEP = ${SRCS_SERV:.c=.d} ${SRCS_CLIENT:.c=.d}

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

LIBFT = libft/libft.a

INCLUDE = -I libft

all:${SERVER} ${CLIENT}

%.o:%.c
	${CC} ${CFLAGS} ${INCLUDE} -O0 -c $< -o $@

${SERVER} : ${LIBFT} ${OBJS_SERV}
	${CC} ${OBJS_SERV} -o ${SERVER} -g3 -Llibft -lft

${CLIENT} : ${LIBFT} ${OBJS_CLIENT}
	${CC} ${OBJS_CLIENT} -o ${CLIENT} -g3 -Llibft -lft

${LIBFT}:
	make -C libft

clean:
	${RM} ${OBJS_SERV} ${OBJS_CLIENT} ${DEP}
	make clean -C libft


fclean: clean
		${RM} ${SERVER} ${CLIENT}
		make fclean -C libft

re:	fclean
	make all

norminette:
	@norminette srcs
	@norminette libft

-include ${DEP}

.PHONY: all clean fclean re norminette
