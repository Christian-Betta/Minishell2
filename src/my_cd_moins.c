/*
** my_cd_moins.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:12:48 2017 Christian Betta
** Last update Tue May  9 14:12:49 2017 Christian Betta
*/

#include "my.h"

int	my_cd_moins(t_stc *stc)
{
  if (stc->cd_m == 0)
    {
      stc->old2 = getcwd(stc->old2, 256);
      if (chdir(stc->old) == 0)
	{
	  stc->cd_m = 1;
	  return (0);
	}
    }
  else if (stc->cd_m == 1)
    {
      stc->old = getcwd(stc->old, 256);
      if (chdir(stc->old2) == 0)
	{
	  stc->cd_m = 0;
	  return (0);
	}
    }
  return (1);
}
