#include "execute.h"

int get_file(char *name)
{
    int descriptor;

    if ((descriptor = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0755)) == -1)
        perror(name);
    return (descriptor);
}
