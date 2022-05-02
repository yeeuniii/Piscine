/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:46:37 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/01 13:55:24 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	idx;
	int	*arr;

	if (min >= max)
		return (0);
	idx = 0;
	size = max - min;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (min < max)
	{
		arr[idx] = min;
		min ++;
		idx ++;
	}
	return (arr);
}
