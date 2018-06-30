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

SRC1	=	$(wildcard src/server/*.c)

SRC2	=	$(wildcard src/ai/*.cpp)

SRC3	=	$(wildcard src/graphic_part/*.cpp)

CC	=	gcc

CPP	=	g++

RM	=	rm -f

INCLUDE	+=	-I./include

CFLAGS	=	-g -Wextra -Wall

CPPFLAGS	=	-I./include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CPPFLAGSIA	=	-I./include -std=gnu++11

NAME1	=	zappy_server

NAME2	=	zappy_ai

NAME3	=	zappy_graph

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.cpp=.o)

OBJ3	=	$(SRC3:.cpp=.o)

all:	$(NAME1) $(NAME2)

graph	:	$(NAME3)

%.o: %.c
	@printf "$(GREEN)Compilation: %s to %s\n$(WHITE)" $< $@
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(NAME1): $(OBJ1)
	@$(CC) -o $(NAME1) $(OBJ1) $(CFLAGS) -lm
	@printf "$(YELLOW)Executable generated: $(NAME1)$(WHITE)\n"

$(NAME2): $(OBJ2)
	@$(CPP) -o $(NAME2) $(OBJ2) $(CPPFLAGSIA)
	@printf "$(YELLOW)Executable generated: $(NAME2)$(WHITE)\n"

$(NAME3): $(OBJ3)
	@$(CPP) -o $(NAME3) $(OBJ3) $(CPPFLAGS)
	@printf "$(YELLOW)Executable generated: $(NAME3)$(WHITE)\n"

clean:
	@printf "$(BLUE)"
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3)
	@printf "$(RED)Deleting Binairies Success$(WHITE)\n"

fclean: clean
	@printf "$(BLUE)"
	$(RM) $(NAME1) $(NAME2) $(NAME3)
	@printf "$(RED)Deleting Executable Success$(WHITE)\n"

re	:	fclean all

.PHONY	:	clean fclean re
