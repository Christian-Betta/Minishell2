/*
** my_getnbr.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:13:22 2017 Christian Betta
** Last update Tue May  9 14:13:22 2017 Christian Betta
*/

#include "my.h"

int     my_getnbr(char *av)
{
  int   i;
  int   nb;
  int   isn;

  i = (nb = (isn = 0));
  while (av[i] != '\0')
    {
      if (av[i] == '-')
	  isn = 1;
      else
	{
	  nb = nb * 10;
	  nb = nb + (av[i] - 48);
	}
      i = i + 1;
    }
  if (isn == 1)
      nb = nb * -1;
  return (nb);
}
