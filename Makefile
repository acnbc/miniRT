CC = cc

NAME = miniRT

DIR_INCLUDE = ./includes

DIR_LIB = ./libft

LIBFT = $(DIR_LIB)/libft.a

DIR_LIBX = ./minilibx

MINILIBX = $(DIR_LIBX)/libmlx.a

DIR_OBJ = ./obj

DIR = $(DIR_OBJ) \
	$(DIR_OBJ)/images \
	$(DIR_OBJ)/src \
	$(DIR_OBJ)/src/interface \
	$(DIR_OBJ)/src/light_shading \
	$(DIR_OBJ)/src/math \
	$(DIR_OBJ)/src/parsing \
	$(DIR_OBJ)/src/parsing/object \
	$(DIR_OBJ)/src/ray_intersec \
	$(DIR_OBJ)/src/ray_tracing \
	$(DIR_OBJ)/src/utils

SRC = 	src/interface/hooks.c \
	src/interface/window.c \
	src/interface/color.c \
	src/light_shading/normal.c \
	src/light_shading/shadow.c \
	src/light_shading/utils.c \
	src/light_shading/lighting.c \
	src/math/matrix_inversion_operations.c \
	src/math/matrix_operations.c \
	src/math/operations_part_1.c \
	src/math/operations_part_2.c \
	src/math/tuple_operations.c \
	src/parsing/object/lst_object.c \
	src/parsing/object/object_type.c \
	src/parsing/object/transform_object.c \
	src/parsing/object/utils_object.c \
	src/parsing/object/sgl_object.c \
	src/parsing/read_file.c \
	src/ray_intersec/ray_cy.c \
	src/ray_intersec/ray_utils.c \
	src/ray_intersec/ray.c \
	src/ray_tracing/ray_tracing_shade.c \
	src/ray_tracing/ray_tracing.c \
	src/ray_tracing/ray_tracing_cam.c \
	src/ray_tracing/ray_tracing_fills.c \
	src/ray_tracing/ray_tracing_hit.c \
	src/utils/math_utils.c \
	src/utils/matrix_inversion_utils.c \
	src/utils/matrix_utils.c \
	src/utils/utils.c \
	src/main.c

OBJS := $(addprefix $(DIR_OBJ)/,$(SRC:%.c=%.o))

ADD_FLAGS_COMPILE_PROGRAM = -L./$(DIR_LIBX) -lmlx -lXext -lX11 -lm

ADD_FLAGS_COMPILE_OBJS = 

BLINKING = \033[5m
RESET = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(DIR_LIB)
	@ make -C $(DIR_LIBX)
	@ $(CC) -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME) $(ADD_FLAGS_COMPILE_PROGRAM)
	@ clear
	@ echo "$(GREEN)Compiled successfully!$(RESET)"

$(DIR_OBJ)/%.o: %.c | $(DIR_OBJ)
	@ echo "$(YELLOW)Compiling $<$(RESET)"
	@ $(CC) -Wall -Wextra -Werror -g -c $< -o $@ $(ADD_FLAGS_COMPILE_OBJS)

$(DIR_OBJ):
	@ mkdir -p $(DIR)
	@ echo "$(YELLOW)Object directories created!$(RESET)"

clean:
	@ rm -rf $(DIR_OBJ)
	@ make clean -C $(DIR_LIB)
	@ make clean -C $(DIR_LIBX)
	@ clear
	@ echo "$(RED)Object files removed!$(RESET)"

fclean:
	@ rm -rf $(DIR_OBJ) $(NAME)
	@ make fclean -C $(DIR_LIB)
	@ make clean -C $(DIR_LIBX)
	@ clear
	@ echo "$(RED)Object files and $(NAME) removed!$(RESET)"

re: fclean all

run: clean all
	./$(NAME) $(MAP)

update:
	@ ( bash create_makefile.sh -y 2>/dev/null && echo "$(GREEN)Makefile updated successfully!$(RESET)" ) || echo "$(RED)Failed to update Makefile. $2$(RESET)"

.PHONY: all clean fclean re run update $(NAME)
