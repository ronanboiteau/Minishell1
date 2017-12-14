#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "mysh_builtins.h"
#include "mysh_exec_path.h"
#include "mysh_run.h"
#include "mysh_signal_child.h"
#include "mysh_signal_parent.h"

static void	parent_exec(pid_t pid, int *status)
{
  t_signal_ptr	**sig_handler;

  signal_handler(SETSIG, SIGINT_IGNORE);
  waitpid(pid, status, WUNTRACED);
  if (WIFSIGNALED(*status))
    {
      if ((sig_handler = malloc(sizeof(t_signal_ptr *) * (SIGNALS_CHILD)))
	  == NULL)
	my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
      alloc_sig_handler(sig_handler);
      init_sig_handler(sig_handler);
      if (WTERMSIG(*status) < SIGNALS_CHILD
	  && sig_handler[WTERMSIG(*status)] != NULL)
	my_dprintf(STDERR, sig_handler[WTERMSIG(*status)]->err);
      free_sig_handler(sig_handler);
    }
  return ;
}

static t_uchar	search_path_and_run(char **env, char **path, char **argv)
{
  pid_t		pid;
  t_uchar	ret;
  char		*exec_path;
  int		status;

  status = 0;
  exec_path = get_exec_full_path(argv[0], path);
  if ((ret = chck_exec_path(exec_path, argv) == 1))
    return (ret);
  if ((pid = fork()) == -1)
    my_exit(EXIT_FAILURE, "ERROR: Failed to spawn child process!\n");
  if (pid == 0)
    {
      if ((execve(exec_path, argv, env) == -1))
	my_exit(EXIT_FAILURE, "%s: Cannot run this file.\n", exec_path);
    }
  else
    parent_exec(pid, &status);
  signal_handler(SETSIG, SIGINT_REGULAR);
  free(exec_path);
  return (WEXITSTATUS(status));
}

t_uchar		run_command(t_builtin_ptr **builtins,
			     char ***env,
			     t_command *command)
{
  t_uchar	ret;
  char		**path;
  int		builtin_found;

  path = get_path(*env);
  ret = call_builtins(builtins, &builtin_found, env, command->argv_tmp);
  if (builtin_found == false && my_cmp(command->argv_tmp[0], "exit"))
    {
      builtin_found = true;
      ret = run_exit(*env, path, command, builtins);
    }
  else if (builtin_found == false)
    ret = search_path_and_run(*env, path, command->argv_tmp);
  my_free_2d_tab(path);
  return (ret);
}
