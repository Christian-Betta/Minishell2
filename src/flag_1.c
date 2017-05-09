/*
** flag_1.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:12:12 2017 Christian Betta
** Last update Tue May  9 14:12:13 2017 Christian Betta
*/

#include "my.h"

void	flag_pour()
{
  my_putchar('%');
}

void    flag_s(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void    flag_i(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	flag_c(va_list ap)
{
  my_putchar(va_arg(ap, int));
}
