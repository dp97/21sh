#include "ft_readline.h"

void	proccess_line_for_quotes(t_chain *line, t_flag *flags)
{
	t_chain	*l;
	char 	*s;

	if ((l = ft_chain_gethead(line)))
	{
		while (l)
		{
			s = l->value;
			while (s && *s)
			{
				if (!(*flags & DQUOTE_FLAG) && *s == '\'')
					*flags & QUOTE_FLAG ? *flags ^= QUOTE_FLAG : (*flags |= QUOTE_FLAG);
				else if (!(*flags & QUOTE_FLAG) && *s == '"')
					*flags & DQUOTE_FLAG ? *flags ^= DQUOTE_FLAG : (*flags |= DQUOTE_FLAG);
				s++;
			}
			l = l->next;
		}
	}
}
