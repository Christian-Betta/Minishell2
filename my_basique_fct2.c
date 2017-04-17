/*
** my_basique_fct2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Mon Apr 10 13:26:48 2017 Christian Betta
** Last update Mon Apr 17 13:44:52 2017 Christian Betta
*/

#include"my.h"

char    *my_epure(char *src)
{
  int   size;

  size = my_strlen(src) - 2;
  size = size + 2;
  while ((src[size] == '\t' || src[size] == ' ')
	 && src[size] != '\0')
    {
      src[size] = '\0';
      size = size - 2;
      size++;
    }
  while ((*src == ' ' || *src == '\t' ) && *src != '\0')
    src = src + 1;
  return (src);
}


/*char	*my_epure(char *str)
{
  int	i;
  int	size;
  int	a;
  char	*dest;

  dest = malloc(sizeof(char) * 100);
  i = (a = 0);
  if (str == NULL)
    return (NULL);
  while (str[i] == ' ')
    i++;
  while (str[i])
    {
      if (str[i] == '\t')
	i++;
      if (str[i] == ' ' && str[i + 1] == ' ')
	{
	  while (str[i] == ' ' && str[i + 1] == ' ')
	    i++;
	  dest[a] = ' ';
	}
      if (str[i] == ' ' && str[i + 1] == '\0')
	dest[a] = '\0';
      else
	{
	  dest[a] = str[i];
	  i++;
	  a++;
	}
      return (dest);
    }
  return (NULL);
}*/

int     my_strncmp(char *s1, char *s2)
{
  int   result;
  int   i;

  result = 0;
  i = 0;
  if (s1 && s2)
    {
      while (s1[i] != '\0' && s2[i] != '\0' && !result)
	{
	  result = s1[i] - s2[i];
	  i++;
	}
      if (s1[i] == '\0' && s2[i] != '\0')
	return (-100);
      else if (s2[i] == '\0' && s1[i] != '\0')
	return (100);
      return (result);
    }
  else
    return (1);
}
