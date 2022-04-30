/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:09:09 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/28 15:13:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory_as_hex(unsigned long long memory)
{
	int		idx;
	char	arr[16];
	char	*hex;

	idx = 15;
	hex = "0123456789abcdef";
	while (idx && memory)
	{
		arr[idx] = hex[memory % 16ull];
		memory /= 16ull;
		idx --;
	}
	while (idx >= 0)
	{
		arr[idx] = '0';
		idx --;
	}
	write(1, arr, 16);
	write(1, ": ", 2);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;
	char	list[2];

	hex = "0123456789abcdef";
	list[0] = hex[c / 16];
	list[1] = hex[c % 16];
	write(1, list, 2);
}

void	print_str_as_hex(unsigned char *str, unsigned int width)
{
	unsigned int	idx;

	idx = 0;
	while (idx < 16)
	{
		if (idx < width)
			ft_print_hex(str[idx]);
		else
			write(1, "  ", 2);
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx ++;
	}
}

void	print_str(unsigned char *str, unsigned int width)
{
	unsigned int	idx;

	idx = 0;
	while (idx < width)
	{
		if (str[idx] <= 31 || str[idx] >= 127)
			write(1, ".", 1);
		else
			write(1, &str[idx], 1);
		idx ++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		idx;
	unsigned int		width;
	unsigned char		*str;
	unsigned long long	memory;

	idx = 0;
	width = 16;
	str = (unsigned char *) addr;
	memory = (unsigned long long) addr;
	if (size == 0)
		return (addr);
	while (idx < size)
	{	
		if (size - idx < 16)
			width = size - idx;
		print_memory_as_hex(memory + idx);
		print_str_as_hex(str + idx, width);
		print_str(str + idx, width);
		write(1, "\n", 1);
		idx += 16;
	}
	return (addr);
}
