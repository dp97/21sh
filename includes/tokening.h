
#ifndef TOKENING_H
# define TOKENING_H
# include "libft.h"
# define EOI	'\0'
# define QUOTED_FLAG	1

# define DELIMIT		0

# define OPERATOR_T		1
# define WORD_T			2

typedef struct		s_token
{
	char			*value;
	short			type;
	struct s_token	*next;
}					t_token;

t_token	*tokening(char *line);
#endif
