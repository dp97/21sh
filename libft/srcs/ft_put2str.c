#include "libft.h"

/*
**  Print a 2d string array. del is delimiter.
*/
void    ft_put2str(char **ss, char del)
{
    int i;

    i = 0;
    if (!ss)
        return ;
    while (ss[i])
    {
        ft_putstr(ss[i]);
        if (del)
            ft_putchar(del);
        i++;
    }
}
