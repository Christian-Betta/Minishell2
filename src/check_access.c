/*
** check_access.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:10:43 2017 Christian Betta
** Last update Tue May  9 14:10:43 2017 Christian Betta
*/

#include "my.h"

int	check_access(t_stc *stc)
{
  int	i;

  i = 0;
  while (stc->path[i] != NULL)
    {
      if (concatener(stc, i, '/') == NULL)
	write(1, "$>", 2);
      else
	{
	  if (access(stc->concat, X_OK) == 0 ||
	      access(stc->s2[0], X_OK) == 0)
	    return (0);
	  i = i + 1;
	}
    }
  return (1);
}
