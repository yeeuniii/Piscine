/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:55:00 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/22 22:37:05 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (str[size] != '\0')
		size ++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	idx;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	idx = 0;
	if (size <= len_d)
		return (len_s + size);
	while (idx < size - len_d - 1 && src[idx])
	{
		dest[len_d + idx] = src[idx];
		idx ++;
	}
	dest[len_d + idx] = '\0';
	return (len_s + len_d);
}
