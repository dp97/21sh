#include "ft_readline.h"
char	*clipboard(char *s, short assign);

static void	cut_copy_backword(t_chain *line, t_cursor *cursor)
{
	int		col;

	if ((*cursor).col == (*cursor).col_start)
		return ;
	col = ft_posinstr(*cursor);
	shift_plus_arrows(A_LEFT_W, cursor, &line);
	col -= ft_posinstr(*cursor);
	clipboard(ft_strsub(line->value, ft_posinstr(*cursor), col), YES);
	while (0 <= --col)
		delete_char(&line->value, cursor);
}

static void	yank_to_line(char **line, t_cursor *cursor)
{
	char	*yank;

	if ((yank = clipboard(NULL, NO)) == NULL)	
		return ;
	while (*yank)
		ft_insert_char(line, cursor, *yank++);
}

static void	cut_copy_backall(char **line, t_cursor *cursor)
{
	if ((*cursor).col == (*cursor).col_start)
		return ;
	clipboard(ft_strsub(*line, 0, ft_posinstr(*cursor)), YES);
	while (backspace_char(line, cursor) == DONE)
		;
}

static void	cut_copy_frontall(char **line, t_cursor *cursor)
{
	if ((*cursor).col == (*cursor).col_end)
		return ;
	clipboard(ft_strsub(*line, ft_posinstr(*cursor), ft_strlen(*line) - ft_posinstr(*cursor)), YES);
	while ((*cursor).col < (*cursor).col_end)
		delete_char(line, cursor);
}

int			cut_copy_paste(char *ctrl, t_chain *line, t_cursor *cursor)
{
	if (ft_strcmp(ctrl, CC_BACK_W) == 0)
		cut_copy_backword(line, cursor);
	if (ft_strcmp(ctrl, CC_BACK) == 0)
		cut_copy_backall(&line->value, cursor);
	if (ft_strcmp(ctrl, CC_FRONT) == 0)
		cut_copy_frontall(&line->value, cursor);
	if (ft_strcmp(ctrl, CC_PASTE) == 0)
		yank_to_line(&line->value, cursor);
	else
		return (NO_MATCH);
	return (MATCH);
}
