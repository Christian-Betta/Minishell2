/*
** my_strcmp.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:15:33 2017 Christian Betta
** Last update Tue May  9 14:15:34 2017 Christian Betta
*/

#include "my.h"

int    my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (1);
      i = i + 1;
    }
  return (0);
}
