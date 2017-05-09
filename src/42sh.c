/*
** 42sh.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:10:18 2017 Christian Betta
** Last update Tue May  9 14:10:19 2017 Christian Betta
*/

#include "my.h"

int	shell(t_stc *stc)
{
  while ((stc->s = get_next_line(0)))
    {
      if ((stc->rtn = check_divers(stc)) == 0 || stc->rtn == 1);
      else if ((stc->rtn = check_cd(stc)) == 0 || stc->rtn == 1)
	change_pwd();
      else if ((stc->rtn = check_pipe(stc)) == 0 || stc->rtn == 1);
      else if ((stc->rtn = check_env(stc)) == 0 || stc->rtn == 1);
      else if (stc->rtn == 84)
	stc->rtn = verif(stc);
      write(1, "$>", 2);
    }
  return (stc->rtn);
}

int	main()
{
  t_stc	*stc;
  char	*tab;

  if (!(stc = malloc(sizeof(t_stc))))
    return (84);
  stc->old = NULL;
  tab = find_path();
  stc->path = my_str_to_wordtab(tab, ':');
  stc->home = find_home();
  stc->cd_m = 0;
  stc->old = getcwd(stc->old, 256);
  write(1, "$>", 2);
  shell(stc);
  return (stc->rtn);
}
