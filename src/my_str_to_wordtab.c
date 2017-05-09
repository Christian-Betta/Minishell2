/*
** my_str_to_wordtab.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:16:03 2017 Christian Betta
** Last update Tue May  9 14:16:03 2017 Christian Betta
*/

#include "my.h"

void    prog(char *tab, char **dest, char ch)
{
  int   a;
  int   b;
  int   i;

  i = (a = (b = 0));
  while (tab[i] != '\0')
    {
      if (tab[i] != ch)
	dest[a][b++] = tab[i];
      else
	{
	  dest[a++][b] = '\0';
	  b = 0;
	}
      i = i + 1;
    }
  dest[a++][b] = '\0';
  dest[a] = NULL;
}

int     find_nb_arg(char *tab, char ch)
{
  int   i;
  int   nb;

  i = 0;
  nb = 2;
  while (tab[i] != '\0')
    if (tab[i++] == ch)
      nb = nb + 1;
  return (nb);
}

char    **my_str_to_wordtab(char *str, char ch)
{
  int   i;
  char  **dest;
  int   x;
  char	*tab;

  i = 0;
  x = find_nb_arg(str, ch);
  if (!(dest = malloc(sizeof(char *) * x)))
    return (84);
  while (i <= x)
    if (!(dest[i++] = malloc(sizeof(char) * (my_strlen(str) + 1))))
      return (84);
  tab = epurstr(str);
  prog(tab, dest, ch);
  return (dest);
}
