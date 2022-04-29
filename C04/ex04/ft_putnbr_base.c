/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:55:31 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/28 22:37:20 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size ++;
	return (size);
}

int	is_invalid(char *base, int size)
{
	int	idx;
	int	map[256];

	idx = 0;
	while (idx < 256)
	{
		map[idx] = 0;
		idx ++;
	}
	if (size <= 1)
		return (1);
	idx = 0;
	while (base[idx])
	{
		if (base[idx] == '-' || base[idx] == '+')
			return (1);
		map[(unsigned int)base[idx]] += 1;
		if (map[(unsigned int)base[idx]] > 1)
			return (1);
		idx ++;
	}
	return (0);
}

void	putnbr(long num, int size, char *base)
{
	if (num)
	{
		putnbr(num / size, size, base);
		write(1, &base[num % size], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	long	num;

	size = ft_strlen(base);
	if (is_invalid(base, size))
		return ;
	num = (long) nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num == 0)
		write(1, base, 1);
	putnbr(num, size, base);
}

int	main()
{
	ft_putnbr_base(-680565436, "0123456789ABCDEFGHIJ");
}
