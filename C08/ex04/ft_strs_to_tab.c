/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:53:25 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/01 18:52:22 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		size;
	int		idx;

	size = 0;
	while (src[size])
		size ++;
	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	idx = 0;
	while (idx < size)
	{
		dest[idx] = src[idx];
		idx ++;
	}
	dest[idx] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	t_stock_str	stock;
	t_stock_str	*arr;

	idx = 0;
	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (0);
	while (idx < ac)
	{
		stock.size = ft_strlen(av[idx]);
		stock.str = av[idx];
		stock.copy = ft_strdup(av[idx]);
		arr[idx] = stock;
		idx ++;
	}
	arr[idx].str = 0;
	return (arr);
}
