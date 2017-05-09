/*
** my_setenv.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:15:19 2017 Christian Betta
** Last update Tue May  9 14:15:20 2017 Christian Betta
*/

#include "my.h"

char    *put_in_char(t_stc *stc, int b)
{
  int   i;
  int   a;
  char  *tab;

  i = (a = 0);
  if (!(tab = malloc(sizeof(char) * my_strlen(stc->s))))
      return (NULL);
  while (stc->s2[1][i] != '\0')
    {
      tab[a] = stc->s2[1][i];
      i = i + 1;
      a = a + 1;
    }
  i = 0;
  tab[a] = '=';
  a = a + 1;
  if (b == 2)
    tab[a] = '\0';
  else
    put_in_char2(stc->s2, i, tab, a);
  return (tab);
}

int	my_setenv3(t_stc *stc, int i)
{
  extern char	**environ;
  int           a;
  int           b;
  int           c;
  char          *tab;

  a = (b = (c = 0));
  tab = put_in_char(stc, i);
  while (environ[a])
    a = a + 1;
  if (!(environ[a] = malloc(sizeof(char) * 512)))
    return (84);
  while (tab[b] != '\0')
    {
      environ[a][c] = tab[b];
      c = c + 1;
      b = b + 1;
    }
  environ[a][c] = '\0';
  if (!(environ[a + 1] = malloc(sizeof(char) * 512)))
    return (84);
  environ[a + 1] = NULL;
  return (0);
}

int	my_setenv2(t_stc *stc)
{
  int   i;

  i = find_nb_arg(stc->s, ' ');
  if (i > 3)
    {
      my_printf("%s: Too many arguments.\n", stc->s2[0]);
      return (1);
    }
  else
    {
      my_setenv3(stc, i);
      return (0);
    }
}

int	check_alpha(t_stc *stc, int i)
{
  if ((stc->s2[1][0] >= 'a' && stc->s2[1][0] <= 'z') ||
      (stc->s2[1][0] >= 'A' && stc->s2[1][0] <= 'Z') ||
      stc->s2[1][i] == '_')
    {
      while (stc->s2[1][i] != '\0')
        {
          if ((stc->s2[1][i] >= 'a' && stc->s2[1][i] <= 'z') ||
	      (stc->s2[1][i] >= 'A' && stc->s2[1][i] <= 'Z') ||
              (stc->s2[1][i] >= '0' && stc->s2[1][i] <= '9') ||
	      stc->s2[1][i] == '_')
            i = i + 1;
          else
            {
              my_printf("%s: Variable name must contain ", stc->s2[0]);
              my_putstr("alphanumeric characters.\n");
              return (1);
            }
        }
    }
  else
    {
      my_printf("%s: Variable name must begin ", stc->s2[0]);
      my_printf("with a letter.\n");
      return (1);
    }
  return (0);
}

int	my_setenv(t_stc *stc)
{
  int	i;

  i = 0;
  stc->s2 = my_str_to_wordtab(stc->s, ' ');
  if (check_alpha(stc, i) == 1)
    return (1);
  else
    {
      if (my_setenv2(stc) == 0)
	return (0);
      else
	return (1);
    }
  return (0);
}
