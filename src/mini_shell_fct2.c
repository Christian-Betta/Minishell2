/*
1;2802;0c** mini_shell_fct2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Mon Apr 10 14:32:39 2017 Christian Betta
** Last update Tue Apr 11 11:14:02 2017 Christian Betta
*/

#include "include/my.h"

int     verif_en(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '.' && str[i + 1] == '/')
        return (1);
      i++;
    }
  return (0);
}

void	multi_str(char *str1, char *str2)
{
  my_putstr(str1);
  my_putchar(' ');
  my_putstr(str2);
}

char	*recup_home(char **tabl)
{
  int	a;

  a = 0;
  while (tabl[a])
    {
      if (tabl[a][0] == 'H' && tabl[a][1] == 'O' &&
	  tabl[a][2] == 'M' && tabl[a][3] == 'E' && tabl[a][4] == '=')
	return (tabl[a]);
      a++;
    }
  return (NULL);
}

int	pos_home(char ** tabl)
{
  int   a;

  a = 0;
  while (tabl[a])
    {
      if (tabl[a][0] == 'H' && tabl[a][0] == 'O' &&
	  tabl[a][0] == 'M' && tabl[a][0] == 'E' && tabl[a][0] == '=')
	return (a);
      a++;
    }
  return (0);
}

char	*mon_home(char **envp)
{
  char	*str;
  char	*dest;
  int	i;
  int	b;

  str = malloc(sizeof(char) * 100);
  dest = malloc(sizeof(char) * 100);
  b = 0;
  str = recup_home(envp);
  while (str[i] != '=')
    i++;
  i++;
  while (str[i])
    {
      dest[b] = str[i];
      i++;
      b++;
    }
  return (dest);
}
