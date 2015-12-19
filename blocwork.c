void	set_list(t_tetro *bloc, char c)
{
	while (bloc->c != c)
		bloc = bloc->next;
}

void	cpybloc(t_en *e, t_tetro *bloc, int pos)
{
	int	i;

	i = 0;
	ft_strncat(e->d, &(bloc->c), 1);
	while (i < 4)
	{
		e->r[pos + bloc->x[i] + (e->size + 1) * bloc->y[i]]
		i++;
	}
}

void	goback(t_en *e)
{
	int	i;

	i = 0;
	while (i < e->len)
	{
		if (e->r[i] == e->c)
			e->r[i] = 0;
		i++;
	}
	e->i = last(e->d) - 'A' + 1;
	clearlast(e->d);
	e->c = last(e->d);
}