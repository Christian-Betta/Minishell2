/*
** flag_3.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:12:25 2017 Christian Betta
** Last update Tue May  9 14:12:26 2017 Christian Betta
*/

#include "my.h"

void	flag_X(va_list ap)
{
  unsigned int  nb;

  nb = va_arg(ap, unsigned int);
  my_putnbr_base(nb, 16);
}

void	flag_b(va_list ap)
{
  unsigned int  nb;

  nb = va_arg(ap, unsigned int);
  my_putnbr_base(nb, 2);
}
