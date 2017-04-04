/*
** my_strcmp.c for  in /home/christian.betta/Minishell/PSU_2016_minishell1
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue Mar 28 15:10:32 2017 Christian Betta
** Last update Tue Apr  4 11:25:23 2017 Christian Betta
*/

#include "my.h"

/*int     my_strncmp(char *s1, char *s2, int i)
{
  int   k;

  k = 0;
  while (s1[k] == s2[k] && s1[k] && s2[k] && k < i)
    {
      k++;
    }
  if ((s1[k] == '\0' && s2[k] == '\0') || k == i)
    {
      return (0);
    }
  else if (s1[k] > s2[k])
    {
      return (1);
    }
  else
    {
      return (-1);
    }
    }*/

/*int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (1);
      i = i + 1;
    }
  i++;
  if (s2[i] == '\0')
    return (0);
  return (1);
}*/

int	my_strncmp(char *s1, char *s2)
{
  int	result;
  int	i;

  result = 0;
  i = 0;
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
