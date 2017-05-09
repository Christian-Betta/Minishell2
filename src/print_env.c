/*
** print_env.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:16:22 2017 Christian Betta
** Last update Tue May  9 14:16:23 2017 Christian Betta
*/

#include "my.h"

int	print_env()
{
  extern char	**environ;
  int		i;

  i = 0;
  while (environ[i])
    {
      my_printf("%s\n", environ[i]);
      i = i + 1;
    }
  return (0);
}
