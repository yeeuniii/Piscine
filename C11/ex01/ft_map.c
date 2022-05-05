/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:39:31 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/03 15:42:20 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	idx;
	int	*res;

	idx = 0;
	res = malloc(sizeof(int) * length);
	while (idx < length)
	{
		res[idx] = f(tab[idx]);
		idx ++;
	}
	return (res);
}
