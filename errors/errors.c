
#include "push_swap.h"

void 	process_syserror(void)
{
	char	*msg;

	msg = strerror(errno);
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	exit(errno);
}

int	perr(char *cmd, char *arg, char *err, int code)
{
	ft_putstr_fd(APP_NAME, 2);
	ft_putstr_fd(": ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (err)
		ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	return (code);
}
