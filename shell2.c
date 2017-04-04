/*
1;2802;0c** shell2.c for  in /home/christian.betta/Minishell/PSU_2016_minishell1
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 19:12:02 2017 Christian Betta
** Last update Tue Apr  4 14:13:02 2017 Christian Betta
*/

#include "my.h"

void    my_pid(t_mini c, int a, char **envp)
{
  if (c.pid == 0)
    {
      a = 0;
      while (c.array[a])
        {
          c.str_cat = mystrcat(c.array[a], c.argument[0]);
          exec_all(c, envp);
          ++a;
        }
      if (c.array[a] == 0 &&
	  my_strncmp("cd", c.buffer) == -1 ||
	  my_strncmp("cd", c.buffer))
	my_putstr(c.buffer);
	my_putstr(": Command not found.\n");
      exit (84);
    }
  else
    wait(&c.status);
}

void	my_put_str_tab(char **tabl)
{
  int	a;

  a = 0;
  while (tabl[a])
    {
      my_putstr(tabl[a]);
      my_putchar('\n');
      a++;
    }
}
