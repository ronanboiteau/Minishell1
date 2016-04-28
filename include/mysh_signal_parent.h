/*
** mysh_signal_parent.h for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jan 19 00:27:52 2016 Ronan Boiteau
** Last update Wed Apr  6 19:00:41 2016 Ronan Boiteau
*/

#ifndef MYSH_SIGNAL_PARENT_H_
# define MYSH_SIGNAL_PARENT_H_

# define SETSIG (0)
# define GETSIG (1)
# define SIGINT_IGNORE (0)
# define SIGINT_REGULAR (1)

int		signal_handler(char mode, int sigint_behavior);

#endif /* !MYSH_SIGNAL_PARENT_H_ */
