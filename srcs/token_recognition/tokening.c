#include "tokening.h"

t_token		*new_token(char *value, short type)
{
	t_token	*new;
	
	if ((new = (t_token *)malloc(sizeof(t_token))) == NULL)
		return (NULL);
	new->value = NULL;
	if (value)
		new->value = ft_strdup(value);
	new->type = type;
	new->next = NULL;
	return (new);
}

void	append_token(t_token **tokens, short type)
{
	while ((*tokens)->next)
		*tokens = (*tokens)->next;
	(*tokens)->next = new_token(NULL, type);
	*tokens = (*tokens)->next;
}

t_token		*tokening(char *line)
{
	t_token	*tokens;
	t_token	*t;
	char	prev;
	char	curr;
	short	flags;
	int		pos;
	char 	foper[] = {';', '|', '<', '>'};

	prev = '\0';
	pos = 0;
	flags = 0;
	if ((tokens = (t_token *)malloc(sizeof(t_token))) == NULL)
		return (NULL);
	t = tokens;
	while (1)
	{
		curr = *line;
		if (curr == '\0')
			return (tokens);
		else if (ft_memchr(foper, curr, sizeof(foper)) != NULL && !(QUOTED_FLAG & flags))
		{
			if (t)
			{
				append_token(&t, OPERATOR_T);
				ft_strichar(&(t->value), pos++, curr);
			}
		}
		else if (curr == '\n' && !(QUOTED_FLAG & flags))
			append_token(&t, 0);
		else if (curr == ' ' && !(QUOTED_FLAG & flags))
			append_token(&t, 0);
		else if (t->type & WORD_T)
			t->value = ft_straddch(t->value, curr);
		else if (curr == '#')
		{
			while ((curr = *line) && curr != '\n')
				line++;
		}
		else
		{
			append_token(&t, WORD_T);
			t->value = ft_straddch(t->value, curr);
		}
		prev = curr;
		line++;
	}
	return (NULL);
}
