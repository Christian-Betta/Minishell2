/*
** my_exec_fonctions.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:13:11 2017 Christian Betta
** Last update Tue May  9 14:13:11 2017 Christian Betta
*/

#include "my.h"

int     check_status2(int status)
{
  if (status == 136 && WCOREDUMP(status))
    {
      my_putstr("Floating exception (core dumped)\n");
      return (136);
    }
  else
    {
      my_putstr("Floating exception\n");
      return (136);
    }
  return (1);
}

int     check_status1(int status)
{
  if (status == 139 && WCOREDUMP(status))
    {
      my_putstr("Segmentation fault (core dumped)\n");
      return (139);
    }
  else
    {
      my_putstr("Segmentation fault\n");
      return (139);
    }
  return (1);
}

int     check_valu(int status)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
        {
          check_status1(status);
          return (139);
        }
      else if (WTERMSIG(status) == 8)
        {
          check_status2(status);
          return (136);
        }
    }
  return (84);
}

int	my_exec_fonctions(t_stc *stc)
{
  extern char	**environ;

  stc->pid = fork();
  if (stc->pid == 0)
    {
      if (execve(stc->concat, stc->concat2, environ) == -1)
	execve(stc->s2[0], stc->s2, environ);
    }
  else if (stc->pid > 0)
    {
      waitpid(stc->pid, &stc->status, 0);
      stc->rtn = check_valu(stc->status);
      if (stc->rtn == 139 || stc->rtn == 136)
	return (stc->rtn);
    }
  return (0);
}
