/*
** my_all2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue Apr  4 17:05:49 2017 Christian Betta
** Last update Tue Apr 18 14:10:30 2017 Christian Betta
*/

#include"my.h"

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
  if (str != NULL)
    {
      while (str[i])
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
  else
    return (NULL);
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
  if (str != NULL)
    while (str[i] != '\0')
      {
	if (str[i] == '/' && str[i - 1] != ' ')
	  return (1);
	i++;
      }
  return (0);
}
