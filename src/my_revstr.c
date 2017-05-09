/*
** my_revstr.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:15:01 2017 Christian Betta
** Last update Tue May  9 14:15:02 2017 Christian Betta
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int   a;
  int   b;
  int   c;

  a = 0;
  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  b = i - 1;
  while (a > (i / 2))
    {
      c = str[b];
      str[b] = str[a];
      str[a] = c;
      a = a + 1;
      b = b - 1;
      i = i - 1;
    }
  return (str);
}
