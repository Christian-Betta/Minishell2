/*
** my_putchar.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:13:50 2017 Christian Betta
** Last update Tue May  9 14:13:51 2017 Christian Betta
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
