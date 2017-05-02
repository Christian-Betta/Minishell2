/*
** exec.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Mon Apr 10 14:18:35 2017 Christian Betta
** Last update Tue Apr 25 14:24:55 2017 Christian Betta
*/

#include"my.h"

int     exec_all(t_mini *ex)
{
  int   a;

  a = 0;
  if ((execve(ex->str_cat, ex->argument, ex->my_env)) == -1)
    {
      ++a;
      return (a);
    }
  else
    return (0);
}

void     my_exec_prog(t_mini *ex, char **envp)
{
  ex->a = 0;
  ex->tmp = malloc(sizeof(char *) * 10000);
  ex->tmp[0] = malloc(sizeof(char) * 10000);
  ex->tmp[0] = ex->buffer;
  ex->command = my_str_to_wordtab(ex->buffer, ' ');
  if (access(ex->command[0], X_OK) == 0)
    {
      ex->mypid = fork();
      if (ex->mypid == 0)
        execve(ex->command[0], ex->tmp, envp);
      else if (ex->mypid > 0)
	waitpid(ex->mypid, &ex->status, 0);
      if (ex->status == 139)
	{
	  my_putstr("Segmentation fault (core dumped)\n");
	  ex->ret = 139;
	}
    }
  else
    {
      multi_str(ex->buffer, ": Command not found.\n");
      ex->ret = 1;
    }
  free(ex->tmp[0]);
}
