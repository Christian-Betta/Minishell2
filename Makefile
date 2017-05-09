##
## Makefile for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
## 
## Made by Christian Betta
## Login   <christian.betta@epitech.net>
## 
## Started on  Tue May  9 14:09:50 2017 Christian Betta
## Last update Tue May  9 14:10:07 2017 Christian Betta
##

SRC	=	$(addprefix src/,	\
		42sh.c			\
		get_next_line.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		concatener.c		\
		my_getnbr.c		\
		check_access.c		\
		my_exec_fonctions.c	\
		check_env.c		\
		check_divers.c		\
		check_cd.c		\
		my_cd_moins.c		\
		change_pwd.c		\
		print_env.c		\
		my_setenv.c		\
		my_unsetenv.c		\
		verif.c			\
		epur_pv.c		\
		pv.c			\
		find_in_env.c		\
		check_pipe.c		\
		run_pipe.c		\
		my_puterror.c		\
		)

OBJ	= $(SRC:.c=.o)

RM	= rm -f

CC	= gcc

AR	= ar

NAME	= mysh

CFLAGS  += -W -Wall -Wextra -g3 -I./include -L./src -lprintf

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all
