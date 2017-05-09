/*
** my_puterror.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:14:04 2017 Christian Betta
** Last update Tue May  9 14:14:04 2017 Christian Betta
*/

#include "my.h"

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit(1);
}
