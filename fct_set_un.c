/*
** set_unset.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Wed Apr 12 10:31:53 2017 Christian Betta
** Last update Wed Apr 12 16:29:42 2017 Christian Betta
*/

int	find_name(char **envp, char *str)
{
  int	i;

  i = 0;
  while (envp[i])
    {
      if (envp[i][0] == str[0] && envp[i][1] == str[1]
	  && envp[i][2] == str[2] && envp[i][3] == str[3])
	return (i);
      i++;
    }
  return (0);
}

int	find_env(char **tabl)
{
  int	i;

  i = 0;
  while (tabl[i])
    i++;
  return (i);
}
