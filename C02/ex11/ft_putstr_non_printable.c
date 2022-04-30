/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:46:28 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/21 20:33:33 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int					idx;
	unsigned char		num;
	char				*hex;

	idx = 0;
	hex = "0123456789abcdef";
	while (str[idx] != '\0')
	{
		num = (unsigned char) str[idx];
		if (!(str[idx] > 31 && str[idx] < 127))
		{
			ft_putchar('\\');
			ft_putchar(hex[num / 16]);
			ft_putchar(hex[num % 16]);
		}
		else
			ft_putchar(str[idx]);
		idx ++;
	}
}
