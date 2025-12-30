CC = cc

NAME = miniRT

DIR_INCLUDE = ./includes

DIR_LIB = ./libft

LIBFT = $(DIR_LIB)/libft.a

DIR_OBJ = ./obj

DIR = $(DIR_OBJ) \
	$(DIR_OBJ)/src

SRC = 	src/main.c

OBJS := $(addprefix $(DIR_OBJ)/,$(SRC:%.c=%.o))

ADD_FLAGS_COMPILE_PROGRAM = -lmlx -lXext -lX11 -lm

ADD_FLAGS_COMPILE_OBJS = 

BLINKING = \033[5m
RESET = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(DIR_LIB)
	@ $(CC) -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) -o $(NAME) $(ADD_FLAGS_COMPILE_PROGRAM)
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
	@ clear
	@ echo "$(RED)Object files removed!$(RESET)"

fclean:
	@ rm -rf $(DIR_OBJ) $(NAME)
	@ make fclean -C $(DIR_LIB)
	@ clear
	@ echo "$(RED)Object files and $(NAME) removed!$(RESET)"

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run $(NAME)
