cmake_minimum_required(VERSION 3.17)
project(cub2)

set(CMAKE_C_FLAGS "-lmlx -framework OpenGL -framework AppKit")

link_directories(/usr/local/lib)
include_directories(get_next_line)
include_directories(libft)

add_executable(cub3d
        get_next_line/get_next_line.c
        get_next_line/get_next_line.h
        get_next_line/get_next_line_utils.c
        cub3d.c
        cub3d_tools.c
        cub3d_utils.c
        all_events.c
        ft_bitmap.c
        ft_sprite.c
        ft_sprite_1.c
        ft_texture.c
        key.c
        pars_map.c
        pars_map_2.c
        parsing.c
        plr_spr.c
        libft/src/ft_atoi.c
        libft/src/ft_bzero.c
        libft/src/ft_calloc.c
        libft/src/ft_isalnum.c
        libft/src/ft_isalpha.c
        libft/src/ft_isascii.c
        libft/src/ft_isdigit.c
        libft/src/ft_isprint.c
        libft/src/ft_itoa.c
        libft/src/ft_lstadd_back.c
        libft/src/ft_lstadd_front.c
        libft/src/ft_lstclear.c
        libft/src/ft_lstdelone.c
        libft/src/ft_lstiter.c
        libft/src/ft_lstlast.c
        libft/src/ft_lstmap.c
        libft/src/ft_lstnew.c
        libft/src/ft_lstsize.c
        libft/src/ft_memccpy.c
        libft/src/ft_memchr.c
        libft/src/ft_memcmp.c
        libft/src/ft_memcpy.c
        libft/src/ft_memmove.c
        libft/src/ft_memset.c
        libft/src/ft_putchar_fd.c
        libft/src/ft_putendl_fd.c
        libft/src/ft_putnbr_fd.c
        libft/src/ft_putstr_fd.c
        libft/src/ft_split.c
        libft/src/ft_strchr.c
        libft/src/ft_strdup.c
        libft/src/ft_strjoin.c
        libft/src/ft_strlcat.c
        libft/src/ft_strlcpy.c
        libft/src/ft_strlen.c
        libft/src/ft_strmapi.c
        libft/src/ft_strncmp.c
        libft/src/ft_strnstr.c
        libft/src/ft_strrchr.c
        libft/src/ft_strtrim.c
        libft/src/ft_substr.c
        libft/src/ft_tolower.c
        libft/src/ft_toupper.c
#        minilibx_opengl_20191021/font.c
#        minilibx_opengl_20191021/mlx.h
#        minilibx_opengl_20191021/mlx_init_loop.m
#        minilibx_opengl_20191021/mlx_int.h
#        minilibx_opengl_20191021/mlx_int_str_to_wordtab.c
#        minilibx_opengl_20191021/mlx_mouse.m
#        minilibx_opengl_20191021/mlx_new_image.m
#        minilibx_opengl_20191021/mlx_new_window.h
#        minilibx_opengl_20191021/mlx_new_window.m
#        minilibx_opengl_20191021/mlx_opengl.h
#        minilibx_opengl_20191021/mlx_opengl.m
#        minilibx_opengl_20191021/mlx_png.c
#        minilibx_opengl_20191021/mlx_png.h
#        minilibx_opengl_20191021/mlx_rgb.c
#        minilibx_opengl_20191021/mlx_shaders.c
#        minilibx_opengl_20191021/mlx_xpm.c
     )
