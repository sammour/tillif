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

void	backslashn(char *s, size_t n)
{
	int	i;

	i = n;
	while (i < n * (n + 1))
	{
		s[i] = '\n';
		i = i + n + 1;
	}
}

char	*resolve(t_tetro *list, t_en *e)
{
	e->r = ft_strnew(e->len);
	// e->tmp = ft_strnew(e->size * e->size);
	e->r = ft_strncpy(e->r, e->r, e->len);
	// e->tmp = ft_strncpy(e->tmp, e->tmp, e->size * e->size);
	backslashn(e->r, e->size);
	if ((e->r = fillall(list, e)) != NULL)
		return (e->r);
	// while (e->c != 'A')
	// {
	// 	set_list(e->c)
	// 	if ((e->r = fillall(list, e)) != NULL)
	// 		return (e->r);
	// 	next_n1(e);
	// }
	ft_strdel(e->r);
	e->size = e->size + 1;
	e->len = e->size * (e->size + 1);
	return (resolve(list, e));
}

char	*fillall(t_tetro *begin, t_en *e)
{
	int		pos;

	pos = 0;
	if (fillbloc(e, begin, pos) != 0)
		return (e->r);
	else
		return (NULL);
}

int		fillbloc(t_en *e, t_tetro *bloc, int pos)
{
	while (e->i < e->blocks)
	{
		if (strchr(e->d, bloc->c) != 0)
		{
			(e->i)++;
			return (fillbloc(e, bloc->next, pos));
		}
		else if ((pos = seekpos(e, bloc)) == -1)
		{
			(e->i)++;
			return (fillbloc(e, bloc->next, pos));
		}
		cpybloc(e, bloc, pos);
		e->i = 0;
		set_list(bloc, 'A');
		if (ft_strlen(e->d) <= blocks)
			return (fillbloc(e, bloc, pos));
		else
			return (1);
	}
	goback(e);
	if (e->i == blocks && e->r == NULL)
		return (0);
	set_list(bloc, 'A' + e->i);
	fillbloc(e, bloc, pos);
}