##
## Makefile for  in /home/christian.betta/minishel/Minishell1-master
## 
## Made by Christian Betta
## Login   <christian.betta@epitech.net>
## 
## Started on  Thu Mar 23 17:54:25 2017 Christian Betta
## Last update Mon Apr 10 13:38:19 2017 Christian Betta
##

SRC	=	src/exit.c		\
		src/env.c		\
		src/main.c		\
		src/my_str_to_wordtab.c	\
		src/my_basique_fct.c	\
		src/my_basique_fct2.c   \
		src/mini_shell_fct.c

LIBS	=	-L. -lgnl -Wextra -Wall -Werror

OBJS	=	$(SRC:.c=.o)

RM	=	rm -f

CC	=	gcc

NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC)	$(OBJS) -o $(NAME) $(LIBS) -g

clean:
	$(RM)	$(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
