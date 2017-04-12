/*
** my_put_nbr.c for my_put_nbr in /home/mayans_k/Workspace/CPool_Day03
**
** Made by Kilian Mayans
** Login   <mayans_k@epitech.net>
**
** Started on  Thu Oct  6 08:09:53 2016 Kilian Mayans
** Last update Fri Mar 17 15:07:47 2017 Christian Betta
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
