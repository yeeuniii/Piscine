/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:28:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/17 17:21:58 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(char *list)
{
	write(1, list, 3);
	if (list[0] != '7')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	list[3];

	list[0] = '0';
	list[1] = '1';
	list[2] = '2';
	while (list[0] <= '7' && list[1] <= '8' && list[2] <= '9')
	{
		print(list);
		list[2] = list[2] + 1;
		if (list[2] > '9')
		{
			list[1] = list[1] + 1;
			list[2] = list[1] + 1;
		}
		if (list[1] > '8')
		{
			list[0] = list[0] + 1;
			list[1] = list[0] + 1;
			list[2] = list[1] + 1;
		}
	}
}
