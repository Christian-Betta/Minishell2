/*
** change_pwd.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:10:32 2017 Christian Betta
** Last update Tue May  9 14:10:32 2017 Christian Betta
*/

#include "my.h"

int	change_pwd2(char *str, int i, int a, int b)
{
  extern char	**environ;

  while (environ[i])
    {
      if (my_strcmp("PWD=", environ[i]) == 0)
	{
	  while (str[a] != '\0')
	    environ[i][b++] = str[a++];
	  environ[i][b] = '\0';
	}
      i = i + 1;
    }
  return (0);
}

int	change_pwd()
{
  char		*str;
  int		i;
  int		a;
  int		b;

  i = (a = 0);
  b = 4;
  if (!(str = malloc(sizeof(char) * 100)))
    return (84);
  if (!(str = malloc(sizeof(char) * (my_strlen(getcwd(str, 256)) + 1))))
    return (84);
  str = getcwd(str, 256);
  change_pwd2(str, i, a, b);
  return (0);
}
