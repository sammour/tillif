/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 04:53:53 by sblancha          #+#    #+#             */
/*   Updated: 2015/12/06 21:43:04 by sblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*resolve(t_tetro *list, t_en *e)
{
	e->r = ft_strnew(e->size * e->size);
	e->tmp = ft_strnew(e->size * e->size);
	e->r = ft_strncpy(e->r, e->r, e->size * e->size);
	e->tmp = ft_strncpy(e->tmp, e->tmp, e->size * e->size);
	if ((e->r = fillall(list, e)) != NULL)
		return (e->r);
	while (e->c != 'A')
	{
		set_list(e->c)
		if ((e->r = fillall(list, e)) != NULL)
			return (e->r);
		next_n1(e);
	}
	ft_strdel(e->r);
	e->size = e->size + 1;
	return (resolve(list, e));
}

char	*fillall(t_tetro *begin, t_en *e)
{
	int		pos;

	pos = 0;
	fillbloc(e, begin, pos);
}

int		fillbloc(t_en *e, t_tetro *bloc, int pos)
{

	while (e->i < blocks)
	{
		if (strchr(e->d, bloc->c) != 0)
		{
			(e->i)++;
			return (fillbloc(e, bloc->next, pos));
		}
		else if ((pos = seekpos(e->tmp, bloc)) == -1)
		{
			(e->i)++;
			return (fillbloc(e, bloc->next, pos));
		}
		cpybloc(e, bloc, pos);
		i = 0;
		set_list('A')
		if (ft_strlen(e->d) <= blocks)
			return (
	}
}

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
