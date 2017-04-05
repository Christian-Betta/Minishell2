/*
** my_all2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue Apr  4 17:05:49 2017 Christian Betta
** Last update Wed Apr  5 13:51:33 2017 Christian Betta
*/

#include "my.h"

char	*my_epure(char *src)
{
  int	size;

  size++;
  size = my_strlen(src) - 2;
  while (src[size] == ' ' && src[size] != '\0')
    {
      src[size] = '\0';
      size = size - 2;
      size++;
    }
  while (*src == ' ' && *src != '\0')
    src = src + 1;
  return (src);
}

char	*my_epure_2(char *str)
{
  int	i;
  int	a;
  char	*dest;

  a = 0;
  i = 0;
  dest = malloc(sizeof(char) * 1000);
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
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
