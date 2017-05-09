/*
** check_pipe.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:11:22 2017 Christian Betta
** Last update Tue May  9 14:11:23 2017 Christian Betta
*/

#include "my.h"

int	check_pipe(t_stc *stc)
{
  int	i;

  i = 0;
  while (stc->s[i] != '\0')
    {
      if (stc->s[i] == '|')
	{
	  if (stc->s[i] == '|' && stc->s[i + 1] == '\0')
	    my_puterror("Invalid null command.\n");
	  if ((stc->rtn = run_pipe(stc)) == 0 || stc->rtn == 1)
	    return (stc->rtn);
	}
      i = i + 1;
    }
  return (84);
}
