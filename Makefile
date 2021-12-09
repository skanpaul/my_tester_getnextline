# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 09:45:53 by ski               #+#    #+#              #
#    Updated: 2021/11/04 16:34:14 by ski              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC				= cc
CFLAGS 			= -Wall -Wextra -Werror
AR 				= ar rc
RM				= rm -f 
NORM			= norminette -R CheckForbiddenSourceHeader
# **************************************************************************** #
BUF_SIZE		= 10
BUF_FLAG		= -D BUFFER_SIZE=${BUF_SIZE}
# ----------------------------------------------------------------------------
NAME 			= a.out
# ----------------------------------------------------------------------------
PATH_MAIN		= ./
HD_MAIN			= main.h
SRC_MAIN		= $(wildcard *.c)
OBJ_MAIN		= ${SRC_MAIN:.c=.o}
MK_MAIN			= Makefile
# ----------------------------------------------------------------------------
PATH_GNL		= ../getnextline/
HD_GNL			= ${PATH_GNL}get_next_line.h
SRC_GNL			= $(wildcard ${PATH_GNL}*.c) 
OBJ_GNL			= ${SRC_GNL:.c=.o}
#MK_GNL			= ${PATH_GNL}Makefile
# ----------------------------------------------------------------------------
PATH_LIBFT		= libft/
HD_LIBFT		= ${PATH_LIBFT}libft.h
# SRC_LIBFT		= $(wildcard ${PATH_LIBFT}*.c) 
# OBJ_LIBFT		= ${PATH_LIBFT:.c=.o}
# MK_LIBFT		= ${PATH_GNL}Makefile
# **************************************************************************** #
# PATH_SUBMAKE	= ${PATH_GNL}
# SRC_NORM		= ${SRC_MAIN}
# HD_NORM			= ${HD_MAIN}

# **************************************************************************** #
all: $(NAME)

#$(NAME): $(OBJ_GNL) $(OBJ_MAIN) ${MK_MAIN} 
#	${CC} $(CFLAGS) ${BUF_FLAG} $(OBJ_GNL) $(OBJ_MAIN) -o $(NAME)
$(NAME): $(SRC_GNL) $(SRC_MAIN) ${MK_MAIN} 
	${CC} $(CFLAGS) ${BUF_FLAG} $(SRC_GNL) $(SRC_MAIN) -L${PATH_LIBFT} -lft -o $(NAME)

clean: sub_clean
	${RM} *.o

fclean: clean sub_fclean
	${RM} $(NAME)

re: fclean all sub_re

.PHONY: all clean fclean re

nono: sub_nono
#	${NORM} ${SRC_NORM}
#	${NORM} ${HD_NORM}

# **************************************************************************** #
#sub_all:
#	${MAKE} all -C ${PATH_SUBMAKE}
#
#sub_clean:
#	${MAKE} clean -C ${PATH_SUBMAKE}
#
#sub_fclean:
#	${MAKE} fclean -C ${PATH_SUBMAKE}
#
#sub_re:
#	${MAKE} re -C ${PATH_SUBMAKE}
#
#sub_nono:
#	${MAKE} nono -C ${PATH_SUBMAKE}

# **************************************************************************** #
