/*
** check_cd.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:10:52 2017 Christian Betta
** Last update Tue May  9 14:10:53 2017 Christian Betta
*/

#include "my.h"

int	check_cd4(t_stc *stc)
{
  if (chdir(stc->s2[1]) == 0)
    return (0);
  else
    {
      my_printf("%s: No such file or directory.\n",stc->s2[1]);
      return (1);
    }
  return (84);
}

int	check_cd3(t_stc *stc)
{
  if (access(stc->s2[1], F_OK) == 0)
    {
      if (chdir(stc->s2[1]) == -1)
	{
	  my_printf("%s: Not a directory.\n", stc->s2[1]);
	  return (1);
	}
      return (0);
    }
  else
    {
      if ((stc->rtn = check_cd4(stc)) == 0 || stc->rtn == 1)
	return (stc->rtn);
    }
  return (84);
}

int	check_cd2(t_stc *stc)
{
  if (my_strcmp("~/", stc->s2[1]) == 0)
    {
      chdir(stc->home);
      if (chdir(stc->tild) == 0)
	return (0);
      else
        my_printf("%s/%s: No such file or directory.\n", stc->home, stc->tild);
      return (1);
    }
  else if (my_strcmp("-", stc->s2[1]) == 0)
    {
      if (my_cd_moins(stc) == 0)
	return (0);
      else
	return (1);
    }
  else
    {
      if ((stc->rtn = check_cd3(stc)) == 0 || stc->rtn == 1)
	return (stc->rtn);
    }
  return (84);
}

int	check_cd(t_stc *stc)
{
  stc->s2 = my_str_to_wordtab(stc->s, ' ');
  if (my_strncmp("cd", stc->s, 2) == 0)
    {
      chdir(stc->home);
      return (0);
    }
  else if (my_strcmp("cd ", stc->s) == 0)
    {
      if (stc->s2[1] == NULL || stc->s2[1][0] == '\0')
	{
	  chdir(stc->home);
	  return (0);
	}
      stc->tild = (stc->s2[1] + 2);
      if ((stc->rtn = check_cd2(stc)) == 0 || stc->rtn == 1)
	return (stc->rtn);
    }
  return (84);
}
