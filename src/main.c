/*
** main.c for  in /home/christian.betta/minishel/Minishell1-master
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 17:27:05 2017 Christian Betta
** Last update Mon Apr 10 13:47:52 2017 Christian Betta
*/

#include "include/my.h"

int	chemin(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

void     my_exec_prog(t_mini ex, char **envp)
{
  int   pid;
  int   status;
  int   a;
  char  **command;
  int   p;
  char **tmp;

  a = 0;
  tmp = malloc(sizeof(char *) * 10000);
  tmp[0] = malloc(sizeof(char) * 10000);
  tmp[0] = ex.buffer;
  command = my_str_to_wordtab(ex.buffer, ' ');
  if (access(command[0], X_OK) == 0)
    {
      pid = fork();
      if (pid == 0)
	execve(command[0], tmp, envp);
      else if (pid > 0)
	waitpid(pid, &status, 0);
      if (status == 139)
	my_putstr("Segmentation fault (core dumped)");
      my_putchar('\n');
    }
  else
    {
      my_putstr(ex.buffer);
      my_putstr(": Command not found.\n");
    }
}

void    commande_unique(t_mini c, char **envp)
{
  int   a;

  c.argument = my_str_to_wordtab(c.buffer, ' ');
  if (my_strncmp("cd", c.argument[0]) == 0)
    cd(c);
  else if ((c.buffer[0] == '.' && c.buffer[1] == '/') || chemin(c.buffer) == 1)
    my_exec_prog(c, envp);
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

void    commande_multiple(t_mini c, char **envp)
{
  c.i = 0;
  c.nbr = nbr_comm(c.buffer);
  c.buffer = my_epure_2(c.buffer);
  c.cmd = my_str_to_wordtab(c.buffer, ';');
  while (c.i <= c.nbr)
    {
      c.argument = my_str_to_wordtab(c.cmd[c.i], ' ');
      if (my_strncmp("cd ..", c.cmd[c.i]) == 0 ||
          my_strncmp("cd", c.cmd[c.i]) == 0)
        cd(c);
      else if ((chemin(c.cmd[c.i]) == 1) ||
	       (c.cmd[c.i][0] == '.' && c.cmd[c.i][1] == '/'))
	my_exec_prog(c, envp);
      else if (my_strncmp("PATH", c.cmd[c.i]) == 0)
	{
          my_put_str_tab_path(c.array);
          my_putchar('\n');
        }
      else if ((c.pid = fork()) == -1)
	exit (0);
      else
	my_pid(c, c.a, envp);
      my_putstr("> ");
      c.i++;
    }
}

void            shell(t_mini c, char **envp)
{
  if (nbr_comm(c.buffer) == 0)
    commande_unique(c, envp);
  else
    commande_multiple(c,envp);
}

void    test_exit(t_mini c, char **envp)
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
      c.buffer = my_epure(c.buffer);
      if (my_strncmp("exit", c.buffer) != 0)
	shell(c, envp);
      else
        my_exit(c.buffer);
    }
}

int             main(int ac, char **av, char **envp)
{
  t_mini        c;

  c.my_env = malloc(sizeof(char *) * (1000000));
  c.buffer = malloc(sizeof(char) * (1000));
  c.my_env = envp;
  my_putstr("> ");
  signal(SIGINT, control_c);
  c.array = copy_env(envp);
  test_exit(c, envp);
  return (0);
}
