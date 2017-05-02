/*
1;2802;0c** shell2.c for  in /home/christian.betta/Minishell/PSU_2016_minishell1
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 19:12:02 2017 Christian Betta
** Last update Tue May  2 15:36:54 2017 Christian Betta
*/

#include "my.h"

void	my_pid(t_mini *c, char **envp)
{
  t_mypid	*p;

  p = (t_mypid*)malloc(sizeof(*p));
  p->fus = malloc(sizeof(char) * 200);
  p->str = malloc(sizeof(char) * 200);
  getcwd(p->str, 200);
  p->fus = mystrcat("PWD=", p->str + 1);
  envp[pos(envp)] = p->fus;
  if (c->mypid == 0 && my_strncmp("env", c->buffer) != 0)
    {
      p->a = 0;
      while (c->array[p->a])
	{
	  c->str_cat = mystrcat(c->array[p->a], c->argument[0]);
	  exec_all(c);
	  p->a++;
	}
      if (c->array[p->a] == 0 && my_strncmp("cd", c->buffer) == -1 ||
	  my_strncmp("cd", c->buffer))
	{
	  my_putstr(c->buffer);
	  my_putstr(": Command not found.\n");
	  c->ret= 1;
	  exit(1);
	}
      c->ret = 1;
    }
}

void	cd(t_mini *cd, char **envp)
{
  char **tabl;
  int	a;

  cd->buffer = my_epure(cd->buffer);
  tabl = malloc(sizeof(char *) * 10);
  tabl = my_str_to_wordtab(cd->buffer,' ');
  if ((my_strncmp("cd", tabl[0])) == 0)
    {
      if (tabl[1] == NULL)
	chdir(mon_home(envp));
      else
	{
	  tabl[1] = my_epure_2(tabl[1]);
	  if (chdir(tabl[1]) == 0)
	    a++;
	  else
	    {
	      my_putstr(tabl[1]);
	      my_putstr(": No such file or directory.\n");
	      cd->ret = 1;
	    }
	}
    }
  free(tabl);
}

  int	pos(char **tabl)
  {
    int   i;
    int   b;

    i = 0;
    while (tabl[i])
      {
	if (tabl[i][0] == 'P' && tabl[i][1] == 'W'
	    && tabl[i][2] == 'D' && tabl[i][3] == '=')
	  return (i);
	i++;
      }
    return (0);
  }

  char    **copy_env(char **envp)
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

  void	set_env(t_mini *v, char **envp)
  {
    char	**set;
    int	a;
    char	*str;
    char	*tmp;

    str = malloc(sizeof(char) * 100);
    set = malloc(sizeof(char *) * 100);
    set = my_str_to_wordtab(v->buffer, ' ');
    if (set[1] != NULL && set[2] != NULL)
      {
	if (find_name(envp, set[1]) != 0 && set[2] != NULL)
	  {
	    a = find_name(envp, set[1]);
	    str = strcat(set[1], set[2]);
	    envp[a] = str;
	  }
	else
	  {
	    a = find_env(envp);
	    envp[a] = malloc(sizeof(char) * 100);
	    str = strcat(set[1], set[2]);
	    envp[a] = str;
	  }
      }
  }
