/*
** my_str_to_wordtab.c for  in /home/christian.betta/minishel/Minishell1-master
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 17:27:24 2017 Christian Betta
** Last update Mon Apr 10 13:44:49 2017 Christian Betta
*/

#include "include/my.h"

int     count_word(char *str, char carac)
{
  int   a;
  int   b;

  a = 0;
  b = 0;
  while (str[a] != '\0' && str[a] != '\n')
    {
      if (str[a] == carac && str[a + 1] != '\0')
        b++;
      a++;
    }
  return (b);
}

int     count_char(char *str, char carac)
{
  int   i;

  i = 0;
  while ((str[i] != carac) && (str[i] != '\0') && (str[i] != '\n'))
    i++;
  i += 1;
  return (i);
}

void    init_var(t_var *init)
{
  init->i = 0;
  init->a = 0;
  init->b = 0;
}

char    **my_str_to_wordtab(char *str, char car)
{
  char  **tabl;
  t_var c;

  init_var(&c);
  tabl = malloc(sizeof(*tabl) * ((count_word(str, car) + 2)));
  if (tabl == NULL)
    exit (0);
  while (str[c.i] != '\n' && str[c.i] != '\0')
    {
      if (str[c.i] == car || str[c.i] == '\n')
        {
          while (str[c.i] == car)
            c.i++;
          c.a = c.a + 1;
          c.b = 0;
        }
      tabl[c.a] = malloc(sizeof(**tabl) * ((count_char(str + c.i, car) + 1)));
      if (tabl[c.a] == NULL)
        exit (0);
      while ((str[c.i] != car)  && (str[c.i] != '\n') && (str[c.i] != '\0'))
        tabl[c.a][c.b++] = str[c.i++];
      tabl[c.a][c.b] = '\0';
    }
  tabl[c.a + 1] = 0;
  return (tabl);
}
