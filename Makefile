# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 22:48:41 by rfulop            #+#    #+#              #
#    Updated: 2017/09/26 22:48:51 by rfulop           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

CC = clang
CFLAGS = -g -Wall -Wextra -Werror
NAME_CHECKER = checker
NAME_PS = push_swap

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIB_PATH = ./libft/

SRC_FILES_CKR = checker.c \
				init.c \
				parse.c \
				inst.c \
				debug.c

SRC_FILES_PS = ps.c \
				init.c \
				debug.c \
				parse.c \
				inst.c \

INC_FILES = pushswap.h
LIB_FILES = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

OBJ_FILES_CKR = $(SRC_FILES_CKR:.c=.o)
OBJ_FILES_PS = $(SRC_FILES_PS:.c=.o)
OBJ_EXEC_CKR = $(addprefix $(OBJ_PATH), $(OBJ_FILES_CKR))
OBJ_EXEC_PS = $(addprefix $(OBJ_PATH), $(OBJ_FILES_PS))

all: $(NAME_CHECKER) $(NAME_PS)

$(OBJ_PATH) :
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(NAME_CHECKER): $(OBJ_PATH) $(OBJ_EXEC_CKR)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJ_EXEC_CKR) $(LIB) -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes
	@echo "\033[32mBinary \033[1;32m$(NAME_CHECKER)\033[1;0m\033[32m created.\033[0m"

$(NAME_PS): $(OBJ_PATH) $(OBJ_EXEC_PS)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJ_EXEC_PS) $(LIB) -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes
	@echo "\033[32mBinary \033[1;32m$(NAME_PS)\033[1;0m\033[32m created.\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJ_FILES_CKR)\033[1;0m\033[31m removed.\033[0m"
	@echo "\033[31mObjects files \033[1;31m$(OBJ_FILES_PS)\033[1;0m\033[31m removed.\033[0m"
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME_CHECKER)
	@rm -f $(NAME_PS)
	@make -C $(LIB_PATH) fclean
	@echo "\033[31mLib \033[1;31m$(NAME_CHECKER)\033[1;0m\033[31m removed.\033[0m"
	@echo "\033[31mLib \033[1;31m$(NAME_PS)\033[1;0m\033[31m removed.\033[0m"

re: fclean all
