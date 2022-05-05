/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohpark <joohpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:26:49 by joohpark          #+#    #+#             */
/*   Updated: 2022/05/04 17:24:48 by joohpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	check_empty(t_map map, int x, int y)
{
	if (x >= map.col || y >= map.row)
		return (0);
	return (map.strs[y][x] == map.empty);
}

t_square	get_square(t_map map, t_square square)
{
	int	index;
	int	length;

	length = square.length;
	index = 0;
	while (index <= square.length)
	{
		if (!check_empty(map, square.x + index, square.y + length))
			return (square);
		if (!check_empty(map, square.x + length, square.y + index))
			return (square);
		index++;
	}
	square.length = square.length + 1;
	return (get_square(map, square));
}

t_map	find_square(t_map map)
{
	t_square	square;

	square.x = 0;
	square.y = 0;
	square.length = 0;
	map.square = square;
	while (square.y < map.row)
	{
		if (map.strs[square.y][square.x] == map.empty)
		{
			square.length = 1;
			square = get_square(map, square);
			if (map.square.length < square.length)
				map.square = square;
		}
		square.x++;
		if (square.x == map.col)
		{
			square.x = 0;
			square.y++;
		}
	}
	return (map);
}
