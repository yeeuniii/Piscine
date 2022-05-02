/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:42:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/30 17:15:16 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

int	count_len(char **strs, int size, char *sep)
{
	int	idx;
	int	len;

	idx = 0;
	len = 0;
	while (idx < size)
	{
		len += ft_strlen(strs[idx]);
		idx ++;
	}
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strcat(char *dest, char *str)
{
	int	idx;
	int	size;

	idx = 0;
	size = ft_strlen(dest);
	while (str[idx])
	{
		dest[size + idx] = str[idx];
		idx ++;
	}
	dest[size + idx] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		idx;

	if (size == 0)
		return (malloc(sizeof(char)));
	len = count_len(strs, size, sep);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[0] = 0;
	idx = 0;
	while (idx < size)
	{
		ft_strcat(str, strs[idx]);
		if (idx != size - 1)
			ft_strcat(str, sep);
		idx ++;
	}
	return (str);
}
