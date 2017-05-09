/*
** flag_2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:12:18 2017 Christian Betta
** Last update Tue May  9 14:12:19 2017 Christian Betta
*/

#include "my.h"

void	flag_p(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void    flag_o(va_list ap)
{
  unsigned int  nb;

  nb = va_arg(ap, unsigned int);
  my_putnbr_base(nb, 8);
}

void    flag_u(va_list ap)
{
  unsigned int nb;

  nb = va_arg(ap, unsigned int);
  my_put_nbr(nb);
}
