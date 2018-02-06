#include "parser.h"

int get_file(char *name)
{
    int descriptor;

    if ((descriptor = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0755)) == -1)
        perror(name);
    return (descriptor);
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
            if (-1 == (scmd->in = open(scmd->input, O_RDONLY)))
            {
                perror("open");
                return (ERR);
            }
        }
        if (scmd->output)
        {
            if (-1 == (scmd->out = open(scmd->output, scmd->open_flags, 0755)))
            {
                perror("open");
                return (ERR);
            }
        }

		scmd = scmd->next;
	}
	return (DONE);
}
