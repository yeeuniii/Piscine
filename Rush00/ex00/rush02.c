/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:02:03 by jgo               #+#    #+#             */
/*   Updated: 2022/04/17 14:19:23 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(int col, char first, char mid, char last)
{
	int	idx_w;

	idx_w = 0;
	while (idx_w < col)
	{
		if (idx_w == 0)
			ft_putchar(first);
		else if (idx_w == col -1)
			ft_putchar(last);
		else
			ft_putchar(mid);
		idx_w++;
	}
}

void	rush(int x, int y)
{
	int	idx_h;

	idx_h = 0;
	while (idx_h < y)
	{
		if (idx_h == 0)
			print_row(x, '/', '*', '\\');
		else if (idx_h == y - 1)
			print_row(x, '\\', '*', '/');
		else
			print_row(x, '*', ' ', '*');
		ft_putchar('\n');
		idx_h ++;
	}
}
