NAME = miniRT

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm

# Diretórios
SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj
LIBFT_DIR = libft

# Bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = -lmlx -lXext -lX11

# Se libft existir, incluir
ifneq ($(wildcard $(LIBFT_DIR)/Makefile),)
	LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
	LIBFT_INC = -I$(LIBFT_DIR)
endif

# Flags de inclusão
INCLUDES = -I$(INC_DIR) $(LIBFT_INC)

# Fontes (adicione seus arquivos .c aqui)
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parsing/ \
	$(SRC_DIR)/math/ \
	$(SRC_DIR)/objects/ \
	$(SRC_DIR)/ray_tracing/ \
	$(SRC_DIR)/lighting/ \
	$(SRC_DIR)/mlx/

# Objetos
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regras principais
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MINILIBX) $(LDFLAGS)
	@echo "✓ $(NAME) compilado com sucesso!"

# Compilar libft se existir
$(LIBFT):
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
	fi

# Compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Criar diretório de objetos
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Limpar objetos
clean:
	@rm -rf $(OBJ_DIR)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		$(MAKE) -C $(LIBFT_DIR) clean; \
	fi
	@echo "✓ Objetos removidos"

# Limpar tudo
fclean: clean
	@rm -f $(NAME)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		$(MAKE) -C $(LIBFT_DIR) fclean; \
	fi
	@echo "✓ $(NAME) e objetos removidos"

# Recompilar
re: fclean all

# Bônus (adicione arquivos _bonus.c aqui quando necessário)
bonus: all

# Phony targets
.PHONY: all clean fclean re bonus