/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:25:26 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/19 11:43:02 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dfs(int idx, int num, int n, char *arr)
{
	if (idx > n)
		return ;
	else if (idx == n)
	{
		write(1, arr, n);
		if (*arr < 10 - n + '0')
			write(1, ", ", 2);
		idx ++;
	}
	else
	{
		while (num <= 9)
		{
			arr[idx] = num + '0';
			dfs(idx + 1, num + 1, n, arr);
			num ++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	if (n > 0 && n < 10)
		dfs(0, 0, n, arr);
}
