#include "execute.h"

int get_file(char *name, int append)
{
    int descriptor;

    if ((descriptor = open(name, O_WRONLY | ((append == TO_FILE) ? O_TRUNC : O_APPEND) | O_CREAT, 0755)) == -1)
        perror(name);
    return (descriptor);
}
