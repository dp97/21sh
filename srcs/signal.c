#include "minishell.h"

static void signal_handler(int signo)
{
    if (signo == SIGINT)
        ;
}

void setup_signals(void)
{
	signal(SIGINT, signal_handler);
}
