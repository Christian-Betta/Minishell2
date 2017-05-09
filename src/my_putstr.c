/*
** my_putstr.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:14:49 2017 Christian Betta
** Last update Tue May  9 14:14:50 2017 Christian Betta
*/

#include "my.h"

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
