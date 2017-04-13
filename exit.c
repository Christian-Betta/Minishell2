/*
** shell1.c for  in /home/christian.betta/Minishell/PSU_2016_minishell1
**
** Made by Christian Betta
** Login   <christian.betta@epitech.net>
**
** Started on  Thu Mar 23 19:11:56 2017 Christian Betta
** Last update Thu Apr 13 10:57:16 2017 Christian Betta
*/

#include"my.h"

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
