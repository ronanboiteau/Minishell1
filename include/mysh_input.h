/*
** mysh_input.h for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Jan 13 22:30:43 2016 Ronan Boiteau
** Last update Wed Apr  6 18:57:57 2016 Ronan Boiteau
*/

#ifndef MYSH_INPUT_H_
# define MYSH_INPUT_H_

# define GREEN "\x1B[1;32m"
# define RED "\x1B[1;31m"
# define RESET "\x1B[0m"
# define YELLOW "\x1B[1;33m"

int		get_input(t_command *command,
			  t_uchar ret,
			  char **env);

#endif /* !MYSH_INPUT_H_ */
