##
## Makefile for  in /home/christian.betta/minishel/Minishell1-master
## 
## Made by Christian Betta
## Login   <christian.betta@epitech.net>
## 
## Started on  Thu Mar 23 17:54:25 2017 Christian Betta
## Last update Tue Apr 11 15:18:43 2017 Christian Betta
##

SRC	=	exit.c			\
		env.c			\
		main.c			\
		my_str_to_wordtab.c	\
		my_basique_fct.c	\
		exec.c			\
		my_basique_fct2.c	\
		mini_shell_fct.c	\
		mini_shell_fct2.c

##CFLAGS	=	-Wextra -Wall -g

LIBS	=	-L. -lgnl 

OBJS	=	$(SRC:.c=.o)

RM	=	rm -f

CC	=	gcc

NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC)	$(OBJS) -o $(NAME) $(LIBS) 

clean:
	$(RM)	$(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
