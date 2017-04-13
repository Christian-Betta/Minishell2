##
## Makefile for  in /home/christian.betta/minishel/Minishell1-master
## 
## Made by Christian Betta
## Login   <christian.betta@epitech.net>
## 
## Started on  Thu Mar 23 17:54:25 2017 Christian Betta
## Last update Thu Apr 13 09:36:44 2017 Christian Betta
##

SRC	=	exit.c			\
		fct_set_un.c		\
		env.c			\
		main.c			\
		pipe.c			\
		env_2.c			\
		my_put_nbr.c		\
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
