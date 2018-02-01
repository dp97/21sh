#include "execute.h"
#include <stdio.h>

int is_valid_fd(int fd)
{
    return fcntl(fd, F_GETFL) != -1 || errno != EBADF;
}

/*
**  Create a pipe and pump result of command in it,
**  and return read end of it.
*/
int get_input_from(int descriptor[3], char **argv, char **env)
{
    pid_t pid;
    int     fildes[2];
    int     ret_code;
//ft_putstr("<GET>");

fildes[0] = -1;
fildes[1] = -1;

    if (descriptor[1] != INVALID_FD)
    {
        if (pipe(fildes) == -1)
        {
            perror("pipe()");
            return (ERR);
        }
        descriptor[1] = fildes[1];
    }
    if (descriptor[0] != INVALID_FD && fcntl(descriptor[0], F_GETFL) == -1)
        return (ret_error(0, "Input is not a valid descriptor.", ERR));


    pid = fork();
    if (pid == -1)
    {
        perror("fork()");
        return (ERR);
    }
    else if (pid == 0)
    {
        close(fildes[0]);
        if (descriptor[0] != INVALID_FD && descriptor[0] != STDIN_FILENO)
            dup2(descriptor[0], STDIN_FILENO);
        if (descriptor[1] != INVALID_FD && descriptor[1] != STDOUT_FILENO)
            dup2(descriptor[1], STDOUT_FILENO);
        ret_code = search_and_run(argv, env);
        close(descriptor[0]);
        close(descriptor[1]);
        close(fildes[1]);
        exit(ret_code);
    }
    //waitpid(pid, 0, 0);

    //close(fildes[0]);
    close(descriptor[1]);

    descriptor[0] = (fildes[0] != INVALID_FD) ? fildes[0] : -1;
    descriptor[1] = -1;

int status;
    while (1)
    {
        if (waitpid(pid, &status, 0) == -1)
            return (ret_error("waitpid", "Interupted by a signal.", ERR));

        if (WIFEXITED(status))
            return (WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            return (WTERMSIG(status));
        else if (WIFSTOPPED(status))
            return (WSTOPSIG(status));
        else
            return (status);
    }

    return (DONE);
}
