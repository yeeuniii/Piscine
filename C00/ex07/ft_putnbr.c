/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:40:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/19 11:41:48 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	power(int num, int times)
{
	int	index;
	int	result;

	index = 0;
	result = 1;
	while (index < times)
	{
		result = result * num;
		index ++;
	}
	return (result);
}

int	get_digit(int num)
{
	int	times;
	int	quotient;

	times = 10;
	quotient = 0;
	while (!quotient)
	{
		times --;
		quotient = num / power(10, times);
		if (num == 0)
		{
			times = 0;
			quotient = 1;
		}
	}
	return (times + 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	size;
	int	num;
	int	ascii_num;

	size = get_digit(nb) - 1;
	if (nb < 0)
	{
		ft_putchar('-');
	}
	while (size >= 0)
	{
		num = nb / power(10, size);
		nb = nb - num * power(10, size);
		if (num < 0)
		{
			num = -num;
		}
		ascii_num = num + '0';
		ft_putchar(ascii_num);
		size --;
	}
}
