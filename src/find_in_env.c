/*
** find_in_env.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:12:01 2017 Christian Betta
** Last update Tue May  9 14:12:02 2017 Christian Betta
*/

#include "my.h"

char    *find_pwd()
{
  extern char   **environ;
  int   i;

  i = 0;
  while (environ[i])
    {
      if (my_strcmp("PWD=", environ[i]) == 0)
        return (environ[i] + 4);
      i = i + 1;
    }
  return (NULL);
}

char	*find_home()
{
  extern char	**environ;
  int	i;

  i = 0;
  while (environ[i])
    {
      if (my_strcmp("HOME=", environ[i]) == 0)
	return (environ[i] + 5);
      i = i + 1;
    }
  return (NULL);
}

char	*find_path()
{
  extern char	**environ;
  int	i;

  i = 0;
  while (environ[i])
    {
      if (my_strcmp("PATH=", environ[i]) == 0)
	return (environ[i] + 5);
      i = i + 1;
    }
  return (NULL);
}
