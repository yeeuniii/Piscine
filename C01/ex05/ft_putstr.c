/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:00:27 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/17 17:15:44 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_size(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index ++;
	}
	return (index);
}

void	ft_putstr(char *str)
{
	int	size;

	size = get_size(str);
	write(1, str, size);
}
