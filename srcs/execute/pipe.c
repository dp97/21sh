#include "execute.h"
#include <stdio.h>

int   piping(char **first_cmd, char **second_cmd, char **env)
{
  int   fildes[2];
  pid_t child[2];
  int   status;

  if (pipe(fildes) == -1)
  {
    perror("pipe()");
    return (ERR);
  }

  child[0] = fork();
  if (child[0] == -1)
  {
    perror("fork()");
    return (ERR);
  }
  if (child[0] == 0)
  {
    close(fildes[0]);
    dup2(fildes[1], STDOUT_FILENO);
    close(fildes[1]);
    execute_cmd(first_cmd, env);
    exit(EXIT_SUCCESS);
  }

  child[1] = fork();
  if (child[1] == -1)
  {
    perror("fork()");
    return (ERR);
  }
  if (child[1] == 0)
  {
    close(fildes[1]);
    dup2(fildes[0], STDIN_FILENO);
    close(fildes[0]);
    
    execute_cmd(second_cmd, env);
    exit(EXIT_SUCCESS);
  }

  //parent
  close(fildes[0]);
  close(fildes[1]);
  waitpid(child[0], 0, 0);
  waitpid(child[1], 0, 0);
  return (DONE);
}
