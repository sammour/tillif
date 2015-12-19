
int		seekpos(t_en *e, t_tetro *bloc)
{
	int	i;

	i = 0;
	while (i < e->len)
	{
		if (checkpos(i, bloc, e) != 0)
			return (i);
		i++;
	}
	return (-1);
}

int		checkpos(int i, t_tetro *bloc, t_en *e)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		if (lool(e, i + bloc->x[count] + (e->size + 1) * bloc->y[count]) != 0)
			return (0);
		count++;
	}
	return (i);
}

int		lool(t_en *e, int n);
{
	int	*tem;

	tem = e->taken;
	if (n % e->size + 1 == e->size)
		return (0);
	while (tem)
	{
		if (*tem == n)
			return (0);
		tem++;
	}
	return (1);
}