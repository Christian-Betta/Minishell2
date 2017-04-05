/*
** my_strcmp.c for  in /home/christian.betta/Minishell/PSU_2016_minishell1
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue Mar 28 15:10:32 2017 Christian Betta
** Last update Wed Apr  5 16:40:44 2017 Christian Betta
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2)
{
  int	result;
  int	i;

  result = 0;
  i = 0;
  if (s1 && s2)
    {
      while (s1[i] != '\0' && s2[i] != '\0' && !result)
	{
	  result = s1[i] - s2[i];
	  i++;
	}
      if (s1[i] == '\0' && s2[i] != '\0')
	return (-100);
      else if (s2[i] == '\0' && s1[i] != '\0')
	return (100);
      return (result);
    }
  else
    return (1);
}
