#include "parser.h"

static void set_ioe(t_scmd *first, t_scmd *second, int ioe)
{
    if (ioe == PIPE)
    {
        first->ioe[1] = TO_PIPE;
        second->ioe[0] = FROM_PIPE;
    }
}

t_scmd		*new_scmd(void)
{
    t_scmd  *new;

    new = (t_scmd *)malloc(sizeof(t_scmd));
    if (new)
    {
        new->argv = NULL;
        new->ioe[0] = -1;
        new->ioe[1] = -1;
        new->ioe[2] = -1;
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
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    if (ioe != -1)
        set_ioe(tmp, tmp->next, ioe);
    return (head);
}
