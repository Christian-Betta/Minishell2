/*
** my_all.c for  in /home/christian.betta/Minishell/PSU_2016_minishell1
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 19:11:43 2017 Christian Betta
** Last update Wed Apr  5 11:33:37 2017 Christian Betta
*/

#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr2(char *str)
{
  int	i;

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

void    my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_put_str_tab_path(char **tabl)
{
  int	a;

  a = 0;
  while (tabl[a])
    {
      my_putstr(tabl[a]);
      a++;
    }
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}


char    *mystrcat(char *dest, char *src)
{
  int   a;
  int   b;
  char  *str3;

  a = 0;
  b = 0;
  str3 = malloc(sizeof(str3) * (my_strlen(dest) + my_strlen(src) + 1));
  while (dest[a] != '\0')
    {
      str3[a] = dest[a];
      a++;
    }
  str3[a++] = '/';
  while (src[b] != '\0')
    str3[a++] = src[b++];
  str3[a] = '\0';
  return (str3);
}
