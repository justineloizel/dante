##
## EPITECH PROJECT, 2022
## lib
## File description:
## Makefile
##

MAKEFLAGS += -silent
CC = gcc

VPATH +=

SRC +=

CFLAGS = -I include/ -Wall -Wextra

LDFLAGS = -L lib/

BUILD_DIR = build/

NAME = dante

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

$(NAME):
	make -C lib/my/
	make -C lib/my_printf/
	@ echo "$(BLUE)Compilation of $(NAME)...$(NC)"
	make -C solver/
	make -C generator/
	@ echo "$(GREEN)$(NAME) created$(NC)"

clean:
	make clean -C lib/my/
	make clean -C lib/my_printf/
	make clean -C solver/
	make clean -C generator/
	@ echo "$(RED)lib clean"
	rm -rf $(BUILD_DIR)
	rm -f $(OBJ)
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*
	@ echo "$(RED)clean successful !"

fclean: clean
	make fclean -C lib/my/
	make fclean -C lib/my_printf/
	make fclean -C solver/
	make fclean -C generator/
	rm -f $(NAME)
	@ echo "$(RED)fclean successful !$(NC)"

re: 	fclean all

.PHONY: all clean fclean re .SILENT

BLUE = \033[1;34m
RED = \033[1;31m
GREEN = \033[1;32m
NC = \033[0m
