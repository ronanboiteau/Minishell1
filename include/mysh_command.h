/*
** mysh_command.h for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Jan 14 23:09:42 2016 Ronan Boiteau
** Last update Mon Jan 18 15:57:24 2016 Ronan Boiteau
*/

#ifndef MYSH_COMMAND_H_
# define MYSH_COMMAND_H_

typedef struct	s_command
{
  char		**argv;
  char		**argv_tmp;
  char		interactive;
}		t_command;

#endif /* !MYSH_COMMAND_H_ */
