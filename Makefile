# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 16:04:17 by ochurko           #+#    #+#              #
#    Updated: 2024/01/26 15:23:55 by ochurko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
BONUS = checker


SRC_1 = push_swap.c \

SRC_2 =	lst_check.c \
		utils_2.c \
		utils.c \
		op_push.c \
		op_swap.c \
		op_replace.c \
		op_rep_rep.c \
		sort.c \
		free_error.c \
		position.c \
		init_stack_a.c \

BONUS_SRC = bonus/checker.c \
			bonus/ft_get_next_line.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ = ${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus