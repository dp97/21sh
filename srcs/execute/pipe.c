#include "execute.h"
#include <stdio.h>
/*
**  Create a pipe and pump result of command in it,
**  and return read end of it.
*/
int   piping(char **cmd, char **env)
{
  int   fildes[2];
  pid_t pid;
  int   status;

  if (pipe(fildes) == -1)
  {
      perror("pipe()");
      return (ERR);
  }

  pid = fork();
  if (pid == -1)
  {
    perror("fork()");
    return (ERR);
  }
  if (pid == 0)
  {
    close(fildes[0]);
    dup2(fildes[1], STDOUT_FILENO);
    close(fildes[1]);
    execute_cmd(cmd, env);
    exit(EXIT_SUCCESS);
  }

  close(fildes[1]);
  waitpid(pid, 0, 0);

  return (fildes[0]);
}

int get_input_from(int descriptor, char **argv, char **env)
{
    pid_t pid;
ft_putstr("GET");
    pid = fork();
    if (pid == -1)
    {
        perror("fork()");
        return (ERR);
    }
    else if (pid == 0)
    {
        dup2(descriptor, STDIN_FILENO);
        execute_cmd(argv, env);
        close(descriptor);
        exit(EXIT_SUCCESS);
    }
    close(descriptor);
    waitpid(pid, 0, 0);
    return (DONE);
}
