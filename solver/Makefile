##
## EPITECH PROJECT, 2022
## lib
## File description:
## Makefile
##

MAKEFLAGS += -silent
CC = gcc

VPATH += src/

SRC += get_file_infos.c
SRC += solver.c
SRC += load_file_str.c
SRC += load_map.c
SRC += fill_final_map.c
SRC += find_path.c

CFLAGS = -I ../include/ -Wall -Wextra -g

LDFLAGS = -L ../lib/ -lmy -lprint

BUILD_DIR = build/

NAME = solver

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(@D)
	#@echo "  CC       $<      $@"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ echo "$(BLUE)Compilation of $(NAME)...$(NC)"
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	@ echo "$(GREEN)$(NAME) created$(NC)"

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OBJ)
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*
	@ echo "$(RED)clean successful !"

fclean: clean
	rm -f $(NAME)
	@ echo "$(RED)fclean successful !$(NC)"

re: 	fclean all

.PHONY: all clean fclean re .SILENT

BLUE = \033[1;34m
RED = \033[1;31m
GREEN = \033[1;32m
NC = \033[0m
