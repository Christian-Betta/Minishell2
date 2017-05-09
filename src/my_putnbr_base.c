/*
** my_putnbr_base.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:14:15 2017 Christian Betta
** Last update Tue May  9 14:14:15 2017 Christian Betta
*/

#include "my.h"

char	*put_zero(char *res)
{
  int	a;

  a = my_strlen(res);
  while (a != 9)
    {
      res[a] = '0';
      a = a + 1;
    }
   return (res);
}

char	*my_putnbr_base(int nb, int b)
{
  char	*res;
  int	a;

  a = 0;
  if (!(res = malloc(sizeof(char) * 8 + 1)))
    return (84);
  res[9] = '\0';
  while (nb > 1)
    {
      res[a] = (nb % b);
      if ((res[a++] > 9) || (a == -1))
	res[a] = res[a] + 55;
      else
	{
	  res[a] = res[a] + '0';
	  a = a + 1;
	}
      nb = nb / b;
    }
  if (nb == 1)
    res[a] = '1';
  put_zero(res);
  my_revstr(res);
  return (res);
}
