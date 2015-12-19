void	getx(t_tetro **t, char *s)
{
	int	i;
	int	n;
	int	xmin;

	i = 0;
	n = 0;
	xmin = 4;
	while (n < 4)
	{
		if (s[i] == (*t)->c)
		{
			(*t)->x[n] = i % 5;
			if ((*t)->x[n] < xmin)
				xmin = (*t)->x[n];
		}
		i++;
	}
	n = 0;
	while (n < 4)
	{
		(*t)->x[n] = (*t)->x[n] - xmin;
		n++;
	}
}

void	gety(t_tetro **t, char *s)
{
	int	i;
	int	n;
	int	ymin;

	i = 0;
	n = 0;
	ymin = 4;
	while (n < 4)
	{
		if (s[i] == (*t)->c)
		{
			(*t)->y[n] = i / 5;
			if ((*t)->y[n] < ymin)
				ymin = (*t)->y[n];
		}
		i++;
	}
	n = 0;
	while (n < 4)
	{
		(*t)->y[n] = (*t)->y[n] - ymin;
		n++;
	}
}

t_tetro	*create_elem(char *src, char a)
{
	t_tetro	*new;
	int		i;

	new = NULL;
	i = 0;
	if (!(new = (t_tetro*)malloc(sizeof(t_tetro))))
		return (NULL);
	new->c = a;
	getx(&new, src);
	gety(&new, src);
	new->next = NULL;
	return (new);
}

t_tetro	*parse(char **tab)
{
	char	i;
	t_tetro	*res;
	t_tetro	*begin;

	i = 0;
	if (!(res = create_elem(*tab, 'A')))
		return (NULL);
	begin = res;
	tab++;
	i++;
	while (tab)
	{
		if (!(res->next = create_elem(*tab, 'A' + i)))
			return (NULL);
		tab++;
		i++;
		res = res->next;
	}
	res->next = begin;
	return (begin);
}
