/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:37:13 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/01 20:37:24 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char character, char *charset)
{
	int	idx;

	idx = 0;
	while (charset[idx])
	{
		if (character == charset[idx])
			return (1);
		idx ++;
	}
	return (0);
}

int	count_size(char *str, char *charset)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	if (!(*charset))
		return (1);
	while (str[idx])
	{
		if (!is_sep(str[idx], charset)
			&& (is_sep(str[idx + 1], charset) == 1 || !str[idx + 1]))
			count ++;
		idx ++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

char	*ft_strdup(char *src, int size)
{
	char	*dest;
	int		idx;

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

char	**ft_split(char *str, char *charset)
{
	int		count;
	int		idx;
	char	**arr;
	char	*from;

	idx = 0;
	count = count_size(str, charset);
	arr = malloc(sizeof(char *) * (count + 1));
	while (idx < count)
	{
		while (is_sep(*str, charset))
			str ++;
		from = str;
		while (!is_sep(*str, charset) && *str)
			str ++;
		arr[idx] = ft_strdup(from, str - from);
		idx ++;
	}
	arr[idx] = NULL;
	return (arr);
}
