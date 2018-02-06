#include "minishell.h"

static void signal_handler(int signo)
{
    if (signo == SIGINT)
        ;
}

void setup_signals(void)
{
	signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
}
