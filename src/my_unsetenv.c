/*
** my_unsetenv.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:16:14 2017 Christian Betta
** Last update Tue May  9 14:16:14 2017 Christian Betta
*/

#include "my.h"

int     put_in_char2(char **s2, int i, char *tab, int a)
{
  while (s2[2][i] != '\0')
    {
      tab[a] = s2[2][i];
      i = i + 1;
      a = a + 1;
    }
  tab[a] = '\0';
  return (0);
}

int	my_unsetenv2(t_stc *stc)
{
  extern char	**environ;
  int	i;
  int	a;

  i = 0;
  a = 1;
  while (stc->s2[a] != NULL)
    {
      i = 0;
      while (environ[i])
        {
          if (my_strcmp(stc->s2[a], environ[i]) == 0)
            {
              while (environ[i + 1] != NULL)
		{
                  environ[i] = environ[i + 1];
                  i = i + 1;
                }
              environ[i] = NULL;
            }
          i = i + 1;
	}
      a = a + 1;
    }
  return (0);
}

int	my_unsetenv(t_stc *stc)
{
  stc->s2 = my_str_to_wordtab(stc->s, ' ');
  my_unsetenv2(stc);
  return (0);
}
