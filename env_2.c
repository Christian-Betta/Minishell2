/*
** env_2.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Wed Apr 12 16:30:14 2017 Christian Betta
** Last update Mon Apr 17 12:00:48 2017 Christian Betta
*/

#include "my.h"

void	un_env(t_mini c, char **envp)
{
  char	**set;
  int	a;

  set = malloc(sizeof(char *) * 100);
  set = my_str_to_wordtab(c.buffer, ' ');
  if (find_name(envp, set[1]) != 0)
    {
      a = find_name(envp, set[1]);
      envp[a] = malloc(sizeof(char) * -1);
    }
  else
    my_putstr("unset: Too few arguments.\n");
}
