/*
** verif.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:16:52 2017 Christian Betta
** Last update Tue May  9 14:16:52 2017 Christian Betta
*/

#include "my.h"

int	verif(t_stc *stc)
{
  stc->concat2 = my_str_to_wordtab(stc->s, ' ');
  if (check_access(stc) == 0)
    {
      if ((stc->rtn = my_exec_fonctions(stc)) == 139 || stc->rtn == 136)
	return (stc->rtn);
      else
	return (0);
    }
  else
    {
      my_printf("%s: Command not found.\n", stc->concat2[0]);
      return (1);
    }
  return (84);
}
