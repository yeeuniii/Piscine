/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:25:30 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/30 12:13:03 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
