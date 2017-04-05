##
## Makefile for  in /home/christian.betta/minishel/Minishell1-master
## 
## Made by Christian Betta
## Login   <christian.betta@epitech.net>
## 
## Started on  Thu Mar 23 17:54:25 2017 Christian Betta
## Last update Tue Apr  4 18:43:57 2017 Christian Betta
##

SRC	=	shell1.c		\
		shell2.c		\
		main.c			\
		my_str_to_wordtab.c	\
		my_all.c		\
		my_strcmp.c		\
		my_all2.c

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
