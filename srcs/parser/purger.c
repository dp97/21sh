#include "parser.h"

void purge_scmd(t_scmd *scmd)
{
    t_scmd  *scmd_del;

    while (scmd)
    {
        scmd_del = scmd;
        scmd = scmd->next;
        ft_2dstrdel(scmd_del->argv);
        ft_strdel(&scmd_del->input);
        ft_strdel(&scmd_del->output);
        ft_strdel(&scmd_del->error);
        free(scmd_del);
    }
}

/*
**  Take address of t_cmd structure and erarse it completely.
*/
void purge_cmd(t_cmd *cmd)
{
    t_cmd   *cmd_del;

    while (cmd)
    {
        cmd_del = cmd;
        cmd = cmd->next;
        purge_scmd(cmd_del->by_one);
        free(cmd_del);
    }
}
