/*
** concatener.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:11:31 2017 Christian Betta
** Last update Tue May  9 14:11:31 2017 Christian Betta
*/

#include "my.h"

char    *concatener(t_stc *stc, int a, char ch)
{
  int   b;
  int   c;

  b = (c = 0);
  if (!(stc->concat = malloc(sizeof(char) * (my_strlen(stc->path[a]) +
					     my_strlen(stc->concat2[0]) + 2))))
    return (NULL);
  while (stc->path[a][b] != '\0')
    {
      stc->concat[b] = stc->path[a][b];
      b = b + 1;
    }
  stc->concat[b] = ch;
  b = b + 1;
  while (stc->concat2[0][c] != '\0')
    {
      if (stc->concat2[0] == NULL || stc->concat2[0] == '\0')
	return (NULL);
      stc->concat[b++] = stc->concat2[0][c++];
    }
  stc->concat[b] = '\0';
  return (stc->concat);
}
