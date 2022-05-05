/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:53:10 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/04 15:10:44 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "square.h"

t_map	fill(t_map map)
{
	int			i;
	int			j;
	t_square	square;

	i = 0;
	j = 0;
	square = map.square;
	while (i < square.length)
	{
		while (j < square.length)
		{
			map.strs[square.y + i][square.x + j] = map.full;
			j ++;
		}
		i ++;
		j = 0;
	}
	return (map);
}
