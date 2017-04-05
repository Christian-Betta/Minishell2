/*
** my_all2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue Apr  4 17:05:49 2017 Christian Betta
** Last update Tue Apr  4 17:10:07 2017 Christian Betta
*/

#include "my.h"

char	*my_epure(char *src)
{
  int	a;

  a++;
  a = my_strlen(src) - 2;
  while (src[a] == ' ' && src[a] != '\0')
    {
      src[a] = '\0';
      a = a - 1;
    }
  while (*src == ' ' && *src != '\0')
    src = src + 1;
  return (src);
}
