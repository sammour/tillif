char	*marki(char *s, int num)
{
	char	*begin;

	begin = s;
	while ((s = ft_strchr(s, '#')) != NULL)
		*s = 'A' + num;
	return (begin);
}

void	filtab(char ***tab, char *str,int blocks)
{
	int	i;

	i = 0;
	while (i < blocks)
	{
		(*tab)[i] = ft_strndup(str + (21 * i), 20);
		i++;
	}
	(*tab)[i] = NULL;
	i = 0;
	while (i < blocks)
	{
		(*tab)[i] = marki((*tab)[i], i);
		i++;
	}
}