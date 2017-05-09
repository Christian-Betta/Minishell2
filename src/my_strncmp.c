/*
** my_strncmp.c for strncmp in /home/jojo/Prog_shell/Projet/PSU_2016_minishell2
** 
** Made by Jojo
** Login   <josselin.mabilon@epitech.eu>
** 
** Started on  Wed Apr 12 14:27:36 2017 Jojo
** Last update Mon Apr 24 17:26:35 2017 Jojo
*/

#include "my.h"

int	my_strncmp(char *str, char *str1, int a)
{
  int	i;

  i = 0;
  if (my_strlen(str1) != a)
    return (1);
  else
    {
      while (str[i] != '\0')
	{
	  if (str[i] == str1[i])
	    i = i + 1;
	  else
	    return (1);
	}
    }
  return (0);
}
