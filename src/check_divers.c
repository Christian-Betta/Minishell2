/*
** check_divers.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:11:04 2017 Christian Betta
** Last update Tue May  9 14:11:05 2017 Christian Betta
*/

#include "my.h"

int	check_divers(t_stc *stc)
{
  if (my_strncmp("exit", stc->s, 4) == 0)
    {
      write(1, "$>", 2);
      exit(0);
    }
  else if (stc->s == NULL || stc->s[0] == '\0')
    return (0);
  else if (check_pv(stc->s) == 0)
    {
      if ((stc->rtn = pv(stc)) == 0 || stc->rtn == 1 ||
	  stc->rtn == 139 || stc->rtn == 136)
	return (stc->rtn);
    }
  return (84);
}
