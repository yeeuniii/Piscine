/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:23:27 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/21 12:46:35 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;
	int				check;

	idx = 0;
	check = 0;
	while (idx < n)
	{
		if (src[idx] == '\0')
			check = 1;
		if (check == 0)
			dest[idx] = src[idx];
		if (check != 0)
			dest[idx] = '\0';
		idx ++;
	}
	return (dest);
}
