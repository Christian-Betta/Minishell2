/*
** epur_str.c for epur_str.c in /home/hugo.varloud/PSU_2016_minishell2/srcs
**
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
**
** Started on  Wed Mar 22 15:29:18 2017 hugo varloud
** Last update Thu Apr 13 18:24:32 2017 Christian Betta
*/

char    *epur_str(char *str)
{
  int   i;
  char  *res;
  int   a;

  a = 0;
  res = malloc(sizeof(char) * my_strlen(str) + 3);
  i = 0;
  if (str[i] == ' ')
    {
      while (str[i] == ' ' && str[i] != '\0')
	i = i + 1;
    }
  if (str[i] != '\0')
    {
      while (str[i + 1])
	{
	  if (str[i] == ' ')
	    while (str[i] == ' ' && str[i + 1] == ' ')
	      i = i + 1;
	  if (str[i + 1] != '\0')
	    res[a] = str[i];
	  a = a + 1;
	  i = i + 1;
	}
    }
  res[a] = str[i];
  a = a + 1;
  if (str[i] == ' ')
    res[a - 1] = '\0';
  else
    res[a] = '\0';
  return(res);
}
