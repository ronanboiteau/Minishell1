/*
** mysh_exec_path.h for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Jan 24 18:06:07 2016 Ronan Boiteau
** Last update Wed Apr  6 19:02:31 2016 Ronan Boiteau
*/

#ifndef MYSH_EXEC_PATH_H_
# define MYSH_EXEC_PATH_H_

char		*get_exec_full_path(char *input, char **path);
t_uchar		chck_exec_path(char *exec_path, char **argv);

#endif /* !MYSH_EXEC_PATH_H_ */
