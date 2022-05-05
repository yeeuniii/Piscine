/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:10:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/04 23:44:48 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);
char	count_size(char *str, char *charset);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

int	check_correct_word(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.col)
	{
		while (j < map.row)
		{
			if (!(map.strs[j][i] == map.empty
				&& map.strs[j][i] == map.obstacle))
				return (0);
			j ++;
		}
		i ++;
		j = 0;
	}
	return (1);
}

t_map	check1(char *str, int *size)
{
	t_map	map;
	int		idx;
	char	*nbr;

	map.valid = 0;
	if (count_size(str, "\n") < 2)
		return (map);
	while (str[*size] != '\n')
		*size += 1;
	idx = *size - 3;
	if (idx < 1)
		return (map);
	nbr = malloc(sizeof(char) * idx + 1);
	if (!nbr)
		return (map);
	while (--idx > -1)
		nbr[idx] = str[idx];
	map.row = ft_atoi(nbr);
	if (!map.row)
		return (map);
	free(nbr);
	return (map);
}

t_map	check2(char *str)
{
	t_map	map;
	int		size;
	int		idx;
	int		len;

	size = 0;
	map = check1(str, &size);
	idx = size;
	map.full = str[--idx];
	map.obstacle = str[--idx];
	map.empty = str[--idx];
	if (map.row != count_size(str + size + 1, "\n"))
		return (map);
	map.strs = ft_split(str + size + 1, "\n");
	idx = 0;
	len = ft_strlen(map.strs[0]);
	while (++idx < map.row)
	{
		if (len != ft_strlen(map.strs[idx]))
			return (map);
	}
	map.col = len;
	if (!check_correct_word(map))
		return (map);
	map.valid = 1;
	return (map);
}
