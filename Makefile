# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:32:38 by ctycho            #+#    #+#              #
#    Updated: 2021/02/04 14:59:42 by ctycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror -framework OpenGL -framework AppKit

RM		=	rm -rf

AR		=	ar rc

SRC_D	=	./src/

OBJ_D	=	./obj

INC_D	=	./include/

INC		=	cub3d.h

SRCS	=	$(addprefix ${SRC_D}, cub3d.c parsing.c key.c ft_texture.c \
			ft_sprite.c ft_sprite_1.c cub3d_utils.c all_events.c pars_map.c \
			cub3d_tools.c plr_spr.c ft_bitmap.c wall_height.c )

OBJS	=	${SRCS:.c=.o}

#color-----------------------------------------------------------------------

GREEN	=	\033[0;32m
CYAN	=	\033[0;36m
MAGENTA	=	\033[0;35m
LGREEN	=	\033[1;32m
LYELLOW	=	\033[1;33m
LRED	=	\033[1;31m
LBLUE	=	\033[1;34m	

all:		$(NAME)
	
${NAME}: ${OBJS} $(INC_D)${INC}
	$(CC) -o $(NAME) $(OBJ) libft/libft.a get_next_line/g_n_l.a minilibx_opengl/libmlx.a $(FLAG)
	@echo "${CYAN}Library "${NAME}" succesfully compiled"

%.o: %.c ${INC}
	@${CC} ${FLAG} $< -o $@
	@echo "${MAGENTA}Object file: ${LYELLOW}$@ ${GREEN}successfuly compiled"

clean:		
	@rm -f ${OBJS}

fclean:		clean
	@rm -f ${NAME}

re:     fclean all
	@echo "${LBLUE}Library successfuly rebuilt"


# @${CC} $(SRCS) -I${INC_D} ${FLAG} libft/libft.a get_next_line/g_n_l.a minilibx_opengl/libmlx.a -o $(NAME) 
# @${AR} ${NAME} ${OBJS}
# 	@ranlib ${NAME}
# 	@echo "${CYAN}Library "${NAME}" succesfully compiled"