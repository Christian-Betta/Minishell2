/*
** epur_str.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:11:50 2017 Christian Betta
** Last update Tue May  9 14:11:51 2017 Christian Betta
*/

#include "my.h"

int     comble1(char *str, int a)
{
  while ((str[a] == ' ' && str[a + 1] == ' ') ||
         (str[a] == '\t' && str[a + 1] == '\t'))
    a = a + 1;
  if (str[a] == '\t')
    str[a] = ' ';
  return (a);
}

char    *epur_str(char *str)
{
  int   i;
  int   b;
  char  *tab;

  i = (b = 0);
  if (!(tab = malloc(sizeof(char) * (my_strlen(str) + 3))))
    return (NULL);
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    i = i + 1;
  if (str[i] != '\0')
    while (str[i + 1])
      {
        if (str[i] == ' ' || str[i] == '\t')
          i = comble1(str, i);
        if (str[i + 1] != '\0')
          tab[b++] = str[i++];
      }
  tab[b++] = str[i];
  if (str[i] == ' ' || str[i] == '\t')
    tab[b - 1] = '\0';
  else
    tab[b] = '\0';
  return(tab);
}
