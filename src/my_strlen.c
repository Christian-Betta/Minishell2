/*
** my_strlen.c for my_strlen.c in /home/josselin.mabilon/CPool_Day04
**
** Made by Josselin MABILON
** Login   <josselin.mabilon@epitech.net>
**
** Started on  Fri Oct  7 17:23:55 2016 Josselin MABILON
** Last update Fri May  5 15:39:41 2017 Jojo
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++] != '\0');
  return (i);
}
