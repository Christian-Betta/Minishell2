
/*
** my.h for  in /home/christian.betta/minishel/Minishell1-master
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 18:24:46 2017 Christian Betta
** Last update Tue Apr  4 14:33:07 2017 Christian Betta
*/

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

#ifndef MY_H_
# define MY_H_

typedef struct  S_minishell
{
  char          **array;
  char          *str_cat;
  int           status;
  int           fd;
  char          **argument;
  pid_t         pid;
  char          *buffer;
}               t_mini;

typedef struct  s_var
{
  int           i;
  int           b;
  int           a;
}               t_var;

char    *get_next_line(int fd);
char    *get_next_line_dbg(int fd);
void    test_exit(t_mini c, char **envp);
int	chemin(char *str);
char    **copy_env(char **env);
void     shell(t_mini control, char **env);
void    control_c();
void     cd(t_mini control);
char    **my_str_to_wordtab(char *str, char carac);
int     mystrstr(char *s1, char *s2);
char    *mystrcat(char *des, char *src);
void    pid(t_mini control, int a, char **env);
int     home_path(char **env);
void     my_exit(char *buffer);
int    exec_all(t_mini control, char **env);
void    my_pid(t_mini c, int a, char **env);
void    my_putchar(char c);
void    my_putstr(char *str);
int     my_strlen(char *str);
int     mystrstr(char *s, char *sa);
char    *mystrcat(char *dest, char *src);
void	my_putstr2(char *str);
void     my_exec_prog(t_mini ex);
int     my_strncmp(char *s1, char *s2);
void    my_put_str_tab_path(char **tabl);
void	 my_exec_progr(t_mini ex);
#endif /* !MY_H_H_ */
