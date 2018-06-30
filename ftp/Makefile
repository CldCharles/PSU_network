##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

RED	=	\033[01;31m

GREEN	=	\033[01;32m

YELLOW	=	\033[01;33m

BLUE	=	\033[01;34m

WHITE	=	\033[0m

SRC     =       src/main.c	\
		src/get_cmd.c	\
		src/fct_ptr.c	\
		src/noop.c	\
		src/help.c	\
		src/my_pwd.c	\
		src/my_cwd.c	\
		src/my_cdup.c	\
		src/quit.c	\
		src/pass.c	\
		src/bis.c	\

CC	=	gcc

RM	=	rm -f

INCLUDE	+=	-I./include

CFLAGS	=	-W -Wextra -Wall -Werror -g

NAME	=	server

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	@printf "$(GREEN)Compilation: %s to %s\n$(WHITE)" $< $@
	@$(CC) -c -fPIC $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@printf "$(YELLOW)Executable generated: $(NAME)$(WHITE)\n"

clean:
	@printf "$(BLUE)"
	$(RM) $(OBJ)
	@printf "$(RED)Deleting Binairies Success$(WHITE)\n"

fclean: clean
	@printf "$(BLUE)"
	$(RM) $(NAME)
	@printf "$(RED)Deleting Executable Success$(WHITE)\n"

re	:	fclean all

.PHONY	:	clean fclean re
