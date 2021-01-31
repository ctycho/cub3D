# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 13:50:00 by ctycho            #+#    #+#              #
#    Updated: 2020/12/26 14:09:25 by ctycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	g_n_l.a

#flags------------------------------------------------------------------------

CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rc

#files------------------------------------------------------------------------

INC		=	get_next_line.h
SRCS	=	get_next_line.c get_next_line_utils.c
OBJS	=	${SRCS:.c=.o}

#colors----------------------------------------------------------------------

GREEN	=	\033[0;32m
CYAN	=	\033[0;36m
MAGENTA	=	\033[0;35m
LGREEN	=	\033[1;32m
LYELLOW	=	\033[1;33m
LRED	=	\033[1;31m
LBLUE	=	\033[1;34m	

#rules------------------------------------------------------------------------

all:		$(NAME)
	
${NAME}: ${OBJS} ${INC}
	@${AR} ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "${CYAN}Library "${NAME}" succesfully compiled"

%.o: %.c
	@${CC} ${FLAG} -I${INC} -c $< -o $@
	@echo "${MAGENTA}Object file: ${LYELLOW}$@ ${GREEN}successfuly compiled"

clean:		
	@rm -rf ${OBJS}

fclean:		clean
	@rm -rf ${NAME}

re:		fclean all
	@echo "${LBLUE}Library successfuly rebuilt"