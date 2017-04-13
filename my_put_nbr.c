/*
** my_put_nbr.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Apr 13 10:58:08 2017 Christian Betta
** Last update Thu Apr 13 10:58:09 2017 Christian Betta
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  modulo = (nb % 10);
	  nb = (nb - modulo) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	{
	  my_putchar(48 + nb % 10);
	}
    }
}
