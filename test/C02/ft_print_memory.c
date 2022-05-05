/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:12:57 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/05 11:07:48 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory_as_hex(unsigned long long memory)
{
	int		idx;
	char	*hex;
	char	arr[17];

	idx = 15;
	hex = "0123456789abcdef";
	arr[16] = '\0';
	while (memory)
	{
		arr[idx] = hex[memory % 16ull];
		memory /= 16ull;
		idx --;
	}
	while (idx > -1)
	{
		arr[idx] = '0';
		idx --;
	}
	write(1, arr, 16);
	write(1, ": ", 2);
}

void	print_as_hex(char character)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[character / 16], 1);
	write(1, &hex[character % 16], 1);
}


void	print_string_as_hex(unsigned char *str, int width)
{
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		if (idx < width)
			print_as_hex(str[idx]);
		else
			write(1, "  ", 2);
		if (idx % 2)
			write(1, " ", 1);
		idx ++;
	}
}

void	print_string(unsigned char *str, int width)
{
	int	idx;

	idx = 0;
	while (idx < width)
	{
		if (str[idx] >= 32 && str[idx] <= 126)
			write(1, str + idx, 1);
		else
			write(1, ".", 1);
		idx ++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		idx;
	unsigned int		width;
	unsigned long long	memory;
	unsigned char		*str;
	
	idx = 0;
	width = 16;
	memory = (unsigned long long)addr;
	str = (unsigned char *)addr;
	while (idx < size)
	{
		if (size - idx < 16)
			width = size - idx;
		print_memory_as_hex(memory + idx);
		print_string_as_hex(str + idx, width);
		print_string(str + idx, width);
		write(1, "\n", 1);
		idx += 16;
	}
	return (addr);
}

int	main()
{
		char string[93] = "Bonjour les aminches***c  est fou*tout*ce qu on peut faire avec***print_memory****lol*lol*  ";
		string[20] = 9;
		string[21] = 10;
		string[22] = 9;
		string[33] = 9;
		string[38] = 9;
		string[63] = 9;
		string[64] = 10;
		string[65] = 9;
		string[78] = 10;
		string[79] = 10;
		string[80] = 10;
		string[81] = 9;
		string[85] = 46;
		string[89] = 10;
		ft_print_memory(string, sizeof(string));	return (0);
}
