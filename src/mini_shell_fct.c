/*
** my_all2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue Apr  4 17:05:49 2017 Christian Betta
** Last update Mon Apr 10 16:38:22 2017 Christian Betta
*/

#include "include/my.h"

void    my_put_str_tab_path(char **tabl)
{
  int   a;

  a = 0;
  while (tabl[a])
    {
      my_putstr(tabl[a]);
      a++;
    }
}

void    my_putstr2(char *str)
{
  int   i;

  i = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	i++;
      else
	my_putchar(str[i]);
      i++;
    }
}

char	*my_epure_2(char *str)
{
  int	i;
  int	a;
  char	*dest;

  a = 0;
  i = 0;
  dest = malloc(sizeof(char) * 1000);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	i++;
      else
	{
	  dest[a] = str[i];
	  a++;
	  i++;
	}
    }
  dest[a] = 0;
  return (dest);
}

int     nbr_comm(char *str)
{
  int   i;
  int   a;

  i = (a = 0);
  while (str[i] != '\0')
    {
      if (str[i] == ';')
	a++;
      i++;
    }
  return (a);
}

int     chemin(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}
