/*
** main.c for  in /home/christian.betta/minishel/Minishell1-master
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 17:27:05 2017 Christian Betta
** Last update Tue May  2 15:43:47 2017 Christian Betta
*/

#include"my.h"

void    commande_unique(t_mini *c, char **envp)
{
  int	stat;

  c->argument = my_str_to_wordtab(c->buffer, ' ');
  if (my_strncmp("cd", c->argument[0]) == 0)
    cd(c, envp);
  else if ((c->buffer[0] == '.' && c->buffer[1] == '/'))// || (chemin(c.buffer) == 1))
    my_exec_prog(c, envp);
  else if (my_strncmp("PATH", c->buffer) == 0)
    {
      my_put_str_tab_path(c->array);
     my_putchar('\n');
    }
  else if ((c->mypid = fork()) == -1)
    exit (c->ret);
  else
    my_pid(c, envp);
}

void    commande_multiple(t_mini *c, char **envp)
{
  c->i = 0;
  c->buffer = my_epure_2_arg(c->buffer);
  c->nbr = nbr_comm(c->buffer);
  c->cmd = my_str_to_wordtab(c->buffer, ';');
  while (c->i <= c->nbr)
    {
      c->argument = my_str_to_wordtab(c->cmd[c->i], ' ');
      c->cmd[c->i] = my_epure_2(c->cmd[c->i]);
      if (my_strncmp("cd ..", c->cmd[c->i]) == 0 ||
          my_strncmp("cd", c->cmd[c->i]) == 0)
        cd(c, envp);
      else if ((c->cmd[c->i][0] == '.' && c->cmd[c->i][1] == '/'))
	       //	       || (chemin(c.buffer) == 1))
	my_exec_prog(c, envp);
      else if (my_strncmp("PATH", c->cmd[c->i]) == 0)
	{
          my_put_str_tab_path(c->array);
          my_putchar('\n');
        }
      else if ((c->mypid = fork()) == -1)
	exit (0);
      else
	my_pid(c, envp);
      c->i++;
    }
}

void            shell(t_mini *c, char **envp)
{
  if (nbr_pipe(c->buffer) != 0)
    c->buffer = epure_pipe(c->buffer);
  if (nbr_comm(c->buffer) == 0)
    commande_unique(c, envp);
  else
    commande_multiple(c,envp);
}

void    test_exit(t_mini *c, char **envp)
{
  while (42)
    {
      if (isatty(0))
	my_putstr("> ");
      c->buffer = get_next_line(0);
      if (c->buffer == NULL)
        {
	  if (isatty(0))
            my_putstr("exit\n");
          exit(c->ret);
        }
      c->buffer = my_epure(c->buffer);
      if (c->buffer[0] == 'e' && c->buffer[1] == 'n' && c->buffer[2] == 'v')
	my_put_str_tab(envp);
      else if (c->buffer[0] == 'e' && c->buffer[1] == 'x'
	  && c->buffer[2] == 'i' && c->buffer[3] == 't' && c->buffer[4] == 't')
	{
	  my_putstr("exitt: Command not found.\n");
	  c->ret = 1;
	}
      else if (c->buffer[0] == 's' && c->buffer[1] == 'e' && c->buffer[2] == 't')
	set_env(c, envp);
      else if (c->buffer[0] == 'u' && c->buffer[1] == 'n'
	       && c->buffer[2] == 's' && c->buffer[3] == 'e' && c->buffer[4] == 't')
	un_env(c, envp);
      else if (my_strncmp("exit", c->buffer) != 0)
	shell(c, envp);
      else
        my_exit(c->buffer);
    }
}

int	main(int ac, char **av, char **envp)
{
  t_mini	*c;

  c = (t_mini*)malloc(sizeof(*c));
  c->my_env = malloc(sizeof(char *) * (1000000));
  c->buffer = malloc(sizeof(char) * (1000));
  c->my_env = envp;
  signal(SIGINT, control_c);
  c->array = copy_env(envp);
  test_exit(c, envp);
  free(c->my_env);
  free(c->buffer);
  return (c->ret);
}
