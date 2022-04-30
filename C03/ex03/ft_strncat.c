/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:00:46 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/22 22:48:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	unsigned int	size;

	idx = 0;
	size = 0;
	while (dest[size] != '\0')
		size ++;
	while (idx < nb && src[idx])
	{
		dest[size + idx] = src[idx];
		idx ++;
	}
	dest[size + idx] = '\0';
	return (dest);
}
