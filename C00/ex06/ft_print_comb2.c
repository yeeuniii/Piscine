/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:29:16 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/17 17:22:36 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int num)
{
	int	one;
	int	two;

	one = num / 10 + '0';
	two = num % 10 + '0';
	ft_putchar(one);
	ft_putchar(two);
}

void	check(int num1, int num2)
{
	if (num1 < num2)
	{
		print(num1);
		ft_putchar(' ');
		print(num2);
		if (num1 != 98)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 1;
	while (num1 < 100)
	{
		while (num2 < 100)
		{
			check(num1, num2);
			num2 ++;
		}
		num1 ++;
		if (num2 == 100)
		{
			num2 = num1 + 1;
		}
	}
}
