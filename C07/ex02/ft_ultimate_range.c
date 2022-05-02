/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:19:34 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/01 14:07:03 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	size;
	int	*arr;

	if (min >= max)
		return (0);
	idx = 0;
	size = max - min;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	while (min < max)
	{
		arr[idx] = min;
		idx ++;
		min ++;
	}
	*range = arr;
	return (size);
}
