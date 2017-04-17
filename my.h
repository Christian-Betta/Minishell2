/*
** my.h for  in /home/christian.betta/minishel/Minishell1-master
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 18:24:46 2017 Christian Betta
** Last update Thu Apr 13 18:41:05 2017 Christian Betta
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
  char		**my_env;
  char          **array;
  char          *str_cat;
  int           status;
  int           fd;
  char          **argument;
  pid_t         pid;
  char          *buffer;
  int		a;
  int		i;
  int		nbr;
  char		**cmd;
  char		*str;
  char		**tmp;
  char		**command;
}               t_mini;

typedef struct  s_var
{
  int           i;
  int           b;
  int           a;
}               t_var;

typedef struct s_mypid
{
  int   a;
  char  *str;
  char  *fus;
}		t_mypid;

typedef struct s_exec
{
  int   pid;
  int   status;
  char  **command;
  char  **tmp;
}		t_exec;

typedef struct s_pipe
{
  int   i;
  int   a;
  char  *dest;
}		t_pipe;

int     nbr_comm(char *str);
char    *get_next_line(int fd);
char    *get_next_line_dbg(int fd);
void	commande_multiple(t_mini c, char **envp);
void	commande_unique(t_mini c, char **envp);
char    *my_epure(char *src);
char    *my_epure_2(char *src);
void    test_exit(t_mini c, char **envp);
int	chemin(char *str);
char    **copy_env(char **env);
void    shell(t_mini control, char **env);
void    control_c();
void    cd(t_mini control, char ** envp);
char    **my_str_to_wordtab(char *str, char carac);
int     mystrstr(char *s1, char *s2);
char    *mystrcat(char *des, char *src);
void    pid(t_mini control, int a, char **env);
char    *epure_pipe(char *str);
int     nbr_pipe(char *str);
int     home_path(char **env);
void    my_exit(char *buffer);
int	exec_all(t_mini control);
void    my_pid(t_mini c, char **envp);
char    *mon_home(char **envp);
int     find_name(char **envp, char *str);
int     find_env(char **tabl);
void    un_env(t_mini c, char **envp);
void    set_env(t_mini v, char **envp);
int     pos_home(char ** tabl);
char    *recup_home(char **tabl);
void    my_putchar(char c);
void    my_putstr(char *str);
int     my_strlen(char *str);
int     mystrstr(char *s, char *sa);
char    *mystrcat(char *dest, char *src);
void	my_putstr2(char *str);
int     pos(char **tabl);
int     my_strncmp(char *s1, char *s2);
int     verif_en(char *str);
void    multi_str(char *str1, char *str2);
void    my_put_str_tab_path(char **tabl);
void	my_exec_prog(t_mini ex, char **envp);

#endif /* !MY_H_H_ */
