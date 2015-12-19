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
	ft_strclr(e->d);
	resolve(list, blocks);
	showit(e);
}

int		main(int ac, char **av)
{
	int		fd;
	int		len;
	char	*buf;

	if (ac != 2)
		return (ft_error(0));
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
	do_it(buf, len);
	if (!(close(fd)))
		return (ft_error(0));
	free(buf);
	return (0);
}
