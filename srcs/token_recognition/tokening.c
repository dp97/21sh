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
	if ((*tokens)->value)
	{
		(*tokens)->next = new_token(NULL, type);
		*tokens = (*tokens)->next;
	}
	else
		(*tokens)->type = type;
}

t_token		*tokening(char *line)
{
	t_token	*tokens;
	t_token	*t;
	short	prev;
	char	curr;
	short	flags;
	int		pos;
	char 	foper[] = {';', '|', '<', '>'};

	prev = 0;
	pos = 0;
	flags = 0;
	if ((tokens = new_token(NULL, 0)) == NULL)
		return (NULL);
	t = tokens;
	while (1)
	{
		curr = *line;
		if (curr == '\0')
			return (tokens);
		else if (prev == OPERATOR_T && !(QUOTED_FLAG & flags))
		{
			if (curr == '<' || curr == '>')
				t->value = ft_straddch(t->value, curr);
			else
			{
				prev = DELIMIT;
				continue ;
			}
		}
		else if ((curr == '\\' || curr == '\'' || curr == '\"') && !(QUOTED_FLAG & flags))
		{
			t->value = ft_straddch(t->value, curr);
			flags |= QUOTED_FLAG;
		}
		else if (ft_memchr(foper, curr, sizeof(foper)) != NULL && !(QUOTED_FLAG & flags))
		{
			prev = OPERATOR_T;
			append_token(&t, OPERATOR_T);
			t->value = ft_straddch(t->value, curr);
		}
		else if (curr == '\n' && !(QUOTED_FLAG & flags))
			prev = DELIMIT;
		else if (curr == ' ' && !(QUOTED_FLAG & flags))
			prev = DELIMIT;
		else if (prev == WORD_T)
			t->value = ft_straddch(t->value, curr);
		else if (curr == '#')
		{
			while ((curr = *line) && curr != '\n')
				line++;
		}
		else
		{
			prev = WORD_T;
			append_token(&t, WORD_T);
			t->value = ft_straddch(t->value, curr);
		}
		line++;
	}
	return (NULL);
}
