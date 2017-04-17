/*
** mini_shell_fct3.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Apr 13 18:05:48 2017 Christian Betta
** Last update Mon Apr 17 13:30:18 2017 Christian Betta
*/

#include "my.h"

char	*my_epure_2_arg(char *str)
{
  int   i;
  int   a;
  char  *dest;

  a = 0;
  i = 0;
  dest = malloc(sizeof(char) * 1000);
  if (str != NULL)
    {
      while (str[i])
	{
	  if (str[i] == ' ' || str[i] == '\t')
	    i++;
	  else if (str[i] == '-')
	    {
	      dest[a] = ' ';
	      dest[a + 1] = '-';
	      a = a + 2;
	      i++;
	    }
	  else
	    {
	      dest[a] = str[i];
	      a++;
	      i++;
	    }
        }
      dest[a] = 0;
      return (dest);
    }
  else
    return (NULL);
}
