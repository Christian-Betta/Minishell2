/*
** exec.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Mon Apr 10 14:18:35 2017 Christian Betta
** Last update Tue Apr 11 15:20:12 2017 Christian Betta
*/

//#include "include/my.h"
#include"my.h"

int     exec_all(t_mini ex)
{
  int   a;

  a = 0;
  if ((execve(ex.str_cat, ex.argument, ex.my_env)) == -1)
    {
      ++a;
      return (a);
    }
  else
    return (0);
}

void     my_exec_prog(t_mini ex, char **envp)
{
  t_exec	e;

  e.tmp = malloc(sizeof(char *) * 10000);
  e.tmp[0] = malloc(sizeof(char) * 10000);
  e.tmp[0] = ex.buffer;
  e.command = my_str_to_wordtab(ex.buffer, ' ');
  if (access(e.command[0], X_OK) == 0)
    {
      e.pid = fork();
      if (e.pid == 0)
	execve(e.command[0], e.tmp, envp);
      else if (e.pid > 0 && verif_en(ex.buffer) == 1)
	{
	  waitpid(e.pid, &e.status, 0);
	  my_putchar('\n');
	}
      else if (e.pid > 0 && verif_en(ex.buffer) == 0)
	waitpid(e.pid, &e.status, 0);
      else if (e.status == 139)
        my_putstr("Segmentation fault (core dumped)\n");
    }
  else
    multi_str(ex.buffer, ": Command not found.\n");
  free(e.tmp[0]);
}
