/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:59:46 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/20 16:57:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	result;
	unsigned int	idx;

	result = 0;
	idx = 0;
	while (src[idx] != '\0')
	{
		result ++;
		idx ++;
	}
	if (size == 0)
		return (result);
	idx = 0;
	while (idx < size - 1 && idx < result)
	{
		dest[idx] = src[idx];
		idx ++;
	}
	dest[idx] = '\0';
	return (result);
}
