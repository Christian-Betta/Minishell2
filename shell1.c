/*
1;2802;0c** shell1.c for  in /home/christian.betta/Minishell/PSU_2016_minishell1
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 19:11:56 2017 Christian Betta
** Last update Tue Apr  4 15:18:17 2017 Christian Betta
*/

#include "my.h"

void            control_c()
{
  my_putstr("\n");
  my_putstr("> ");
}

void            my_exit(char *buffer)
{
  if (my_strncmp("exit", buffer) == 0)
    {
      my_putstr("exit\n");
      exit(0);
    }
}

int             exec_all(t_mini ex, char **envp)
{
  int           a;

  a = 0;
  if ((execve(ex.str_cat, ex.argument, envp)) == -1)
    ++a;
  else
    return (0);
}

char	**copy_env(char **envp)
{
  int           i;
  char          **tabl;

  i = 0;
  while (envp[i])
    {
      if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
          envp[i][2] == 'T' && envp[i][3] == 'H')
        tabl = my_str_to_wordtab(envp[i], ':');
      i++;
    }
  return (tabl);
}

void	test_exit(t_mini c, char **envp)
{
  while (42)
    {
      c.buffer = get_next_line(0);
      if (c.buffer == NULL)
	{
	  if (isatty(0))
	    my_putstr("exit\n");
	  exit(0);
	}
      if (my_strncmp("exit", c.buffer) != 0)
	shell(c, envp);
      else
	my_exit(c.buffer);
    }
}

void            shell(t_mini c, char **envp)
{
  int           a;

  c.argument = my_str_to_wordtab(c.buffer, ' ');
  if (my_strncmp("cd ..", c.buffer) == 0 || my_strncmp("cd", c.buffer) == 0)
    cd(c);
  else if (c.buffer[0] == '.' && c.buffer[1] == '/')
    my_exec_prog(c);
  else if (chemin(c.buffer) == 1)
    my_exec_prog(c);
  else if (my_strncmp("PATH", c.buffer) == 0)
    {
      my_put_str_tab_path(c.array);
      my_putchar('\n');
    }
  else if ((c.pid = fork()) == -1)
    exit (0);
  else
    my_pid(c, a, envp);
  my_putstr("> ");
}
