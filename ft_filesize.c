/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 03:04:10 by sblancha          #+#    #+#             */
/*   Updated: 2015/12/04 03:36:33 by sblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_filesize(int fd)
{
	char	*buf;
	size_t	tmp;
	size_t	size;

	buf = NULL;
	tmp = 0;
	size = 0;
	if (!(buf = (char*)malloc(sizeof(char) * 4096)))
		return (0);
	while ((tmp = read(fd, buf, 4096)) != 0)
		size = size + tmp;
	free(buf);
	return (size);
}
