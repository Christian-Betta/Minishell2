/*
** epur_pv.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:11:42 2017 Christian Betta
** Last update Tue May  9 14:11:43 2017 Christian Betta
*/

#include "my.h"

void    comble(char *tab, int j)
{
  j = j - 1;
  while (tab[j] == ';')
    {
      tab[j] = '\0';
      j = j - 1;
    }
}

char    *epur_pv(char *str)
{
  int   i;
  int   j;
  char  *tab;

  i = (j = 0);
  tab = malloc(sizeof(char) * my_strlen(str));
  while (str[i++] == ';');
  while (str[i])
    {
      if ((str[i] == ';' && str[i + 1] == ';'))
        i = i + 1;
      else
	tab[j++] = str[i++];
      tab[j] = '\0';
    }
  comble(tab, j);
  return (tab);
}
