#include "parser.h"

t_scmd		*new_scmd(void)
{
    t_scmd  *new;

    new = (t_scmd *)malloc(sizeof(t_scmd));
    if (new)
    {
        new->argv = NULL;
        new->open_flags = 0;
        new->output = NULL;
        new->out = STDOUT_FILENO;
        new->input = NULL;
        new->in = STDIN_FILENO;
        new->error = NULL;
        new->err = STDERR_FILENO;
        new->next = NULL;
    }
    return (new);
}

t_scmd      *add_scmd(t_scmd *head, t_scmd *new)
{
    t_scmd  *tmp;

    if (head == NULL)
        return (new);
    tmp = head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (head);
}

void destroy_scmd(t_scmd **scmd)
{
    if (scmd == NULL|| *scmd == NULL)
        return ;
    ft_2dstrdel((*scmd)->argv);
    ft_strdel(&(*scmd)->input);
    ft_strdel(&(*scmd)->output);
    ft_strdel(&(*scmd)->error);
    free(*scmd);
    *scmd = NULL;
}
