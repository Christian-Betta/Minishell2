/*
** pv.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:16:29 2017 Christian Betta
** Last update Tue May  9 14:16:30 2017 Christian Betta
*/

#include "my.h"

int     check_db_pv(char *s)
{
  int   i;

  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] == ';' && s[i + 1] == ';')
        return (0);
      i = i + 1;
    }
  return (84);
}

int     check_pv(char *s)
{
  int   i;

  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] == ';')
	return (0);
      i = i + 1;
    }
  return (84);
}

int	pv2(t_stc *stc)
{
  int   a;
  int   i;

  i = 0;
  a = find_nb_arg(stc->s, ';');
  stc->s2 = my_str_to_wordtab(stc->s, ';');
  while (i < a)
    {
      stc->concat2 = my_str_to_wordtab(stc->s2[i], ' ');
      if (check_access(stc) == 0)
        stc->rtn = my_exec_fonctions(stc);
      else
	{
	  my_printf("%s: Command not found.\n", stc->concat2[0]);
	  stc->rtn = 1;
	}
      i = i + 1;
    }
  return (stc->rtn);

}

int	pv(t_stc *stc)
{
  char	*str;

  if (check_db_pv(stc->s) == 0)
    {
      str = epur_pv(stc->s);
      stc->s = str;
    }
  stc->rtn = pv2(stc);
  return (stc->rtn);
}
