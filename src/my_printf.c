/*
** my_printf.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:13:33 2017 Christian Betta
** Last update Tue May  9 14:13:37 2017 Christian Betta
*/

#include "my.h"

void	fonctions(int i, va_list ap)
{
  void (*fonctions[10])(va_list);

  fonctions[0] = &flag_pour;
  fonctions[1] = &flag_i;
  fonctions[2] = &flag_i;
  fonctions[3] = &flag_c;
  fonctions[4] = &flag_s;
  fonctions[5] = &flag_o;
  fonctions[6] = &flag_u;
  fonctions[7] = &flag_X;
  fonctions[8] = &flag_b;
  fonctions[9] = &flag_p;
  (*fonctions[i])(ap);
}

char	tableau(char z, int e)
{
  char	str[10];
  int	i;

  str[0] = '%';
  str[1] = 'i';
  str[2] = 'd';
  str[3] = 'c';
  str[4] = 's';
  str[5] = 'o';
  str[6] = 'u';
  str[7] = 'X';
  str[8] = 'b';
  str[9] = 'p';
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == z)
	  e = i;
      i = i + 1;
    }
  return (e);
}

int	printf2(char *s, int i, int t, va_list ap)
{
  while (s[i] != '\0')
    {
      if (s[i] != '%')
	{
	  my_putchar(s[i]);
	  i = i + 1;
	}
      else
	{
	  if (s[i + 1] != '%')
	    {
	      t = tableau(s[i + 1], 0);
	      fonctions(t, ap);
	      i = i + 2;
	    }
	  else
	    {
	      my_putchar('%');
	      i = i + 2;
	    }
	}
    }
  return (0);
}

void     my_printf(char *s, ...)
{
  va_list       ap;
  int   i;
  int	t;

  i = (t = 0);
  va_start(ap, s);
  printf2(s, i, t, ap);
  va_end(ap);
}
