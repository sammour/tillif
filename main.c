/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 02:34:25 by sblancha          #+#    #+#             */
/*   Updated: 2015/12/06 21:43:16 by sblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fcntl.h"

char	*marki(char *s, int num)
{
	char	*begin;

	begin = s;
	while ((s  = ft_strchr(s, '#')) != NULL)
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

void	do_it(char *str, size_t len)
{
	int		blocks;
	char	**tab;
	t_tetro	*list;

	blocks = (len + 1) / 21;
	tab = NULL;
	list = NULL;
	if (!(tab = (char**)malloc(sizeof(char*) * (blocks + 1))))
		return (0);
	filtab(&(tab), str, blocks);
	list = parse(char **tab);
	ft_memreg(tab);
	e->d = ft_strnew(e->blocks);
	resolve(list, blocks);
}

int		main(int ac, char **av)
{
	int		fd;
	int		len;
	char	*buf;

	if (!(fd = open(av[1])))
		return (ft_error(0));
	len = ft_filesize(fd);
	if (!(buf = (char*)malloc(sizeof(char) * (ft_filesize(fd) + 1))))
		return (ft_error(0));
	if (!(read(fd, buf, len)))
		return (ft_error(0));
	buf[len] = 0;
	if (check(buf) == -1)
		return (ft_error(0));
	if (!(do_it(buf, len)))
		return (ft_error(0));
	if (!(close(fd)))
		return (ft_error(0));
	free(buf);
	return (0);
}
