/*
** mini_shell_fct3.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Apr 13 18:05:48 2017 Christian Betta
** Last update Thu Apr 13 18:36:42 2017 Christian Betta
*/

char	*my_epure_3(char *str)
{
  char	*dest;
  int	i;
  int	a;

  i = 0;
  a = my_strlen(str) - 1;
  if (str[i] == ' ')
    {
      while (str[i] == ' ')
	i++;
    }
  if (dest[a] == ' ')
    while (dest[a] == ' ')
      {
	dest[a] == '\0';
	a--;
      }
  return (dest);
}
