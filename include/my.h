/*
** my.h for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/include
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:09:40 2017 Christian Betta
** Last update Tue May  9 14:09:40 2017 Christian Betta
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

typedef struct	s_stc
{
  char	*s;
  pid_t	pid;
  int	status;
  char	**path;
  char	*concat;
  char	**concat2;
  char	*home;
  char	**s2;
  char	*tild;
  int	cd_m;
  char	*old;
  char	*old2;
  int	rtn;
}		t_stc;

typedef struct	s_gnl
{
  int   j;
  char  *line;
}		t_gnl;

/*
**42sh
*/
char    *find_path();
int     check_access(t_stc *);
int     my_exec_fonctions(t_stc *);
char    *concatener(t_stc *, int, char);
char    *get_next_line(const int);
int     check_env(t_stc *);
int     check_divers(t_stc *);
int	check_cd(t_stc *);
char    *find_home();
int     change_pwd();
int     my_cd_moins(t_stc *);
int	print_env();
int     my_setenv(t_stc *);
int     my_unsetenv(t_stc *);
int     put_in_char2(char **, int, char *, int);
int     find_nb_arg(char *, char);
int     verif(t_stc *);
int     my_pv(t_stc *);
int     check_pv(char *);
int     pv(t_stc *);
int	my_puterror(char *);
int     run_pipe(t_stc *);
int     check_pipe(t_stc *);

/*
**my_putchar.c
*/
void	my_putchar(char);

/*
**my_put_nbr.c
*/
void	my_put_nbr(int);

/*
**epur_str.c
*/
char    *epur_str(char *);

/*
**epur_pv.c
*/
char    *epur_pv(char *);

/*
**my_str_to_wordtab.c
*/
char    **my_str_to_wordtab(char *, char);

/*
**my_putstr.c
*/
int	my_putstr(char *);

/*
**my_strlen.c
*/
int	my_strlen(char *);

/*
**my_getnbr.c
*/
int	my_getnbr(char *);

/*
**my_printf.c
*/
void     my_printf(char *, ...);
void    fonctions(int, va_list);
char    tableau(char, int);
void    flag_pour();
void    flag_s(va_list);
void    flag_i(va_list);
void    flag_c(va_list);
void    flag_p(va_list);
void    flag_o(va_list);
void    flag_u(va_list);
void    flag_x(va_list);
void    flag_X(va_list);
void    flag_b(va_list);

/*
**my_revstr.c
*/
char	*my_revstr(char *);

/*
**my_strcmp.c && my_strncmp.c
*/
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);

/*
**my_putnbr_base.c
*/
char    *my_putnbr_base(int, int);

#endif
