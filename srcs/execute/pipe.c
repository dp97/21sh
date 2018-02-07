#include "execute.h"
#include <stdio.h>

/*
**  Create a pipe and pump result of command in it,
**  and return read end of it.
*/
int get_input_from(t_scmd *scmd, char **env)
{
    pid_t pid;
    int     ret_code;
//ft_putstr("<GET>");

    if (scmd->in > -1 && fcntl(scmd->in, F_GETFL) == -1)
        return (ret_error(0, "INPUT is not a valid descriptor.", ERR));
    if (scmd->out > -1 && fcntl(scmd->out, F_GETFL) == -1)
        return (ret_error(0, "OUTPUT is not a valid descriptor.", ERR));
    if (scmd->err > -1 && fcntl(scmd->err, F_GETFL) == -1)
        return (ret_error(0, "OUTPUT is not a valid descriptor.", ERR));


//printf("=>%s {%d.%d.%d}\n", scmd->argv[0], scmd->in, scmd->out, scmd->err);

    pid = fork();
    if (pid == -1)
    {
        perror("fork()");
        return (ERR);
    }
    else if (pid == 0)
    {
        dup2(scmd->in, STDIN_FILENO);
        dup2(scmd->out, STDOUT_FILENO);
        dup2(scmd->err, STDERR_FILENO);

        ret_code = search_and_run(scmd->argv, env);

        close(scmd->in);
        close(scmd->out);
        close(scmd->err);

        exit(ret_code);
    }
    //waitpid(pid, 0, 0);

    //close(fildes[0]);
    if (scmd->in != STDIN_FILENO)
        close(scmd->in);
    if (scmd->out != STDOUT_FILENO)
        close(scmd->out);
    if (scmd->err != STDERR_FILENO)
        close(scmd->err);

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
