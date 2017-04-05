/*
** main.c for  in /home/christian.betta/minishel/Minishell1-master
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 17:27:05 2017 Christian Betta
** Last update Wed Apr  5 11:24:58 2017 Christian Betta
*/

#include "my.h"

int	chemin(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

void     my_exec_prog(t_mini ex, char **envp)
{
  int   pid;
  int   status;
  int   a;
  char  **command;
  int   p;
  char **tmp;

  a = 0;
  tmp = malloc(sizeof(char *) * 10000);
  tmp[0] = malloc(sizeof(char) * 10000);
  tmp[0] = ex.buffer;
  command = my_str_to_wordtab(ex.buffer, ' ');
  if (access(command[0], X_OK) == 0)
    {
      pid = fork();
      if (pid == 0)
	execve(command[0], tmp, envp);
      else if (pid > 0)
	waitpid(pid, &status, 0);
      if (status == 139)
	my_putstr("Segmentation fault (core dumped)");
      my_putchar('\n');
    }
  else
    {
      my_putstr(ex.buffer);
      my_putstr(": Command not found.\n");
    }
}

void             cd(t_mini cd)
{
  char **tabl;

  tabl = malloc(sizeof(char *) * 10);
  tabl = my_str_to_wordtab(cd.buffer,' ');
  if ((my_strncmp("cd", tabl[0])) == 0)
    chdir(tabl[1]);
}

int             main(int ac, char **av, char **envp)
{
  t_mini        c;

  c.my_env = malloc(sizeof(char *) * (1000000));
  c.buffer = malloc(sizeof(char) * (1000));
  c.my_env = envp;
  my_putstr("> ");
  signal(SIGINT, control_c);
  c.array = copy_env(envp);
  test_exit(c, envp);
  return (0);
}
