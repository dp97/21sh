#include "builtins.h"
#include <unistd.h>
extern char **environ;

static int	ft_envadd(char *name, char *new)
{
	char	**tmp;
	char	*t;
	int		i;
	int		n;

	i = 0;
	while (environ[i])
	{
		t = environ[i];
		if (ft_strncmp(t, name, ft_strlen(name)) == 0)
		{
ft_putstr(t);

			//free(&environ[i]);
//return ;

			environ[i] = new;
			return (DONE);
		}
		i++;
	}
	tmp = environ;
	if ((environ = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return (-1);
	n = 0;
	while (n < i)
		environ[n] = tmp[n++];
	environ[n++] = new;
	environ[n] = NULL;
	free(tmp);
	return (DONE);
}

int			ft_setenv(char *name, char *val, int overwrite)
{
	char	*s;
	char	*new;

	if (name == NULL)
		return (ret_error("ft_setenv", "Var name is Null.", ERR));
	if (ft_strchr(name, '='))
		return (ret_error("ft_setenv", "Var name cantain a '='.", ERR));
	if (getenv(name) && overwrite == 0)
		return (DONE);
	if ((new = ft_strnew(ft_strlen(name) + ft_strlen(val) + 2)) == NULL)
		return (-1);
	ft_strcpy(new, name);
	ft_strcat(new, "=");
	ft_strcat(new, val);
	if (ft_envadd(name, new) == -1)
	{
		ft_strdel(&new);
		return (ret_error("ft_setenv", "Not enough memory.", ERR));
	}
	return (DONE);
}
