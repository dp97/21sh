#include "parser.h"

/*
**  Return NO_APPEND because its a filename not next command.
**  only when its pipe '|' is returned DONE because its a SEPARATOR.
*/
static int     red_output(t_scmd *whole_scmd, t_scmd *curr_scmd, int stream, short append)
{
    t_scmd      *whole;

    whole = whole_scmd;
    while (whole->next)
        whole = whole->next;
    whole->open_flags = O_WRONLY | O_CREAT | (append ? O_APPEND : O_TRUNC);
    if (stream == STDIN_FILENO)
        whole->input = ft_strdup(curr_scmd->argv[0]);
    else if (stream == STDERR_FILENO)
        whole->error = ft_strdup(curr_scmd->argv[0]);
    else
        whole->output = ft_strdup(curr_scmd->argv[0]);
    return (NO_APPEND);
}

/*
**  Checking for fd aggregation.
*/
static int  resolve_optfd(char **op)
{
    int     fd;

    if ((*op)[0] == '0' || \
        (*op)[0] == '1' || \
        (*op)[0] == '2')
    {
        fd = (*op)[0] - 48;
        ++(*op);
        return (fd);
    }
    return (-1);
}

int	prep_redir(t_scmd *whole_scmd, t_scmd *curr_scmd, char *pre, char *post)
{
    int     optional_fd;

	if (pre)
	{
        if (whole_scmd == NULL || curr_scmd->argv == NULL)
            return (ret_error("Parse error", pre, ERR));
        optional_fd = resolve_optfd(&pre);
		if (0 == ft_strcmp(">", pre))
            return (red_output(whole_scmd, curr_scmd, optional_fd, 0));
		else if (0 == ft_strcmp(">>", pre))
            return (red_output(whole_scmd, curr_scmd, optional_fd, 1));
		else if (0 == ft_strcmp("<", pre))
		{
            whole_scmd->input = ft_strdup(curr_scmd->argv[0]);
			return (NO_APPEND);
		}
	}
	if (post)
	{
		if (ft_strcmp("|", post) == 0)
			curr_scmd->output = ft_strdup("|");
	}
	return (DONE);
}
