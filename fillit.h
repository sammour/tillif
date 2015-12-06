/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 05:16:43 by sblancha          #+#    #+#             */
/*   Updated: 2015/12/06 21:42:47 by sblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_tetro
{
	int				x[4];
	int				y[4];
	char			c;
	struct s_tetro	*next;
}				t_tetro;

typedef struct	s_en
{
	t_tetro	*n1;
	char	*r;
	char	*d;
	size_t	blocks;
	size_t	size;
	size_t	i;
	char	c;
}				t_en;

#endif
