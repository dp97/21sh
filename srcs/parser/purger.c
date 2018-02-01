#include "parser.h"

/*
**  Take address of t_cmd structure and erarse it completely.
*/
void purge_cmd(t_cmd *cmd)
{
    t_cmd   *cmd_del;
    t_scmd  *scmd_del;
    t_scmd  *scmd;

    while (cmd)
    {
        cmd_del = cmd;
        cmd = cmd->next;
        scmd = scmd->by_one;
        while (scmd)
        {
            scmd_del = scmd;
            scmd = scmd->next;
            ft_str2deldl
            free(scmd_del);
        }
        free(cmd_del);
    }
}
