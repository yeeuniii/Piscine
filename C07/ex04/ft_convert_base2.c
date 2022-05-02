/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:04:46 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/30 12:32:54 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	get_memory_size(long num, int base_size)
{
	int	size;

	size = 0;
	if (!num)
		return (1);
	if (num < 0)
		size ++;
	while (num)
	{
		num /= base_size;
		size ++;
	}
	return (size);
}

char	*ft_itoa_base(long num, char *base)
{
	int		base_size;
	int		size;
	int		idx;
	char	*str;

	base_size = ft_strlen(base);
	size = get_memory_size(num, base_size);
	idx = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	if (num < 0)
	{
		num *= -1;
		str[idx] = '-';
		idx ++;
	}
	str[size] = '\0';
	while (size > idx)
	{
		size --;
		str[size] = base[num % base_size];
		num /= base_size;
	}
	return (str);
}
