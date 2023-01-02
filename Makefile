# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auzun <auzun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 21:10:21 by auzun             #+#    #+#              #
#    Updated: 2022/12/29 22:31:49 by auzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation flags
ifeq ($(DMEM),1)
MEM 		= -fsanitize=address
endif

ifeq ($(DTHREAD),1)
MEM 		= -fsanitize=thread
endif

#==============================================================================#
#                                   TARGETS                                    #
#==============================================================================#

NAME = miniRT
BONUS_NAME = miniRT_BONUS
#==============================================================================#
#                                   COMMANDS                                   #
#==============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DFLAGS = -MMD
MKDIR = mkdir -p
MAKE_LIBMLX=make -C ${LIBMLX_PATH}
LD_FLAGS=-lbsd  -L${LIBFT_PATH} -L lib -L${LIBMLX_PATH} \
				-lmlx_Linux -lft -L/usr/lib -lXext -lX11 -lm -lz
RM = rm -f
MAKE_SILENT = make --no-print-directory
INC_LIBFT = -L libft -lft

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

PURPLE = \033[35m
GREEN = \033[32m
YELLOW = \033[33m
END = \033[0m

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_DIR = src/
BONUS_SRC_DIR = bonus_src/
HEADER_DIR = include/
BONUS_HEADER_DIR = bonus_include/
OBJ_DIR = obj/
BONUS_OBJ_DIR = bonus_obj/
LIBFT=./libft/libft.a
LIBFT_PATH=./libft
LIBMLX=./minilibx-linux/libmlx_Linux.a
LIBMLX_PATH=./minilibx-linux

#==============================================================================#
#                                   SOURCES                                    #
#==============================================================================#

SRC =	main.c \
		\
		init/init.c \
		\
		clear/cleanup.c clear/clear_tab.c \
		\
		hooks/hooks.c \
		\
		vectors/vector_op.c vectors/vector_utils.c vectors/vector_op2.c\
		\
		intersect/intersect_sphere.c intersect/intersect_plane.c \
		intersect/intersect_cylinder.c intersect/intersect.c \
		intersect/cylinder_utils.c\
		\
		raytracing/rendering/draw.c raytracing/raytracer.c raytracing/rendering/colors.c \
		raytracing/effects/lights.c raytracing/effects/shadows.c\
		\
		parser/file_errors.c parser/parse_errors.c parser/value_errors.c \
		parser/vector_errors.c parser/check_values.c parser/check_vectors.c \
		parser/parse_scene.c parser/parse_line.c parser/parse_lights.c \
		parser/parse_coord.c parser/parse_camera.c parser/parse_cylinder.c \
		parser/parse_sphere.c parser/parse_plane.c parser/parse_colors.c\

BONUS_SRC =	main_bonus.c \
		\
		init/init_bonus.c \
		\
		clear/cleanup_bonus.c clear/clear_tab_bonus.c \
		\
		hooks/hooks_bonus.c \
		\
		vectors/vector_op_bonus.c vectors/vector_utils_bonus.c vectors/vector_op2_bonus.c\
		\
		intersect/intersect_sphere_bonus.c intersect/intersect_plane_bonus.c \
		intersect/intersect_cylinder_bonus.c intersect/intersect_bonus.c \
		intersect/cylinder_utils_bonus.c intersect/intersect_cone_bonus.c\
		intersect/cone_utils_bonus.c intersect/intersect_triangle_bonus.c\
		\
		raytracing/rendering/draw_bonus.c raytracing/raytracer_bonus.c raytracing/rendering/colors_bonus.c \
		raytracing/effects/lights_bonus.c raytracing/effects/shadows_bonus.c raytracing/effects/reflection_bonus.c\
		raytracing/effects/texture/uv_mapping_bonus.c raytracing/effects/texture/object_mapping_bonus.c \
		raytracing/effects/texture/ft_barycentric_coords.c raytracing/effects/perturbations_bonus.c \
		raytracing/effects/texture/texture_bonus.c\
		\
		parser/file_errors_bonus.c parser/parse_errors_bonus.c parser/value_errors_bonus.c \
		parser/vector_errors_bonus.c parser/check_values_bonus.c parser/check_vectors_bonus.c \
		parser/parse_scene_bonus.c parser/parse_line_bonus.c parser/parse_lights_bonus.c \
		parser/parse_coord_bonus.c parser/parse_camera_bonus.c parser/parse_cylinder_bonus.c \
		parser/parse_sphere_bonus.c parser/parse_plane_bonus.c parser/parse_colors_bonus.c\
		parser/check_indexes_bonus.c parser/indexes_errors_bonus.c parser/check_textures_bonus.c \
		parser/texture_errors_bonus.c parser/parse_texture_bonus.c parser/parse_cone_bonus.c\
		parser/parse_triangle_bonus.c\
		\
#==============================================================================#
#                                   HEADERS                                    #
#==============================================================================#

HEAD_NAME = $(HEADER_DIR)/miniRT.h
INC = -I./$(HEADER_DIR) -I${LIBFT_PATH} -I${LIBMLX_PATH}
BONUS_HEAD_NAME = $(BONUS_HEADER_DIR)/miniRT_bonus.h
BONUS_INC = -I./$(BONUS_HEADER_DIR) -I${LIBFT_PATH} -I${LIBMLX_PATH}

#==============================================================================#
#                                   OBJECTS                                    #
#==============================================================================#

OBJ = $(addprefix ${OBJ_DIR}, ${SRC:.c=.o})
BONUS_OBJ = $(addprefix ${BONUS_OBJ_DIR}, ${BONUS_SRC:.c=.o})

#==============================================================================#
#                                   MAKEFILE                                   #
#==============================================================================#

all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEAD_NAME)
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(DFLAGS) $(MEM) $(INC) -c $< -o $@ -g

$(NAME) : ${LIBFT} ${LIBMLX} $(OBJ)
	echo "$(YELLOW)Making MiniRT$(END)"
	$(CC) $(CFLAGS) $(OBJ) $(INC_LIBFT) ${LD_FLAGS} $(INC) $(MEM) -o $(NAME) -g
	echo "$(GREEN)Done$(END)"

bonus : $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o : $(BONUS_SRC_DIR)%.c $(BONUS_HEAD_NAME)
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(DFLAGS) $(MEM) $(BONUS_INC) -c $< -o $@ -g

$(BONUS_NAME) : ${LIBFT} ${LIBMLX} $(BONUS_OBJ)
	echo "$(YELLOW)Making MiniRT BONUS$(END)"
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(INC_LIBFT) ${LD_FLAGS} $(BONUS_INC) $(MEM) -o $(BONUS_NAME) -g
	echo "$(GREEN)Done$(END)"

${LIBMLX}:
	echo "$(YELLOW)Making MLX$(END)"
	$(MAKE_SILENT) -C ${LIBMLX_PATH}
	echo "$(GREEN)Done$(END)"

${LIBFT}:
	echo "$(YELLOW)Making LIBFT$(END)"
	$(MAKE_SILENT) -C ${LIBFT_PATH}
	echo "$(GREEN)Done$(END)"

clean :
	echo "$(PURPLE)Cleaning LIBFT's objects...$(END)"
	$(MAKE_SILENT) fclean -C ${LIBFT_PATH}
	echo "$(GREEN)Done$(END)"
	echo "$(PURPLE)Cleaning mlx's objects...$(END)"
	$(MAKE_SILENT) clean -C ${LIBMLX_PATH}
	echo "$(GREEN)Done$(END)"
	echo "$(PURPLE)Cleaning MiniRT's objects...$(END)"
	$(RM)r $(OBJ_DIR)
	$(RM)r $(BONUS_OBJ_DIR)
	echo "$(GREEN)Done$(END)"

fclean : clean
	echo "$(PURPLE)Cleaning MiniRT...$(END)"
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	echo "$(GREEN)Done$(END)"

re : fclean
	$(MAKE_SILENT) all

rebonus: fclean 
	${MAKE_SILENT} bonus

.PHONY : all clean fclean re bonus
.SILENT :
