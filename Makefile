# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:32:38 by ctycho            #+#    #+#              #
#    Updated: 2021/02/05 10:51:22 by ctycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3d

#flags------------------------------------------------------------------------

CC		:=	gcc
FLAG	:=	-Wall -Wextra -Werror -framework OpenGL -framework AppKit -I.
RM		:=	rm -rf
AR		:=	ar rc

#directories-----------------------------------------------------------------

LIB_D	:=	./libft/
GNL_D	:=	./get_next_line/
MLX_D	:=	./minilibx_opengl/
SRC_D	:=	./src/

#files------------------------------------------------------------------------

INC		:=	cub3d.h
SRCS	:=	$(addprefix ${SRC_D}, cub3d.c parsing.c key.c ft_texture.c \
			ft_sprite.c ft_sprite_1.c cub3d_utils.c cub3d_utils1.c all_events.c pars_map.c \
			cub3d_tools.c plr_spr.c ft_bitmap.c wall_height.c )

#color-----------------------------------------------------------------------

GREEN	:=	\033[0;32m
CYAN	:=	\033[0;36m
MAGENTA	:=	\033[0;35m
LGREEN	:=	\033[1;32m
LYELLOW	:=	\033[1;33m
LRED	:=	\033[1;31m
LBLUE	:=	\033[1;34m	

#rules------------------------------------------------------------------------

all:		$(NAME)
	
${NAME}: $(SRCS) ${INC}
	@make -C $(LIB_D)
	@make bonus -C $(LIB_D)
	@make -C $(GNL_D)
	@make -C $(MLX_D)
	@$(CC) -o $(NAME) $(SRCS) $(LIB_D)libft.a $(GNL_D)gnl.a $(MLX_D)libmlx.a $(FLAG)
	@echo "${MAGENTA}File: ${LYELLOW}$@ ${GREEN}successfuly compiled"

clean:		
	@rm -f ${NAME}
	@make clean -C $(LIB_D)
	@make clean -C $(GNL_D)
	@make clean -C $(MLX_D)
	@echo "${LGREEN}Everything is cleaned succesfully"

fclean:		clean
	@rm -f ${NAME}
	@make fclean -C $(LIB_D)
	@make fclean -C $(GNL_D)
	@make clean -C $(MLX_D)
	@echo "${LGREEN}Everything is cleaned succesfully"

re:			fclean all
	echo "${LBLUE}Library successfuly rebuilt"

