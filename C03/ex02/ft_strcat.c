/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:54:06 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/22 22:48:47 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	size;
	int	idx;

	size = 0;
	idx = 0;
	while (dest[size] != '\0')
	{
		size ++;
	}
	while (src[idx] != '\0')
	{
		dest[size + idx] = src[idx];
		idx ++;
	}
	dest[size + idx] = '\0';
	return (dest);
}
