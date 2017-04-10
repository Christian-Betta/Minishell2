/*
** mini_shell_fct2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Mon Apr 10 14:32:39 2017 Christian Betta
** Last update Mon Apr 10 14:51:31 2017 Christian Betta
*/

#include "include/my.h"

int     verif_en(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '.' && str[i + 1] == '/')
        return (1);
      i++;
    }
  return (0);
}

void	multi_str(char *str1, char *str2)
{
  my_putstr(str1);
  my_putchar(' ');
  my_putstr(str2);
}
