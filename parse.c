#include "push_swap.h"

static int	is_digits_only(const char *s)
{
	if (!(*s == '+' || *s == '-' || ft_isdigit(*s)))
		return (0);
	s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	*make_content(int value)
{
	int	*result;
    
	result = malloc(sizeof(*result));
	//if (!result)
	//   process_error();
	*result = value;
	return (result);
}

int add_value(t_dlist **lst, int value)
{
	int		*content;
	t_dlist	*elem;

	content = make_content(value);
	//if (!content)
	//	return (1);
	elem = ft_dlstnew(content);
	//if (!elem)
	//	process_syserror();
	ft_dlstadd_back(lst, elem);
	return (0);
}


int	parse_args(t_app *e, int count, char **argv)
{
	int	i;
	int value;

	i = 0;
	while (i < count)
	{
		if (!is_digits_only(argv[i]))
			return (0);
		value = ft_atoi(argv[i]);
		// check doubles
		// if everything is ok - add to stack
		add_value(&e->a, value);
		i++;
	}
	return (1);
}
