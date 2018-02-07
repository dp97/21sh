#include "parser.h"

static int  setup_pipe(int *w, int *r)
{
    int fildes[2];

    if (pipe(fildes) == -1)
    {
        perror("pipe()");
        return (ERR);
    }
    *r = fildes[0];
    *w = fildes[1];
    return (DONE);
}

/*
**	Open necesary streams for redirection and piping.
*/
int open_streams(t_scmd *sc)
{
	t_scmd	*scmd;

	scmd = sc;
	while (scmd)
    {

        if (scmd->input)
        {
            if (0 == ft_strcmp(scmd->input, "|"))
            {
                //setup_pipe(&(scmd->out), &(scmd->next->in));
            }
            else if (-1 == (scmd->in = open(scmd->input, O_RDONLY)))
            {
                perror("open");
                return (ERR);
            }
        }
        if (scmd->output)
        {
            if (0 == ft_strcmp(scmd->output, "|"))
            {
                setup_pipe(&(scmd->out), &(scmd->next->in));
            }
            else if (-1 == (scmd->out = open(scmd->output, scmd->open_flags, 0755)))
            {
                perror("open");
                return (ERR);
            }
        }
        if (scmd->error)
        {
            if (-1 == (scmd->err = open(scmd->error, scmd->open_flags, 0755)))
            {
                perror("open");
                return (ERR);
            }
        }

		scmd = scmd->next;
	}
	return (DONE);
}
