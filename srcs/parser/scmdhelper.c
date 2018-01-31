#include "parser.h"

static void set_ioe(t_scmd *first, t_scmd *second, int ioe)
{
    if (ioe == PIPE)
    {
        second->in = STD_PREV;
        first->out = STD_NEXT;
    }
}

t_scmd		*new_scmd(void)
{
    t_scmd  *new;

    new = (t_scmd *)malloc(sizeof(t_scmd));
    if (new)
    {
        new->argv = NULL;
        new->in = STDIN_FILENO;
		new->out = STDOUT_FILENO;
		new->err = STDERR_FILENO;
        new->next = NULL;
    }
    return (new);
}

t_scmd      *add_scmd(t_scmd *head, t_scmd *new, int ioe)
{
    t_scmd  *tmp;

    if (head == NULL)
    {
        if (ioe != -1)
        {
            ret_error("parse", "Grammar error.", ERR);
            return (NULL);
        }
        return (new);
    }
    tmp = head;
    while (head->next)
        head = head->next;
    head->next = new;
    if (ioe != -1)
        set_ioe(head, head->next, ioe);
    return (tmp);
}
