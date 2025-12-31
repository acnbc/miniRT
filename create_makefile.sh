#!/bin/bash

_CC=''
_NAME=''
_DIR_LIB=''
_DIR_INCLUDE=''
_LIBFT=''
_INCLUDE_MINILIBX=''
_DIR_LIBX=''
_MINILIBX=''
_DIR_OBJ=''
_ARRAY_DIR=''
_FILES=''
_ADD_FLAGS_COMPILE_PROGRAM=''
_ADD_FLAGS_COMPILE_OBJS=''

MAKE_EXISTIS=$(find . -type f | grep -F ./Makefile | wc -l)
_UPDATE='N'


shopt -s nocasematch
if [ -n "$1" ] && [[ $1 != "-y" ]] || [[ $1 == "--help" ]]; then
	echo "Usage: ./create_makefile.sh [options]"
	echo "Options:"
	echo "  --help	Show this help message and exit"
	echo "  -y, -Y	Automatically update the Makefile if it exists"
	exit 0
fi
shopt -u nocasematch

if [ "$1" == "-y" ] || [ "$1" == "-Y" ]; then
	_UPDATE='Y'
elif [ $MAKE_EXISTIS -eq 1 ] && [ "$_UPDATE" != "Y" ] && [ "$_UPDATE" != "y" ]; then
	read -p "Makefile already exists. Do you want to update it? (Y/N): " _UPDATE
fi

if ([ "$_UPDATE" == "N" ] && [ "$_UPDATE" == "n" ]) || [ $MAKE_EXISTIS -eq 0 ]; then
	read -p "Enter the program name: " _NAME
	read -p "Enter the program compiler (default: cc): " _CC
	read -p "Enter the include directory (default: include/): " _DIR_INCLUDE
	read -p "Enter the libft directory (default: lib/): " _DIR_LIB
	read -p "Enter the libft file (default: libft.a): " _LIBFT

	read -p "Include minilibx? (y/n): " _INCLUDE_MINILIBX
	if [ "${_INCLUDE_MINILIBX,,}" == "y" ]; then
		read -p "Enter the minilibx directory (default: minilibx/): " _DIR_LIBX
		read -p "Enter the minilibx file (default: libmlx.a): " _MINILIBX
	fi

	read -p "Enter the object files directory (default: obj/): " _DIR_OBJ
	read -p "Enter additional flags for compiling the program: " _ADD_FLAGS_COMPILE_PROGRAM
	read -p "Enter additional flags for compiling object files: " _ADD_FLAGS_COMPILE_OBJS
else
	_CC=$(cat Makefile | grep -F 'CC =' | sed -E 's/CC =\s*(.)/\1/')
	_NAME=$(cat Makefile | grep -F 'NAME =' | sed -E 's/NAME =\s*(.)/\1/')
	_DIR_INCLUDE=$(cat Makefile | grep -F 'DIR_INCLUDE =' | sed -E 's/DIR_INCLUDE =\s*(\.\/)?(.*)/\2/')
	_DIR_LIB=$(cat Makefile | grep -F 'DIR_LIB =' | sed -E 's/DIR_LIB =\s*(\.\/)?(.*)/\2/')
	_LIBFT=$(cat Makefile | grep -F 'LIBFT =' | sed -E 's/LIBFT =\s*\$\(DIR_LIB\)\/(.*)/\1/')
	_DIR_LIBX=$(cat Makefile | grep -F 'DIR_LIBX =' | sed -E 's/DIR_LIBX =\s*(\.\/)?(.*)/\2/')
	_MINILIBX=$(cat Makefile | grep -F 'MINILIBX =' | sed -E 's/MINILIBX =\s*\$\(DIR_LIBX\)\/(.*)/\1/')
	_DIR_OBJ=$(cat Makefile | grep -F 'DIR_OBJ =' | sed -E 's/DIR_OBJ =\s*(\.\/)?(.*)/\2/')
	_ADD_FLAGS_COMPILE_PROGRAM=$(cat Makefile | grep -F 'ADD_FLAGS_COMPILE_PROGRAM =' | sed -E 's/ADD_FLAGS_COMPILE_PROGRAM =\s*(.*)/\1/')
	_ADD_FLAGS_COMPILE_OBJS=$(cat Makefile | grep -F 'ADD_FLAGS_COMPILE_OBJS =' | sed -E 's/ADD_FLAGS_COMPILE_OBJS =\s*(.*)/\1/')

fi


if [ -z "$_CC" ]; then
	_CC="cc"
fi

if [ -z "$_DIR_INCLUDE" ]; then
	_DIR_INCLUDE="include"
fi

if [ -z "$_DIR_LIB" ]; then
	_DIR_LIB="lib"
fi

if [ -z "$_LIBFT" ]; then
	_LIBFT="libft.a"
fi

if [ "${_INCLUDE_MINILIBX,,}" == "y" ] && [ -z "$_DIR_LIBX" ]; then
	_DIR_LIBX="minilibx"
fi

if [ "${_INCLUDE_MINILIBX,,}" == "y" ] && [ -z "$_MINILIBX" ]; then
	_MINILIBX="libmlx.a"
fi

if [ -z "$_DIR_OBJ" ]; then
	_DIR_OBJ="obj"
fi


REGEX_PATH="(^\.\/("$_DIR_INCLUDE"|"$_DIR_LIB"|"$_DIR_OBJ"|\.))"

if [ -n "$_DIR_LIBX" ]; then
	REGEX_PATH="(^\.\/("$_DIR_INCLUDE"|"$_DIR_LIB"|"$_DIR_OBJ"|"$_DIR_LIBX"|\.))"
fi


_ARRAY_DIR=$(find . -type d | sed -E "/$REGEX_PATH|(^\.$)|(^\.\/\s$)/d" | sed -E 's/\.(.*)/\t\$(DIR_OBJ)\1 \\/' | sed -E '$s/(.*)\s\\/\1/')
_FILES=$(find . -type f | grep -F .c | sed -E "/$REGEX_PATH|(^\.\/\s$)/d" | sed -E 's/\.\/(.*)/\t\1 \\/' | sed -E '$s/(.*)\s\\/\1/')


CC="CC = $_CC"
NAME="NAME = $_NAME"
DIR_INCLUDE="DIR_INCLUDE = ./$_DIR_INCLUDE"
DIR_LIB="DIR_LIB = ./$_DIR_LIB"
LIBFT="LIBFT = "'$(DIR_LIB)'"/$_LIBFT"
DIR_LIBX="DIR_LIBX = ./$_DIR_LIBX"
MINILIBX="MINILIBX = "'$(DIR_LIBX)'"/$_MINILIBX"
DIR_OBJ="DIR_OBJ = ./$_DIR_OBJ"
DIR='DIR = $(DIR_OBJ) \
'"$_ARRAY_DIR"
FILES="SRC = $_FILES"
OBJS='OBJS := $(addprefix $(DIR_OBJ)/,$(SRC:%.c=%.o))'
ADD_FLAGS_COMPILE_PROGRAM="ADD_FLAGS_COMPILE_PROGRAM = $_ADD_FLAGS_COMPILE_PROGRAM"
ADD_FLAGS_COMPILE_OBJS="ADD_FLAGS_COMPILE_OBJS = $_ADD_FLAGS_COMPILE_OBJS"



echo -e "$CC\n" > Makefile
echo -e "$NAME\n" >> Makefile
echo -e "$DIR_INCLUDE\n" >> Makefile
echo -e "$DIR_LIB\n" >> Makefile
echo -e "$LIBFT\n" >> Makefile

if [ -n "$_DIR_LIBX" ] && [ -n "$_MINILIBX" ]; then
	echo -e "$DIR_LIBX\n" >> Makefile
	echo -e "$MINILIBX\n" >> Makefile
fi

echo -e "$DIR_OBJ\n" >> Makefile
echo -e "$DIR\n" >> Makefile
echo -e "$FILES\n" >> Makefile
echo -e "$OBJS\n" >> Makefile
echo -e "$ADD_FLAGS_COMPILE_PROGRAM\n" >> Makefile
echo -e "$ADD_FLAGS_COMPILE_OBJS" >> Makefile

echo -n '
BLINKING = \033[5m
RESET = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(DIR_LIB)
' >> Makefile

if [ -n "$_DIR_LIBX" ] && [ -n "$_MINILIBX" ]; then
echo -n '	@ make -C $(DIR_LIBX)
	@ $(CC) -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME) $(ADD_FLAGS_COMPILE_PROGRAM)
' >> Makefile

else
echo -n '	@ $(CC) -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) -o $(NAME) $(ADD_FLAGS_COMPILE_PROGRAM)
' >> Makefile

fi

echo -n '	@ clear
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
' >> Makefile

if [ -n "$_DIR_LIBX" ] && [ -n "$_MINILIBX" ]; then
echo -n '	@ make clean -C $(DIR_LIBX)
' >> Makefile
fi

echo -n '	@ clear
	@ echo "$(RED)Object files removed!$(RESET)"

fclean:
	@ rm -rf $(DIR_OBJ) $(NAME)
	@ make fclean -C $(DIR_LIB)
' >> Makefile

if [ -n "$_DIR_LIBX" ] && [ -n "$_MINILIBX" ]; then
echo -n '	@ make clean -C $(DIR_LIBX)
' >> Makefile
fi

echo -n '	@ clear
	@ echo "$(RED)Object files and $(NAME) removed!$(RESET)"

re: fclean all

run: all clean
	./$(NAME)

update:
	@ ( bash create_makefile.sh -y 2>/dev/null && echo "$(GREEN)Makefile updated successfully!$(RESET)" ) || echo "$(RED)Failed to update Makefile. $2$(RESET)"

.PHONY: all clean fclean re run update $(NAME)
' >> Makefile
