/*
** mysh_signal_child.h for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jan 19 00:33:08 2016 Ronan Boiteau
** Last update Wed Apr  6 19:00:37 2016 Ronan Boiteau
*/

#ifndef MYSH_SIGNAL_CHILD_H_
# define MYSH_SIGNAL_CHILD_H_

# define SIGNALS_CHILD (49)

typedef struct	s_signal_ptr
{
  int		signal;
  char		*err;
}		t_signal_ptr;

void		alloc_sig_handler(t_signal_ptr **sig_handler);
void		free_sig_handler(t_signal_ptr **sig_handler);
void		init_sig_handler(t_signal_ptr **sig_handler);

#endif /* !MYSH_SIGNAL_CHILD_H_ */
