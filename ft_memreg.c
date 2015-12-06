/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memreg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 04:43:57 by sblancha          #+#    #+#             */
/*   Updated: 2015/12/04 04:52:55 by sblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memreg(void **toreg)
{
	void	**tmp;

	tmp = toreg;
	while (toreg)
	{
		free(*toreg);
		*toreg = NULL;
		toreg++;
	}
	toreg = tmp;
	free(toreg);
	toreg = NULL;
}
