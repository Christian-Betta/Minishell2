/*
** pipe.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Wed Apr 12 18:15:44 2017 Christian Betta
** Last update Thu Apr 13 10:01:14 2017 Christian Betta
*/

#include "my.h"

int	nbr_pipe(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	a++;
      i++;
    }
  return (a);
}

char	*epure_pipe(char *str)
{
  t_pipe	p;

  p.i = 0;
  p.a = nbr_pipe(str);
  p.dest = malloc(sizeof(char) * 100);
  while (str[p.i] != '\0')
    {
      if (str[p.i] == '|')
	p.a--;
      if (p.a == 0)
	{
	  p.i++;
	  while (str[p.i] == ' ')
	    p.i++;
	  while (str[p.i] != '\0')
	    {
	      p.dest[p.a] = str[p.i];
	      p.a++;
	      p.i++;
	    }
	  return (p.dest);
	}
      p.i++;
    }
}
