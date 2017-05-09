/*
** check_env.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:11:14 2017 Christian Betta
** Last update Tue May  9 14:11:15 2017 Christian Betta
*/

#include "my.h"

int	check_env2(t_stc *stc)
{
  if (my_strncmp("unsetenv", stc->s, 8) == 0)
    {
      my_printf("%s: Too few arguments.\n", stc->s);
      return (1);
    }
  else if (my_strcmp("setenv ", stc->s) == 0)
    {
      if (my_setenv(stc) == 0)
	return (0);
      else
	return (1);
    }
  else if (my_strcmp("unsetenv ", stc->s) == 0)
    {
      if (my_unsetenv(stc) == 0)
	return (0);
      else
	return (1);
    }
  return (84);
}

int	check_env(t_stc *stc)
{
  if (my_strncmp("env", stc->s, 3) == 0)
    {
      print_env();
      return (0);
    }
  else if (my_strncmp("setenv", stc->s, 6) == 0)
    {
      print_env();
      return (0);
    }
  else
    {
      stc->rtn = check_env2(stc);
      if (stc->rtn == 0 || stc->rtn == 1)
	return (stc->rtn);
    }
  return (84);
}
