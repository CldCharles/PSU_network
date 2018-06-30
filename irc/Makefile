##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## MAKEFILE
##

RED	=	\033[01;31m

GREEN	=	\033[01;32m

YELLOW	=	\033[01;33m

BLUE	=	\033[01;34m

WHITE	=	\033[0m

SRC1	=	src/server/serv2.c		\
		src/server/int_max.c		\
		src/server/xgetline.c		\
		src/server/manage_cmd.c		\
		src/server/cmd_nick.c		\
		src/server/cmd_quit.c		\
		src/server/cmd_user.c		\
		src/server/usr_list.c		\
		src/server/go_to_usr.c		\
		src/server/str_to_wordtab.c	\
		src/server/str_to_wordtab2.c	\
		src/server/cmd_join.c		\
		src/server/chan_list.c		\
		src/server/serv2bis.c		\
		src/server/cmd_msg.c		\
		src/server/cmd_names.c		\

SRC2	=	src/client/client.c		\
		src/client/xgetline.c		\
		src/client/iscommand.c		\
		src/client/cmd_serv.c		\
		src/client/cmd_nick.c		\
		src/client/cmd_quit.c		\
		src/client/str_to_wordtab.c	\

CC	=	gcc

RM	=	rm -f

INCLUDE	+=	-I./include

CFLAGS	=	-g -Wextra -Wall -Werror

NAME1	=	server

NAME2	=	client

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

all:	$(NAME1) $(NAME2)

objdump:	$(NAME1)

nm:	$(NAME2)

%.o: %.c
	@printf "$(GREEN)Compilation: %s to %s\n$(WHITE)" $< $@
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(NAME1): $(OBJ1)
	@$(CC) -o $(NAME1) $(OBJ1) $(CFLAGS)
	@printf "$(YELLOW)Executable generated: $(NAME1)$(WHITE)\n"

$(NAME2): $(OBJ2)
	@$(CC) -o $(NAME2) $(OBJ2) $(CFLAGS)
	@printf "$(YELLOW)Executable generated: $(NAME2)$(WHITE)\n"

clean:
	@printf "$(BLUE)"
	$(RM) $(OBJ1) $(OBJ2)
	@printf "$(RED)Deleting Binairies Success$(WHITE)\n"

fclean: clean
	@printf "$(BLUE)"
	$(RM) $(NAME1) $(NAME2)
	@printf "$(RED)Deleting Executable Success$(WHITE)\n"

re	:	fclean all

.PHONY	:	clean fclean re objdump nm
