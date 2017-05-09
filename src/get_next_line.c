/*
** get_next_line.c for  in /home/christian.betta/All_Job/Minishell/PSU_2016_minishell2/src
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Tue May  9 14:12:34 2017 Christian Betta
** Last update Tue May  9 14:12:35 2017 Christian Betta
*/

#include "my.h"
# define READ_SIZE 1024

char            *get_next_line2(const int fd, t_gnl gnl)
{
  static        int i = 1;
  static char   buffer[READ_SIZE];
  static int    readable = 1;

  gnl.j = 0;
  gnl.line = malloc(sizeof(char) * 100000);
  while (readable > 0)
    {
      if (i >= readable)
	{
          readable = read(fd, buffer, READ_SIZE);
          i = 0;
	}
      while (buffer[i] != '\n' && i < readable -1)
	gnl.line[gnl.j++] = buffer[i++];
      if (buffer[i] == '\n')
	{
          gnl.line[gnl.j] = '\0';
          i = i + 1;
          return (gnl.line);
	}
    }
  return (NULL);
}

char    *get_next_line(const int fd)
{
  t_gnl	gnl;

  return (get_next_line2(fd, gnl));
}
