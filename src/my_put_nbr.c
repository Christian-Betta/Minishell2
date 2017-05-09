/*
** my_put_nbr.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:14:33 2017 Christian Betta
** Last update Tue May  9 14:14:34 2017 Christian Betta
*/

#include "my.h"

void     my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr((nb / 10) * -1);
      my_putchar(((nb % 10) * -1) + '0');
    }
  else
    {
      if (nb >= 10)
	my_put_nbr(nb / 10);
      my_putchar((nb % 10) + '0');
    }
}
